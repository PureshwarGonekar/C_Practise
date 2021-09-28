#include<stdio.h>
int traid(int i)
{
    int a,b,c,z;
    for(;i<999;i++)
    {
        a=i%10; z=i/10;
        b=z%10; c=z/10;
        if(a!=b && a!=c && b!=c)
            return i;
    }
}
int check_b_c(int i)
{
  int a,b,c;
  a=i%10; i/=10;
  b=i%10; c=i/10;
  if(a!=b && a!=c && b!=c)
    return 1;
  return -1;
}
int ultrachecking(int a,int b,int c)
{
  int T[9],temp,t;
  T[0]=a%10; //firstly fill a into T[]
  a/=10;
  T[1]=a%10;
  T[2]=a/10;
  ///
  t=2;
  for(int r=1;r<=3;r++) // checking digits of b
  {
    temp=b%10;
    for(int i=0;i<=t;i++)
    {
      if(temp==T[i])
        return -1;
    }
    t++;
    T[t]=temp;
    b/=10;
  }

  //for checking digit of c
  for(int r=1;r<=3;r++)
  {
    temp=c%10;
    for(int i=0;i<=t;i++)
    {
      if(temp==T[i])
        return -1;
    }
    t++;
    T[t]=temp;
    c/=10;
  }
  return 1;
}
int main()
{
  int N,a,b,c,m,i=0;
  scanf("%d",&N);
  for(m=traid(102);N!=0&&m<999;m=traid(a))
  {
    a=m;
    b=2*a;
    c=3*a;
    if(check_b_c(b)==1 && check_b_c(c)==1)
    {
      if(1==ultrachecking(a,b,c)){
        printf("%d %d %d\n",a,b,c);
        N--;
      }
    }
    a++;
  }
}
