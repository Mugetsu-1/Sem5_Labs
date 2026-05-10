#include<stdio.h>
#include<conio.h>
int main()
{
int i,j,k;
float m[3][3],x[1][3],c[3][3];
printf("The standard matrix is:");
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	{
		scanf("%f",&m[i][j]);
	}
}
for(i=0;i<3;i++)
{
	for(j=0;j<3;j++)
	{
		printf("\t%f",m[i][j]);
	}
printf("\n");
}
printf("\nEnter the matrix of current weather");
for(i=0;i<1;i++)
{
	for(j=0;j<3;j++)
	{
		scanf("%f",&x[i][j]);
	}
}
for(i=0;i<1;i++)
{
	for(j=0;j<3;j++)
	{
		printf("\t%f",x[i][j]);
	}
}	
printf("\nThe probability of weather is:");

for(i=0; i<1; i++)
	{
		for(j=0; j<3; j++)
		{
			c[i][j]=0;
			for(k=0; k<3; k++)
			c[i][j]+=x[i][k]*m[k][j];
			
		}
	}
for(i=0;i<1;i++)
{
	for(j=0;j<3;j++)
	{
		printf("\t%f",c[i][j]);
	}
}	
}
