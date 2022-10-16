#include<stdio.h>
void linear_search(int x,int numbers[] ,int n)
{
    for(int i=0;i<n;i++)
    {
        if(numbers[i]==x)
        {
            printf("Number is found in the array.\n");
            return ;
        }
    }
    printf("Number is not found in the array.\n");
    return;
}
int main()
{
    int numbers[] = {-5,62,987,-45,6,14,-94,2,10};
    int num;
    int n = sizeof(numbers)/sizeof(numbers[0]);
    printf("Enter number to be searched in the array : \n");
    scanf("%d",&num);
    linear_search(num,numbers,n);
    return 0;
}