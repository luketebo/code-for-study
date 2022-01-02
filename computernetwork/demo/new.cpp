#include <stdio.h>//io标准库

#include <string.h>//string标准库

#include <winsock2.h>//socket库，必须在windows.h之前，否则会出现重定义问题。参考https://blog.csdn.net/hanxiaoyang123/article/details/84001362

#include <Windows.h> //windows库

#include <process.h> //windows下的多线程库

#include "loghelperheader.h"//自定义日志头文件



#pragma comment(lib, "ws2_32")//socket的实现库，winsock2.h只是接口




#define PORT 5778 //socket监听端口

unsigned __stdcall HandRequest(void *pArg);//声明socket请求处理函数，否则需要在调用之前定义该函数。

//启动socket监听并处理请求

int SocketListenStart()//单文件模式下用 int main()替换即可

{

    //1.初始化WSA

    WORD socketVersion = MAKEWORD(2, 2);//Socket编程中,MAKEWORD(2,2)就是调用2.2版，MAKEWORD(1,1)就是调用1.1版。

    printf("socketVersion:%p\n",socketVersion);

    printf(" MAKEWORD(3, 5):%p\n", MAKEWORD(3, 5));//用于测试MAKEWORD()方法的作用.

    WSADATA wsaData;//WSADATA是一种数据结构。这个结构被用来存储被WSAStartup函数调用后返回的Windows Sockets数据。它包含Winsock.dll执行的数据。

    if (WSAStartup(socketVersion, &wsaData) != 0)//WSAStartup，即WSA(Windows Sockets Asynchronous，Windows异步套接字)的启动命令。

    {

        WSACleanup();//必须调用WSACleanup()以允许Windows Sockets DLL释放任何该应用程序的资源。

        WriteToLog(GetErrorMessage(GetLastError()));//打印最后一次错误信息，单文件模式下用printf替换

        return 0;//返回0表示启动失败

    }

    //创建套接字

    /*

    int socket(int domain, int type, int protocol);

    domain指定使用何种的地址类型，比较常用的有：

        PF_INET, AF_INET： Ipv4网络协议；

        PF_INET6, AF_INET6： Ipv6网络协议。

            AF 表示ADDRESS FAMILY 地址族，PF 表示PROTOCOL FAMILY 协议族，但这两个宏定义是一样的，所以使用哪个都没有关系。UNIX系统支持AF_INET，AF_UNIX，AF_NS等，而DOS,Windows中仅支持AF_INET，它是网际网区域。

    type参数的作用是设置通信的协议类型，可能的取值如下所示：

        SOCK_STREAM： 提供面向连接的稳定数据传输，即TCP协议。

        OOB： 在所有数据传送前必须使用connect()来建立连接状态。

        SOCK_DGRAM： 使用不连续不可靠的数据包连接。

        SOCK_SEQPACKET： 提供连续可靠的数据包连接。

        SOCK_RAW： 提供原始网络协议存取。

        SOCK_RDM： 提供可靠的数据包连接。

        SOCK_PACKET： 与网络驱动程序直接通信。

    protocol用来指定socket所使用的传输协议编号。这一参数通常不具体设置，一般设置为0即可。

    */

    SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (slisten == INVALID_SOCKET)

    {

        WSACleanup();//必须调用WSACleanup()以允许Windows Sockets DLL释放任何该应用程序的资源。

        WriteToLog(GetErrorMessage(GetLastError()));//打印最后一次错误信息

        return 0;

    }

    //绑定IP和端口

    struct sockaddr_in sin;

    /*sockaddr结构

    struct sockaddr_in 

    {

        short sin_family;//Address family一般来说AF_INET（地址族）PF_INET（协议族）

        unsigned short sin_port;//Port number(必须要采用网络数据格式,普通数字可以用htons()函数转换成网络数据格式的数字)

        struct in_addr sin_addr;//IP address in network byte order（Internet address）

        unsigned char sin_zero[8];//Same size as struct sockaddr没有实际意义,只是为了　跟SOCKADDR结构在内存中对齐

    };

    */

    sin.sin_family = AF_INET;

    sin.sin_port = htons(PORT);//htons():将主机的无符号短整形数转换成网络字节顺序。

    sin.sin_addr.S_un.S_addr = INADDR_ANY;//INADDR_ANY:0.0.0.0,表示监控通过任何IP地址访问到本机的请求

    /*

    1、LPSOCKADDR:

    typedef struct sockaddr {

        #if (_WIN32_WINNT < 0x0600)

            u_short sa_family;

        #else

            ADDRESS_FAMILY sa_family;           // Address family.

        #endif //(_WIN32_WINNT < 0x0600)

        CHAR sa_data[14];                   // Up to 14 bytes of direct address.

    } SOCKADDR, *PSOCKADDR, FAR *LPSOCKADDR;

    2、bind():

        #if INCL_WINSOCK_API_PROTOTYPES

            WINSOCK_API_LINKAGE

            int

            WSAAPI

            bind(

                _In_ SOCKET s,

                _In_reads_bytes_(namelen) const struct sockaddr FAR * name,

                _In_ int namelen

            );

        #endif //INCL_WINSOCK_API_PROTOTYPES

    */

    if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)

    {

        WriteToLog(GetErrorMessage(GetLastError()));//打印最后一次错误信息

        return 0;

    }

    //开始监听

    if (listen(slisten, 5) == SOCKET_ERROR)//最大连接数5

    {

        WriteToLog(GetErrorMessage(GetLastError()));//打印最后一次错误信息

        return 0;

    }

    //定义变量用于循环监听并接收数据

    SOCKET sClient;

    struct sockaddr_in remoteAddr;

    int nAddrlen = sizeof(remoteAddr);

    while (1 == 1)

    {

        WriteToLog("等待新的连接...\n");

        sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);

    // //A、同步接收数据

    // char revData[1024];

    // int ret = recv(sClient, revData, 1024, 0);

    // if (ret > 0)

    // {

    //  WriteToLog("读取到数据\n");

    //  revData[ret] = 0x00;

    //  WriteToLog(revData);

    // }

    // else

    // {

    //  WriteToLog(GetErrorMessage(GetLastError()));

    // }

        //B、多线程异步接收数据

        HANDLE hth1;        //子线程句柄

        unsigned Thread1ID; //子线程ID

        // printf("%p\n", &sClient);

        // printf("%p\n", sClient);//这两句语句用于理解指针,查看传到子线程之前的内存地址,从而分析为什么子线程取得内存地址不对.

        //SOCKET* arg=&sClient;用这种方式进行多线程传参多此一举,直接传指针即可

        //启动子线程

        hth1 = (HANDLE)_beginthreadex(NULL,//安全属性， 为NULL时表示默认安全性

                                      0,//线程的堆栈大小， 一般默认为0

                                      HandRequest,//子线程处理函数

                                      &sClient,//子线程参数,是一个void*类型， 传递多个参数时用结构体

                                      //(void*)arg,//用这种方式进行多线程传参多此一举,直接传指针即可

                                      0,//线程初始状态，0:立即运行；CREATE_SUSPEND：suspended（悬挂） 

                                      &Thread1ID); //用于记录线程ID的地址 

        if (hth1 == 0)

        {

            WriteToLog(GetErrorMessage(GetLastError()));//打印最后一次错误信息

        }

        DWORD ExitCode; //线程退出码

        GetExitCodeThread(hth1, &ExitCode);//获取线程退出码

        ResumeThread(hth1);//运行线程

        WriteToLog("本次连接处理完毕\n");

    }

    closesocket(sClient);

    closesocket(slisten);

    WSACleanup();//必须调用WSACleanup()以允许Windows Sockets DLL释放任何该应用程序的资源。

}

/*

    __stdcall:被这个关键字修饰的函数，其参数都是从右向左通过堆栈传递的(__fastcall 的前面部分由ecx,edx传)， 函数调用在返回前要由被调用者清理堆栈。

*/

unsigned __stdcall HandRequest(void *pArg)

{

    // printf("%p\n", &pArg);

    // printf("%p\n",pArg);

    // printf("%p\n", (SOCKET)pArg);//以上代码用于观察*pArg指针指到哪里了,为什么总是报"在一个非套接字上尝试了一个操作。"

    // printf("%p\n", &sClient);

    // printf("%p\n",sClient);//这两句是用全局变量的方案取主线程的值.

    // SOCKET sClient = (SOCKET)pArg;

    SOCKET sClient = *(SOCKET*)pArg;//这里还没完全理解,不能用简单的语言来解释。如果想不通过全局变量的方式来取socket,则只能通过这种方式来取到真正原始的socket内容.

    char revData[1024];

    if (sClient == INVALID_SOCKET)

    {

        WriteToLog(GetErrorMessage(GetLastError()));//打印最后一次错误信息

        return 0;

    }

    //  WriteToLog("\n\n接收到一个连接:%s\r\n",inet_ntoa(remoteAddr.sin_addr));

    WriteToLog("开始读取数据\n");

    //接收数据

    int ret1 = recv(sClient, revData, 1024, 0);//等待sClient传输完数据,并COPY一份到revData中

    if (ret1 > 0)

    {

        printf("%d\n",ret1);

        WriteToLog("读取到数据%d\n",ret1);//为什么printf出来是正常的数字,通过fprintf写到日志文件里则是"发送完数据-35051392"这样的数据呢?

        revData[ret1] = 0x00;//标记结束

        WriteToLog(revData);

    }

    else

    {

        WriteToLog(GetErrorMessage(GetLastError()));//打印最后一次错误信息

    }

    //发送协议数据给浏览器,否则浏览器一直处于加载状态.

    char *sendData = "HTTP/1.1 200 OK\r\nAccess-Control-Allow-Origin:*\r\nContent-Type:text/html;charset=UTF-8\r\nContent-Length:2\r\n\r\n12345";

    int ret2=send(sClient, sendData, strlen(sendData), 0);

    if (ret2 > 0)

    {

        printf("%d\n",ret2);

        WriteToLog("发送完数据%d\n",ret2);//为什么printf出来是正常的数字,通过fprintf写到日志文件里则是"发送完数据-35051392"这样的数据呢?

    }

    else

    {

        WriteToLog(GetErrorMessage(GetLastError()));//打印最后一次错误信息

    }

    return 1;

}