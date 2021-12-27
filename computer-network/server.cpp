/*
1：加载套接字库，创建套接字(WSAStartup()/socket())；

2：绑定套接字到一个IP地址和一个端口上(bind())；

3：将套接字设置为监听模式等待连接请求(listen())；

4：请求到来后，接受连接请求，返回一个新的对应于此次连接的套接字(accept())；

5：用返回的套接字和客户端进行通信(send()/recv())；

6：返回，等待另一连接请求；

7：关闭套接字，关闭加载的套接字库(closesocket()/WSACleanup())。
*/
#include<stdio.h>
#include<iostream>
#include<WinSock2.h>
// #pragma comment (lib,"ws2-32.lib")
#pragma comment (lib,"ws2_32.lib")
using namespace std;

int main() {
    // 初始化DLL
    /*
    WORD w_req = MAKEWORD(2,2)  // 版本号
    WSADATA wsadata;
    // 这个是来判断初始化的套接字库到底正不正确
    int err;
    err = WSAStartup(w_req,&wsadata)
    */
    WSADATA wsaDate;
    WSAStartup(MAKEWORD(2, 2), &wsaDate);

    //创建套接字
    SOCKET s_server = socket(AF_INET, SOCK_STREAM, 0);// 0 ? IPPROTO_TCP
    SOCKET s_accept;
    // 绑定套接字
    // 创建服务端的地址
    struct sockaddr_in sockAddr;
    // 创建接收端的地址  已经被创建过了
   //  struct sockaddr_in acceptAddr;
    // 使用0填充
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;
    /*
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // 具体ip地址
    */
    //  看不懂
    sockAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    sockAddr.sin_port = htons(1234); // 端口
    ::bind(s_server, (struct sockaddr*)&sockAddr, sizeof(SOCKADDR));

    // 进入监听状态
    listen(s_server, 20);

    //接受客户端请求
    SOCKADDR clntAddr;
    int nSize = sizeof(SOCKADDR);
    // 这里创建了接收端
    SOCKET clntSock = accept(s_server, (struct sockaddr*)&clntAddr, &nSize);

    // 向客户端发送信息

    char str[] = "Hello World";
    send(clntSock, str, 100,0);

    //关闭套接字

    closesocket(clntSock);
    closesocket(s_server);

    // 终止 DLL 使用
    WSACleanup();

    return 0;
}