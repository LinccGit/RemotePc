#include "function.h"
//����ͨ�ŵ�ͷ�ļ��Ϳ�
#include <WinSock2.h> //ͷ�ļ�
#include <windows.h>
#include <stdio.h>


#pragma comment(lib, "ws2_32.lib") //���ļ�

SOCKET s;


int InitSocket()
{
	//windows�����⣬��Ҫ��������api����������ĳ�ʼ���ͷ���ʼ������
	WORD wVersionRequested;
	WSADATA wsaData;
	wVersionRequested = MAKEWORD(2, 2);
	BOOL err = WSAStartup(wVersionRequested, &wsaData);

	//��ʼ��ʧ��
	if (err != 0)
	{
		printf("init error!");
		return 0;
	}

	//1.socket ����һ���׽���
	s = socket(
		AF_INET,//INETЭ���
		SOCK_STREAM,//��ʾʹ�õ���TCPЭ��
		0
	);
	if (s == INVALID_SOCKET)
	{
		return 0;
	}

	return 1;
}