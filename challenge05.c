#include<stdio.h>
#include<math.h>
int main(){
int choice,n,i;
float a,b,c;
float x,d,r1,r2;
int factorial;
do{

printf("1.linear equation\n");
printf("2.factorial\n");
printf("3.quadratic equation\n");
printf("4.exit\n");
printf("enter your choice : ");
scanf("%d",&choice);
if(choice == 1)
{
printf("enter a and b for ax + b = 0 : ");
scanf("%f%f",&a,&b);
if(a!=0)
{
x = -b / a;
printf("x = %f",x);
}
else
{
printf("many solutions");
}

}
else if(choice == 2)
{
printf("enter n:");
scanf("%d",&n);
factorial = 1;
if(n<0){
printf("any factorial is not detected");
}
else{
for(i=1;i<=n;i++)
 {
factorial = factorial * i;

}
printf("fatorial = %d",factorial);
}
}
else if(choice == 3)
{
printf("enter a,b,c for ax^2+bx+c : ");
scanf("%f%f%f",&a,&b,&c);
if(a==0){
printf("not a quadratic equation");
}
else
{
d = (b^2 - (4*a*c));
if(d > 0)
{
r1 = (-b + sqrt(d) / (2*a));
r2 = (-b - sqrt(d) / (2*a));
printf("root1 = %f/n",r1);
printf("root2 = %f/n",r2);
}
else if(d==0)
{
r1 = -(b / (2*a);
printf("root = %f",r1);
else
{
printf("no real roots");
}
}

else if(choice == 4 )
{
printf("exit");
}
else
{
printf("wrong choice");
}
}
while(choice!=4);
return 0;
}
