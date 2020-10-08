bool isPrime(int a)
{
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0)
        {
            return false;
        }
    }
    return true;
}

vector<int> Solution::primesum(int A) {
    vector<int>v;
    for(int i=2;i<=A/2;i++)
    {
        if(isPrime(i)&&isPrime(A-i))
        {
            v.push_back(i);
            v.push_back(A-i);
            return v;
        }
    }
}
