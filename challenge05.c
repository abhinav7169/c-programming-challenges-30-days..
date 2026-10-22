//ALGORITHM
//1.START
2.READ CHOICE,N,I AND FACTORIAL IN INT
3.READ X,D,R1,R2 IN DECIMAL
4. USE DO-WHILE LOOP
5.PRINT 1.LINEAR EQUATION 2.FACTORIAL3.QUADRATICEQUATION4.EXIT
6. IF WE TYPE ANY ANOTHER THE PRINT INVALID
7.PRINT CHOICE 1 LINEAR EQUATION IN AX + B IF A!=0 PRINT X = -B / A
8.ELSE PRINT NO SOLUTIONS OR MANY SOLUTIONS
9.CHOICE2 FACTORIAL START FROM FACTORIAL 1 IF N<0 PRINT NO FACTORIAL IS DETECTED
10.USE FOR CONDITION TO GET INFINITE LOOP
11.CHOICE3 ENTER QUADRATIC EQUATION PRINT A,B,C
12.IF A=0 PRINT IT IS NOT A QUADRATIC EQUATION
13.FIND DISCRIMINENTD = B^2 – 4AC
14.FIND THE TWO ROOTS R1 AND R2
R= -B -+SQRT(D) / 2A
15.IF D = 0 PRINT R1
16.CHOICE4  PTINT EXIT
17. IF ANY ANOTHER CHOICE IS TYPED BY THE USER TYPE INVALID CHOICE
18.STOP
code :
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
