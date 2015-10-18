#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define SIZE 501
#define SIZEB 100

void Sort(int ar[],int n)
{
	int j,min;
	int temp;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(ar[j]<ar[min])
				min=j;
		}
		temp=ar[i];
		ar[i]=ar[min];
		ar[min]=temp;
	}
}


long rsum(int n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return rsum(n-1)+rsum(n-2);
}

void main(void)
{
	int step,op;
	int a[SIZE];
	int b[SIZEB];

	while(1)
	{
		printf("1)0~500選擇排序 2)0~90用迴圈作費氏數列 3)0~40用遞迴作費氏數列 ");
		scanf("%d",&op);
		if(op==1)
		{
			int n;
			step=10;
			double duration;
			FILE *dfPtr;			
			printf("n\treptitions\ttime \n");
			for(n=0;n<=500;n+=step)
			{
				long repetition=0;
				clock_t start=clock();
				do{
					repetition++;
					for(int i=0;i<n;i++)
						a[i]=n-i;
					Sort(a,n);
				}while(clock()-start<500);

				duration=((double)(clock()-start))/CLOCKS_PER_SEC;

				duration/=repetition;
				printf("%6d\t%9d\t%f \n",n,repetition,duration);					
			}			
		}
		if(op==2)
		{
			int m=0;
			step=5;
			double duration2;		
			printf("n\treptitions\ttime \n");
			for(m=0;m<=90;m+=step)
			{
				long repetition2=0;
				clock_t start2=clock();
				do{
					repetition2++;
					for(int i=0;i<m;i++)
					{
						if(i==0)
							b[i]=0;
						else if(i==1)
							b[i]=1;
						else if(i>=2)
						{
							b[i]=b[i-1]+b[i-2];
						}
					}
				}while(clock()-start2<90);

				duration2=((double)(clock()-start2))/CLOCKS_PER_SEC;

				duration2/=repetition2;
				printf("%6d\t%9d\t%.9f \n",m,repetition2,duration2);				
			}			
		}
		if(op==3)
		{
			int k=0;
			step=5;
			double duration3;		
			printf("n\treptitions\ttime \n");
			for(k=0;k<=40;k+=step)
			{
				long repetition3=0;
				clock_t start3=clock();
				do{
					repetition3++;
					rsum(k);
				}while(clock()-start3<40);

				duration3=((double)(clock()-start3))/CLOCKS_PER_SEC;

				duration3/=repetition3;
				printf("%6d\t%9d\t%.9f \n",k,repetition3,duration3);				
			}			
		}
	}	
} 