
//Algorithm: GRIDWATCH
1. Start.
2. Declare the required variables and a 2D array.
3. Enter the grid size (3 to 6). If invalid, ask again.
4. Enter the risk scores for each cell (0 to 100).
5. Enter the threshold value (1 to 100).
6. Display the grid.
7. Find and display the total of each row and the highest row total.
8. Find and display the total of each column and the highest column total.
9. Find the highest risk score and its position.
10. Count the number of cells that meet the threshold.
11. Calculate the main and secondary diagonal totals and check whether they are equal.
12. Calculate and display the boundary total.
13. Find and display the local hotspots in the grid.
14. Display the final result as CRITICAL, WARNING or NORMAL.
15. Stop.
input:
#include<stdio.h>
int main()
{
int a[6][6],n,t;
int i,j,sum;
int rmax=-1,cmax=-1;
int max=-1,count=0;
int d1=0,d2=0;
int b=0,h=0;
printf("enter size of grid : ");
scanf("%d",&n);
while(n<3||n>6)
{
printf("enter size between 3 and 5");
scanf("%d",&n);
}
printf("enter the risk value : \n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("enter value : ");
scanf("%d",&a[i][j]);
while(a[i][j]<0||a[i][j]>100)
{

printf("wroung value enter again : ");
scanf("%d",&a[i][j]);
}
}
}
printf("enter warning thrishold : ");
scanf("%d",&t);
while(t<1||t>100)
{
printf("enter threshold between 1 and 100 : ");
scanf("%d",&t);
}
printf("grid value :");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%4d",a[i][j]);
}
printf("\n");
}
printf("row total :");
for(i=0;i<n;i++)
{
sum=0;
for(j=0;j<n;j++)
{
sum+=a[i][j];
}
printf("row%d=%d\n",i+1,sum);
if(sum>rmax)
{
rmax=sum;
}
}
printf("highest row : ");
for(i=0;i<n;i++)
{
sum=0;
for(j=0;j<n;j++)
{
sum+=a[i][j];
}
if(sum==rmax)
{
printf("%d",i+1);
}
}
printf("column total : ");
for(j=0;j<n;j++)
{
sum=0;
 for(i=0;i<n;i++)
{
sum+=a[i][j];
}
printf("column%d=%d\n",j+1,sum);
if(sum>cmax)
{
cmax=sum;
}
}
printf("highest column : ");
for(j=0;j<n;j++)
{
sum=0;
for(i=0;i<n;i++)
{
sum+=a[i][j];
}
if(sum==cmax)
{
printf("%d",j+1);
}
}
printf("maximum risk : ");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]>max)
{
max=a[i][j];
}
if(a[i][j]>=t)
{
count++;
}
}
}
printf("maximum value = %d\n",max);
printf("maximum value position : \n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]==max)
{
printf("row%dcolumn%d",i+1,j+1);
}
}
}
printf("threshold count=%d\n",count);
for(i=0;i<n;i++)
{
d1+=a[i][i];
d2+=a[i][n-1-i];
}
printf("main diagonal=%d\n",d1);
printf("secondary diagonal=%d\n",d2);
if(d1==d2)
{
printf("both diagonals are equal");
}
else
{
printf("both diagonals are not equal");
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(i==0||i==n-1||j==0||j==n-1)
{
b+=a[i][j];
}
}
}
printf("boundary total=%d\n",b);
printf("hotspots : ");
 for(i=1;i<n-1;i++)
{
for(j=1;j<n-1;j++)
{
if(a[i][j]>a[i-1][j]&&a[i][j]>a[i+1][j]&&a[i][j]>a[i][j-1]&&a[i][j]>a[i][j+>
{
printf("hotspot at row %d column %d\n",i+1,j+1);
h++;
}
}
}
if(h==0)
{
printf("no hotspot found\n");
}
if(h>0)
{
printf("final result :");
}
else if(count>=n)
{
printf("warning\n");
}
else
{
printf("normal\n");
}
return 0;
}
