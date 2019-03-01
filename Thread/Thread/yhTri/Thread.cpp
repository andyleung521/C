#include <iostream>
#include <winsock.h>
#include <process.h>
#include <Windows.h>
#pragma comment(lib,"ws2_32.lib")

//程序描述：

//主线程启动10个子线程并将表示子线程序号的变量地址作为参数传递给子线程。
//子线程接收参数->sleep(50)->全局变量++->sleep(0)->输出参数和全局变量。

//要求：

//1．子线程输出的线程序号不能重复。

//2．全局变量的输出必须递增。

//下面画了个简单的示意图：

using namespace std;

long g_iCount;
unsigned int _stdcall Fun(void *pPM);
const int THREAD_NUM = 10;

int main(int argc, char* argv[])
{
	//初始化WSA  
	g_iCount = 0;
	HANDLE handle[THREAD_NUM];
	int i = 0;

	while (i < THREAD_NUM)
	{
		handle[i] = (HANDLE) _beginthreadex(NULL,0,Fun,&i,0,NULL);
		i++;
	}

	WaitForMultipleObjects(THREAD_NUM,handle,true,INFINITE);
	getchar();
	return 0;
}

unsigned int _stdcall Fun(void *pPM)
{
	int nThreadNum = *(int *)pPM;

	Sleep(100);
	g_iCount++;

	printf("Thread num is %d,global count is %d\n",nThreadNum,g_iCount);
	return 0;


}