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
////	// ��ӡ���е�1
////	for (i = 0; i < 10; i++)
////	{
////		a[i][0] = 1;
////		a[i][i] = 1;
////	}
////
////	// ֮�����
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
//	for (i = 2; i<10; i++){    //ֱ�Ӵӵ����п�ʼ����Ϊ�ڶ���ȫ��1
//		for (j = 1; j<i; j++)
//			a[i][j] = a[i][j - 1] + a[i - 1][j - 1];
//	}
//	for (i = 0; i<10; i++){
//		for (j = 0; j<(10 - i - 1); ++j)
//			printf("    ");    //ÿ��ǰ��Ҫ�յ�����λ�ã�ÿ����ռ4���ո�
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
int* YangHuiData(int n); //n����������ε����� 
void YangHuiShow(int *pData, int n);//����Ļ�ϴ�ӡ��������� 
int main() {
	int n;
	cout << "��������������ε�����: ";
	cin >> n;
	//����������ǲ����浽��ά����
	int *pData = YangHuiData(n);
	//����Ļ�ϴ�ӡ���������ε�������� 
	YangHuiShow(pData, n);
	//n����������ε����� 
	getchar();
}

int* YangHuiData(int n) {
	int *a = new int[n*n];
	//�����������εļ��㣬û����ʾ��λ����0 
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
	//��������aָ��Ķ�ά��������Ļ�ϴ�ӡ 
	//��������Σ�ÿ��ǰ�������ʵĿո� 
	//����ʾ�ɵ��������Σ����ҶԳ� 
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - i - 1; j++)
			cout << setw(3) << " ";//ǰ���ո�Ϊ�������ݵ�һ����  
		for (j = 0; j <= i; j++)
			cout << setw(6) << a[i*n + j];
		cout << endl;
	}

}