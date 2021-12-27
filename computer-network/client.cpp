/*
* 1：加载套接字库，创建套接字(WSAStartup()/socket())；

2：向服务器发出连接请求(connect())；

3：和服务器端进行通信(send()/recv())；

4：关闭套接字，关闭加载的套接字库(closesocket()/WSACleanup())。
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <WinSock2.h>
// #pragma comment (lib,"ws2-32.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable : 4996)
using namespace std;

int main()
{
    /*
        WORD w_req = MAKEWORD(2,2);  // 版本号
    */
    // 初始化DLL  初始化套接字库
    WSADATA wsaDate;

    WSAStartup(MAKEWORD(2, 2), &wsaDate);
    /*
    if (err != 0) {
        cout << "初始化套接字库失败！" << endl;
    }
    else {
        cout << "初始化套接字库成功！" << endl;
    }
    //检测版本号
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {
        cout << "套接字库版本号不符！" << endl;
        WSACleanup();
    }
    else {
        cout << "套接字库版本正确！" << endl;
    }
    */
    /*
    这里没有判断判断初始化套接字库是否成功
    以及检测套接字库的版本号
    */

    //创建套接字
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    /*
    创建服务器端地址客户的地址
    */
    struct sockaddr_in sockAddr;
    // 先全部使用0来进行填充
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;
    /*
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    */
    sockAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    sockAddr.sin_port = htons(1234);
    // 向服务器发送请求
    connect(sock, (SOCKADDR *)&sockAddr, sizeof(SOCKADDR));

    //接受服务器传回来的数据

    char szBuffer[200] = {0};
    recv(sock, szBuffer, 200, NULL);

    //输出接收到的数据
    printf("meeage for server : %s\n", szBuffer);

    //关闭套接字
    closesocket(sock);

    //终止使用DLL
    WSACleanup();

    return 0;
}