
#include<stdio.h>
#include<math.h>
int main()
{
	int n,i;
	double temp;
	double k;
	printf("please input a number:");
	scanf("%d", &n);

	//method 1:
	//��һ����n, ������ֽܷ��n = pq, ��ôpq���Ȼ��һ�����ڵ��ڸ���nһ��С�ڵ��ڸ���n, 
	//Ҳ����˵һ������n��Ȼ��һ��������С�ڵ��ڸ���n��.���Զ�һ����n, 
	//ֻҪ��������û��С�ڵ��ڸ���n�����ӾͿ����ˣ�����С�ڵ���n������ʹѭ���������٣���Ҳ�Ǽ򻯵�ԭ��
	/*temp = n;
	k = sqrt(temp);
	for (i = 2; i <= k; i++)
	{
		if (n%i == 0)
		{
			break;
		}
	 }*/

	//method2:
	for (i = 2; i < n; i++)
	{
		if (n%i == 0)
		{
			break;
		}
	}


	if (n <= 1)
	{
		printf("%d is not a prime\n",n);
	}
	else if (i <= k)
	{
		printf("%d is not a prime.\n",n);
	}
	else
	{
		printf("%d is a prime\n",n);
	}

	
	return 0;
	getchar();

}
