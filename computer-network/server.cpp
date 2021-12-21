#include<stdio.h>
#include<WinSock2.h>
#pragma comment (lib,"ws2-32.lib")

int main(){
    // 初始化DLL
    WSADATA wsaDate;
    WSAStartup(MAKEWORD(2,2), &wsaDate);
    
    //创建套接字
    SOCKET socket = socket(AF_INET, SOCK_STREAM, 0);// 0 ? IPPROTO_TCP

    // 绑定套接字
    struct sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    sockAddr.sin_family = AF_INET;
    sockAddr.sin_addr.s_addr = inet_addr(AF_INET); // 具体ip地址
    sockAddr.sin_port = htons(1234) // 端口
    bind(servSock,(struct sockaddr *)&sockAddr,sizeof(SOCKADDR));

    // 进入监听状态
    listen(servSock,20);

    //接受客户端请求
    SOCKADDR clntAddr;
    int nSize = sizeof(SOCKADDR);
    SOCKET clntSock = accept(servSock,(struct sockaddr *)&clntAddr,nSize);

    // 向客户端发送信息

    char *str = "Hello World";
    send(clntSock,strlen(str)+sizeof(char), NULL);

    //关闭套接字

    closesocket(clntSock);
    closesocket(servSock);

    // 终止 DLL 使用
    WSACleanup();

    return 0;
}