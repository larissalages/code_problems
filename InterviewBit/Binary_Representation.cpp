string Solution::findDigitsInBinary(int A) {
    if(A==0)
    {
        return "0";
    }
    string num;
    while(A>0)
    {
        string i=to_string(A%2);
        num+=i;
        A=A/2;
    }
    reverse(num.begin(),num.end());
    return num;
}
