#include<stdio.h>
int main(){
float expense;
float smalltotal=0,mediumtotal=0,largetotal=0;
float total=0,average;
int smallcount=0,mediumcount=0,largecount=0;
int validcount=0;
while(1)
{
printf("enter expense(0 to stop) : ");
scanf("%f",&expense);
if(expense==0)
{
  break;
}
else if(expense<0)
{
printf("invalid expense /n");
continue;
}
else
{
validcount++;
total = total + expense;
if(expense < 100)
{
smallcount++;
smalltotal = smalltotal + expense;
printf("category:small\n");
}
else if(expense<500){
mediumcount++;
mediumtotal = mediumtotal + expense;
printf("category:medium\n");
}
else{
largecount++;
largetotal = largetotal + expense;
printf(" category:large\n");
}}}
printf("number of validexpenses : %d\n",validcount);
printf("total of validexpenses : %.2f\n",total);
printf("number of smallcounut : %d\n",smallcount);
printf("total of smallexpenses : %.2f\n",smalltotal);
printf("number of mediumcount : %d\n",mediumcount);
printf("total of mediumexpense : %.2f\n",mediumtotal);
printf("number of largeexpense : %d\n",largecount);
printf("total of largeexpense : %.2f\n",largetotal);
if(validcount>0)
{
average = total / validcount;
printf("average of valid expense = Rs %.2f",average);
}
else {
printf("invalid expense entered/n");
}
return 0;
}
