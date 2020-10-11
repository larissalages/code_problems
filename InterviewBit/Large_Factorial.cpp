string Solution::solve(int A) {
    string res;
    int arr[10000];
    arr[0]=1;
    int carry=0;
    int num;
    int arr_size=1;
    for(int i=2;i<=A;i++)
    {
        for(int j=0;j<arr_size;j++)
        {
            num=arr[j]*i+carry;
            arr[j]=num%10;
            carry=num/10;
        }
        while(carry>0)
        {
            arr[arr_size++]=carry%10;
            carry=carry/10;
        }
    }
    for(int i = arr_size-1; i >= 0 ; i--)
        res+=to_string(arr[i]);
    return res;
}
