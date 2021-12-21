#include<stdio.h>
#include<stdlib.h>
#include<WinSock2.h>
#pragma comment (lib,"ws2-32.lib")

int main(){
    // 初始化DLL
    WSADATA wsaDate;
    WSAStartup(MAKEWORD(2,2), &wsaDate);
    
    //创建套接字
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);

    // 向服务器发送请求
    struct sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("AF_INET");
    sockAddr.sin_port = htons(1234);
    connect(sock, (SOCKADDR*)&sockAddr,sizeof(SOCKADDR));

    //接受服务器传回来的数据

    char szBuffer[200] = {0};
    recv(sock,szBuffer,200,NULL);

    //输出接收到的数据
    printf("meeage for server : %s\n",szBuffer);

    //关闭套接字
    closesocket(sock);

    //终止使用DLL
    WSACleanup();

    system("psuser");
    return 0;


}