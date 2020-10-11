int Solution::isPower(int A) 
{
    if(A==1) return 1;
    for(int i=2;i<=sqrt(A);i++)
    {
      float a=log(A)/log(i);
      if(floor(a)==a)
        return 1;
    }
    return 0;
}
