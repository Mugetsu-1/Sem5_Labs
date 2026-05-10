#include<stdio.h>
#include<conio.h>
void main()
{
float lamda,u,ta,ts,ls,ws,rho,lq,wq,a,total;
clrscr();
printf("\ngiven the following information=");
printf("\nArrival rate of customer=1 per min");
lamda=1;
printf("\nIt takes average 20 sec to purchase the ticket");
ts=20;
printf("\nfan arrives before 2 min");
printf("\n takes 1.5 min to reach correct seat");

u=60/ts;
printf("u=%f",u);

lq=(lamda-(u-lamda))-(lamda/u);
printf("lq=%f",lq);

wq=(lq/lamda)*60;
printf("waiting time in the queue=%f",wq);

printf("\nTime to reach stadium after purchasing ticket");
scanf("%f",&a);

total=(wq+ts+a);

if(total==120)
printf("\nSports fan be seated in stadium before kick off");
else
printf("\nSports fan cant be seated in stadium before kick off");
getch();
}