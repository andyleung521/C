#include <iostream>

using namespace std;


int prim[50000];//用来存所有素数 
int primNum=0;//用来记录 prim数组中已经存入的素数的数量 
int times=0; //用于记录求解问题的总共判断次数 
int primLessN(int n);
int primLessN_2(int n);
bool isPrimMothed(int n); //判断一个数是否为素数 

/*
  方法一：由前往后用素数判断的枚举法：
  求“小于N的最大素数”中的条件是“n不能被[2,n)中任意一个素数整除”，而不是整数
   
  当n=10 0000时，
  ans=99991
  times=4626 4478次 
  primNum=9592 
  
  我每一个素数被判断出来，都要遍历一下之前的素数表
  而判断10 0000的时候，外层循环走了50000，里层每一个素数就是一次之前素数表的遍历
  50000*（1+2+3+...+9592)=50000* 4600 8082
  前面那个数没有50000，还要减去那些非素数 
  从 50000* 4600 8082可以看出，主要是之前那些素数花的时间，非素数几乎没花时间
  非素数= 4626 4478-4600 8082= 25 6450 
  只有25万，虽然还是要比下面多很多，因为是从前往后比较的 
*/
int primLessN(int n)
{
  prim[0]=2; //2是最小的素数
  primNum++; 
  for(int i=3;i<n;i+=2)
  {
    bool isPrim=1; //isPrim用来判断一个数是否为素数
    for(int j=0;j<primNum;j++)
	{
      times++;
      if(i%prim[j]==0)
	  {
        isPrim=0;
        break; //没加break之前， 当n=10 0000时，times=2 5239 6936次 （2.5亿） ，加了之后times=4626 4478次 （4.5千万次） 
      }
      
    } 
    if(isPrim) 
	{
		prim[primNum++]=i;
	}//如果是素数，则存入prim素数数组 
  } 
  return prim[primNum-1];
} 

/*
  方法二： 由后往前的整数枚举法
  而且方法二的空间消耗也少 
   
  当n=10 0000时，
  ans=99991
  times=346次 

  当n=100 0000时，用方法一的话，根本算不出来 
  ans=99 9983
  times=1811次 
  
  当n=1 0000 0000(一亿)时， 
  ans=9999 9989
  times=11314次 
  
  当n=10 0000 0000(十亿)时， 
  ans=9 9999 9937
  times=52537次 
*/
bool isPrimMothed(int n)
{
  bool isPrim=1;
   //isPrim用来判断一个数是否为素数
  if(n==2||n==3)
  {
	  return 1;
  }
  for(int i=2;i*i<=n;i++)
  {
    times++;

    if(n%i==0) 
	{
		return 0;
	}
  } 
  return 1;
} 

int primLessN_2(int n)
{
  for(int i=n;i>=2;i--)
  {
    if(isPrimMothed(i)) 
	   { 
		    return i;
	   }
  } 
}
int main(){
  int n;
  scanf("%d",&n);

  //int ans=primLessN(n);

  int ans=primLessN_2(n);
  
  cout<<ans<<endl; 
  printf("总判断次数times:%d\n", times);
  printf("总素数数primNum:%d\n", primNum);
  getchar();
  return 0;

  getchar();

}
