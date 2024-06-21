#include <stdio.h>

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void Bubble(int A[],int n)
{
	int i,j,flag=0;
	for(i=0;i<n-1;i++)
	{
		flag=0;
		for(j=0;j<n-i-1;j++)
		{
			if(A[j]>A[j+1])
			{
				swap(&A[j+1],&A[j]);
				flag=1;
			}
		}
			if(flag==0)
			{
				break ;
			}
	}
}

int main()
{
    int A[]={12,3,2,34,86,98,23};
    int n=7;
    for(int i=0;i<n;i++)
    {
    	printf("%d\t",A[i]);
	}
	printf("\nAfter swapping\n");
    Bubble(A,n);
    for(int i=0;i<n;i++)
    {
    	printf("%d\t",A[i]);
	}
    return 0;
}
