#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
float lamda,x,sig,i,a;
printf("\nEnter the value of lamda=");
scanf("%f",&lamda);
printf("\nEnter the value of x=");
scanf("%f",&x);
a=1;
for(i=1;i<=x;i++)
{
a=a*i;
}
sig=(pow(2.71,-lamda));
sig=sig*pow(lamda,x);
sig=sig/a;
sig=1-sig;
printf("\nFinal answer is=%f",sig);
return 0;
getch();
}








