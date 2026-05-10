//Kolmogorov Smirov test

#include<stdio.h>
#include<conio.h>
int main()
{
	float N,R[20],Dplus[20],Dminus[20],ibn[20],Dplusmax,Dminusmax,D,Dalpha;
	int i;
	Dalpha=0.565;
	printf("\nEnter the total numbers");
	scanf("%f",&N);
	printf("\nEnter the array for Ri");
	for(i=1;i<=N;i++)
	{
	
	printf("\nR[%f]=",i);
	scanf("%f",&R[i]);
}
	printf("\nFinding the value of i by n:");
	for(i=1;i<=N;i++)
	{
	
	ibn[i]=i/N;
	printf("\n%f",ibn[i]);
}
	for(i=1;i<=5;i++)
	{
		Dplus[i]=(ibn[i]-R[i]);
		
		
	}
	for(i=1;i<=5;i++)
	{
		Dminus[i]=(N*R[i]-i+1)/N;
		printf("\nDminus[%d]=%f",i,Dminus[i]);
		
	}
	
	
	Dplusmax=Dplus[0];
		for(i=1;i<=5;i++)
		{
			if(Dplus[i]>Dplusmax)
			Dplusmax=Dplus[i];
		}
	printf("\nDplusmax=%f",Dplusmax);
	
	Dminusmax=Dminus[0];
		for(i=1;i<=N;i++)
		{
			if(Dminus[i]>Dminusmax)
			Dminusmax=Dminus[i];
		}
		
	printf("\nDminusmax=%f",Dminusmax);	
	
	if(Dplusmax>Dminusmax)
	D=Dplusmax;
	else
	D=Dminusmax;
	
	printf("\nD=%f",D);
	
	if(D<Dalpha)
	printf("\nHypothesis is Accepted");
	else
	printf("\nHypothesis is rejected");
	getch();
	return 0;


}

