#include <iostream>
#include <stdlib.h>
#include <process.h>
//#include <cwindow.h>
#include <Windows.h>

 

const int THREADNUM = 3;
const int MAINLOOP = 10;
HANDLE hEventThread[THREADNUM];
HANDLE hThreadHandle[THREADNUM];

UINT WINAPI  ThreadProc(LPVOID lpPram)
{
 int num = (int)lpPram;
    char cthread  = num + 'A';
 for(int i = 0; i < MAINLOOP ; i++)
 {
  WaitForSingleObject(hEventThread[num],INFINITE);
  printf("son thread ID=%d ,output is %c\n",GetCurrentThreadId(),cthread);
  SetEvent(hEventThread[(num+1)%THREADNUM]);
 }
 return 0;
}

int main(int argc, char* argv[])
{
 printf("Printf ABC 30 times\n");
 int i = 0;
 for(i =0; i<THREADNUM;i++)
  hEventThread[i] = CreateEvent(FALSE,FALSE,FALSE,NULL);
 
 for (i = 0; i< THREADNUM ; i++)
 {
  hThreadHandle[i] = (HANDLE)_beginthreadex(NULL,0,ThreadProc,(void*)i,0,NULL);
 }

 SetEvent(hEventThread[0]);

 WaitForMultipleObjects(3,hThreadHandle,TRUE,INFINITE);
 for (i = 0; i < THREADNUM;i++)
 {
  CloseHandle(hThreadHandle[i]);
  CloseHandle(hEventThread[i]);
 }

 getchar();
 return 0;


}

 