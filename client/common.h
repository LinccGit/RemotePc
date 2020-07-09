#pragma once
#pragma once

//定义一些公共的结构体，同于标记数据的不同类型

//定义宏，来表示包的具体处理类型
//cmd 类型数据
#define PACKET_REQ_CMD 10001 //REQ 表示request请求 CMD 表示cmd类型的数据 客户端--->服务端
#define PACKET_RLY_CMD 10002 //RLY 表示reply应答 CMD 表示cmd类型的数据   服务端--->客户端
//键盘类型数据
#define PACKET_REQ_KEYBOARD 20001 //REQ 表示request请求 KEYBOARD 表示键盘按键类型的数据 客户端--->服务端
#define PACKET_RLY_KEYBOARD 20002 //RLY 表示reply应答 KEYBOARD 表示键盘按键类型的数据   服务端--->客户端

//对齐，要按1字节对齐
#pragma pack(push)//表示原有的结构体对齐值大小压栈
#pragma pack(1)
struct MyPacket
{
	unsigned int type;//表示包类型
	unsigned int length;//表示长度
	char data[1];//定义一个1字节的数组，柔性数组

};
#pragma pack(pop)//表示原有的结构体对齐值大小出栈