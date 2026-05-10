#include<stdio.h>
#include<conio.h>
int main()
{
	int i,n,x[100],m,c,a;
	float r[100];
	printf("\nEnter the value of multiplier:");
	scanf("%d",&a);
	printf("\nEnter the value of increment:");
	scanf("%d",&c);
	printf("\nEnter the value of m:");
	scanf("%d",&m);
	x[0]=27;
	for(i=0;i<100;i++)
	{
		x[i+1]=(a*x[i]+c)%m;
		printf("\nx[%d]=%d",i,x[i]);
	
		r[i]=float(x[i])/float(m);
	 	printf("\t%f",r[i]);
	}
	 
}
