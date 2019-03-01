////#include <iostream>
////#include <stdio.h>
////
////using namespace std;
////
////int main()
////{
////	int i,j;
////	int a[10][10] = { 0 };
////
////	// 打印所有的1
////	for (i = 0; i < 10; i++)
////	{
////		a[i][0] = 1;
////		a[i][i] = 1;
////	}
////
////	// 之间的数
////	for (i = 2; i < 10; i++)
////	{
////		for (j = 1; j < i; j++)
////		{
////			a[i][j] = a[i][j-1] + a[i-1][j-1];
////		}
////	}
////	//printf all  num
////
////	for (i = 0; i < 10; i++)
////	{
////		for (j = 0; j < 10-i-1; j++)
////		{
////			printf("    ");
////		}
////
////		for (j = 0; j <= i; j++)
////		{
////			printf("%4d    ", a[i][j]);
////		}
////		printf("\n");
////	}
////
////	getchar();
////
////	return 0;
////
////
////
////}
//#include <stdio.h>
//int main(){
//	int a[10][10];
//	int i, j;
//	for (i = 0; i<10; i++){
//		a[i][0] = 1;
//		a[i][i] = 1;
//	}
//	for (i = 2; i<10; i++){    //直接从第三行开始，因为第二行全是1
//		for (j = 1; j<i; j++)
//			a[i][j] = a[i][j - 1] + a[i - 1][j - 1];
//	}
//	for (i = 0; i<10; i++){
//		for (j = 0; j<(10 - i - 1); ++j)
//			printf("    ");    //每行前需要空的数的位置，每个数占4个空格
//		for (j = 0; j <= i; j++)
//			printf("%4d    ", a[i][j]);
//		printf("\n");
//	}
//
//	getchar();
//	return 0;
//}

#include<iostream>
#include<iomanip>
using namespace std;
int* YangHuiData(int n); //n是杨辉三角形的行数 
void YangHuiShow(int *pData, int n);//在屏幕上打印杨辉三角形 
int main() {
	int n;
	cout << "请输入杨辉三角形的行数: ";
	cin >> n;
	//计算杨辉三角并保存到二维数组
	int *pData = YangHuiData(n);
	//在屏幕上打印等腰三角形的杨辉三角 
	YangHuiShow(pData, n);
	//n是杨辉三角形的行数 
	getchar();
}

int* YangHuiData(int n) {
	int *a = new int[n*n];
	//完成杨辉三角形的计算，没有显示的位置填0 
	int i, j;
	for (i = 0; i<n*n; i++) {
		a[i] = 0;
	}

	a[0] = 1;
	a[n] = 1;
	a[n + 1] = 1;

	for (i = 2; i<n; i++) {
		a[i*n] = 1;
		a[i*n + i] = 1;
		for (j = 1; j<i; j++) {
			a[i*n + j] = a[(i - 1)*n + j - 1] + a[(i - 1)*n + j];
		}
	}
	
	return a;
	getchar();
}
void YangHuiShow(int *a, int n) {
	//根据数据a指向的二维数组在屏幕上打印 
	//杨辉三角形，每行前面填充合适的空格 
	//以显示成等腰三角形，左右对称 
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
			cout << setw(3) << " ";//前导空格，为单个数据的一半宽度  
		for (j = 0; j <= i; j++)
			cout << setw(6) << a[i*n + j];
		cout << endl;
	}

}