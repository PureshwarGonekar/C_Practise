/* //Algorithm -> 1 coulumn Right and 1 row up (if already occupied then move 1 column left)
1) 1 is stored at position (N/2,N-1) as (i,j)
2) Regular Updates(Next Position) (i,j)-> (i-1,j+1)
3) if i==-1 -> i=n-1;   if j==N -> j=0;
4) If Position is occupied then i=i+1; and j=j-2;
5) Special case if(i==-1 && j==N) -> i=0; j=N-2;
*/
#include<stdio.h>
#include<conio.h>
int main()
{
  int N,r,i,j;
  scanf("%d",&N);
  int a[N][N];
  for(i=0;i<N;i++)
  {
    for(j=0;j<N;j++)
        a[i][j]=0;
  }
  for(r=1,i=N/2,j=N-1; r<=N*N ; )
  {
    if(a[i][j]==0){
        a[i][j]=r;
        r++;
    }
    else{ // if an element is already occupied in a[i][j]
        i=i+1;
        j=j-2;
        continue;
    }
    i--;
    j++;
    if(i==-1 && j==N){ //special case when both i and j are at
        i=0;
        j=N-2;
    }
    else{
        if(j==N)
          j=0;
        if(i==-1)
          i=N-1;
    }
  }
  for(i=0;i<N;i++)
  {
      for(j=0;j<N;j++)
        printf("%d  ",a[i][j]);
      printf("\n");
  }
  return 0;
}
