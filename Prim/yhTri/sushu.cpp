
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
	//对一个数n, 如果他能分解成n = pq, 那么pq里必然有一个大于等于根号n一个小于等于根号n, 
	//也就是说一个合数n必然有一个因子是小于等于根号n的.所以对一个数n, 
	//只要检验他有没有小于等于根号n的因子就可以了（检验小于等于n的因子使循环次数变少，这也是简化的原因
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
