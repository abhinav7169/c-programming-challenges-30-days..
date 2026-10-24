#include <stdio.h>
int main(){
int a[12], n, i, j;
int s = 0, mn, mx;
float av;
printf("enter n 5-12: ");
scanf("%d", &n);
while(n<5 || n>12){
printf("wrong n enter again: ");
scanf("%d",&n);
}
for(i=0;i<n;i++){
printf("enter a[%d]: ",i);
scanf("%d",&a[i]);
while(a[i]<0 || a[i]>1000){
printf("invalid 0-1000 enter again: ");
scanf("%d",&a[i]);
}}
//task1
printf("\narray is: ");
for(i=0;i<n;i++) printf("%d ",a[i]);
//task2
mn = a[0]; mx = a[0];
for(i=0;i<n;i++){
s = s + a[i];
if(a[i]<mn) mn = a[i];
if(a[i]>mx) mx = a[i];
}
av = s/(float)n;
printf("\nsum=%d avg=%.2f min=%d max=%d",s,av,mn,mx);
//task3
int sec = -1, f=0;
for(i=0;i<n;i++){
if(a[i]!=mx){
if(f==0 || a[i]>sec){
sec = a[i];
f=1;
}}}
if(f==0) printf("\nsecond largest not exist");
 else printf("\nsecond largest=%d",sec);
//task4
printf("\npeaks: ");
int pk=0;
for(i=1;i<n-1;i++){
if(a[i]>a[i-1] && a[i]>a[i+1]){
printf("%d at %d ",a[i],i);
pk=1;
}}
if(pk==0) printf("none");
//task5
int cur=1, longg=1;
for(i=1;i<n;i++){
if(a[i]>a[i-1]) cur++;
else{
if(cur>longg) longg=cur;
cur=1;
}}
if(cur>longg) longg=cur;
printf("\nlongest inc run=%d",longg);
//task6
int k;
printf("\nenter k: ");
scanf("%d",&k);
int kk = k % n;
if(kk<0) kk = kk + n;
for(i=0;i<kk;i++){
int last = a[n-1];
for(j=n-1;j>0;j--) a[j]=a[j-1];
a[0]=last;
}
printf("rotated array: ");
for(i=0;i<n;i++) printf("%d ",a[i]);
//task7
int r,d,cnt=0;
printf("\nenter R: ");
scanf("%d",&r);
d = (r%9)+1;
for(i=0;i<n;i++) if(a[i]%d==0) cnt++; printf("D=%d count=%d",d,cnt);
return 0;
}
output:
enter n 5-12: 6
enter a[0]: 12
enter a[1]: 45
enter a[2]: 33
enter a[3]: 67
enter a[4]: 22
enter a[5]: 90

array is: 12 45 33 67 22 90
sum=269 avg=44.83 min=12 max=90
second largest=67
peaks: 45 at 1 67 at 3
longest inc run=2
enter k: 2
rotated array: 22 90 12 45 33 67
enter R: 64
D=2 count=3
enter n 5-12: 5
enter a[0]: 4
enter a[1]: 9
enter a[2]: 6
enter a[3]: 9
enter a[4]: 2

array is: 4 9 6 9 2
sum=30 avg=6.00 min=2 max=9
second largest=6
peaks: 9 at 1 9 at 3
longest inc run=2
enter k: 2
rotated array: 9 2 4 9 6
enter R: 64
D=2 count=3
 enter n 5-12: 5
enter a[0]: 5
enter a[1]: 5
enter a[2]: 5
enter a[3]:
5
enter a[4]: 5

array is: 5 5 5 5 5
sum=25 avg=5.00 min=5 max=5
second largest not exist
peaks: none
longest inc run=1
enter k: 2
rotated array: 5 5 5 5 5
enter R: 64
D=2 count=0
enter n 5-12: 5
enter a[0]: 9
enter a[1]: 8
enter a[2]: 7
enter a[3]: 6
enter a[4]: 5

array is: 9 8 7 6 5
sum=35 avg=7.00 min=5 max=9
second largest=8
peaks: none
longest inc run=1
enter k: 2
rotated array: 6 5 9 8 7
enter R: 64
D=2 count=2
enter n 5-12: 5
enter a[0]: 2
enter a[1]: 7
enter a[2]: 3
enter a[3]: 8
enter a[4]: 4

array is: 2 7 3 8 4
sum=24 avg=4.80 min=2 max=8
second largest=7
peaks: 7 at 1 8 at 3
longest inc run=2
enter k: 2
rotated array: 8 4 2 7 3
enter R: 64
D=2 count=3
 enter n 5-12: 5
enter a[0]: 1
enter a[1]: 2
enter a[2]: 3
enter a[3]: 4
enter a[4]: 5

array is: 1 2 3 4 5
sum=15 avg=3.00 min=1 max=5
second largest=4
peaks: none
longest inc run=5
enter k: 0
rotated array: 1 2 3 4 5
enter R: 64
D=2 count=2
 enter n 5-12: 5
enter a[0]: 1
enter a[1]: 2
enter a[2]: 3
enter a[3]: 4
enter a[4]: 5

array is: 1 2 3 4 5
sum=15 avg=3.00 min=1 max=5
second largest=4
peaks: none
longest inc run=5
enter k: 2
rotated array: 4 5 1 2 3
enter R: 64
D=2 count=2
 enter n 5-12: 5
enter a[0]: 1
enter a[1]: 2
enter a[2]: 3
enter a[3]: 4
enter a[4]: 5

array is: 1 2 3 4 5
sum=15 avg=3.00 min=1 max=5
second largest=4
peaks: none
longest inc run=5
enter k: -1
rotated array: 2 3 4 5 1
enter R: 64
D=2 count=2
enter n 5-12: 5
enter a[0]: 22
enter a[1]: 90
enter a[2]: 12
enter a[3]: 45
enter a[4]: 33

array is: 22 90 12 45 33
sum=202 avg=40.40 min=12 max=90
second largest=45
peaks: 90 at 1 45 at 3
longest inc run=2
enter k: 67
rotated array: 45 33 22 90 12
enter R: 64
D=2 count=3
enter n 5-12: 5
enter a[0]: 22
enter a[1]: 90
enter a[2]: 12
enter a[3]: 45
enter a[4]: 33

array is: 22 90 12 45 33
sum=202 avg=40.40 min=12 max=90
second largest=45
peaks: 90 at 1 45 at 3
longest inc run=2
enter k: 2
rotated array: 45 33 22 90 12
enter R: 64
D=2 count=3
enter n 5-12: 3
wrong n enter again: 13
wrong n enter again: 1000
wrong n enter again: 4
wrong n enter again: 5
enter a[0]: 3
enter a[1]: 3
enter a[2]: 3
enter a[3]: 3
enter a[4]: 3

array is: 3 3 3 3 3
sum=15 avg=3.00 min=3 max=3
second largest not exist
peaks: none
longest inc run=1
enter k: 2
rotated array: 3 3 3 3 3
enter R: 64
D=2 count=0
