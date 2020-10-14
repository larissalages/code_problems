int Solution::isPrime(int A) {
    if(A==1||A==0)
    {
        return 0;
    }
    for(int i=2;i<=sqrt(A);i++)
    {
        if(A%i==0)
        {
            return 0;
        }
    }
    return 1;
}
