#include "function.h"
//包含通信的头文件和库
#include <WinSock2.h> //头文件
#include <windows.h>
#include <stdio.h>


#pragma comment(lib, "ws2_32.lib") //库文件

SOCKET s;


int InitSocket()
{
	//windows很特殊，需要单独调用api来进行网络的初始化和反初始化操作
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2, 2);
	BOOL err = WSAStartup(wVersionRequested, &wsaData);

	//初始化失败
	if (err != 0)
	{
		printf("init error!");
		return 0;
	}

	//1.socket 创建一个套接字
	s = socket(
		AF_INET,//INET协议簇
		SOCK_STREAM,//表示使用的是TCP协议
		0
	);
	if (s == INVALID_SOCKET)
	{
		return 0;
	}

	return 1;
}