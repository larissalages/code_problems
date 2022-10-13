#include<stdio.h>
void binary_search(int x,int numbers[],int low, int high)
{

    while(low<=high){
    int mid = (low+high)/2;
    if(numbers[mid]==x)
    {
        printf("Number found in the array. \n");
        return;
    }
    else if(numbers[mid]>x)
    {
        high = mid-1;
    }
    else
    {
        low=mid+1;
    }
    }
    printf("Number not found in the array. \n");
    return;
}
int main()
{
    int numbers[] = {-10,-6,-3,0,15,34,50,57,100};
    int num;
    int n = sizeof(numbers)/sizeof(numbers[0]);
    int low=0,high=n-1;
    printf("Enter number to be searched in the array : \n");
    scanf("%d",&num);
    binary_search(num,numbers,low,high);
    return 0;
}