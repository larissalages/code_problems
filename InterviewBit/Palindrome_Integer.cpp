int Solution::isPalindrome(int A) {
    int val=A;
    int num=0;
    while(A>0)
    {
        num=num*10+A%10;
        A=A/10;
    }
    if(val==num)
    {
        return 1;
    }
    return 0;
}
