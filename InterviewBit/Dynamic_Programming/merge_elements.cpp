static int memoizationTable[1001][1001];

int mcm(const vector<int> &A, const int startElement, const int endElement);

int Solution::solve(vector<int> &A) {
    memset(memoizationTable, -1, sizeof(memoizationTable));
    return (mcm(A,0,(int)A.size()-1));
}

int mcm(const vector<int> &A, const int startElement, const int endElement)
{
    if(startElement > endElement) return 0;
    if(startElement ==endElement) return (memoizationTable[startElement][endElement]=0);
    else if(memoizationTable[startElement][endElement]!= -1) return memoizationTable[startElement][endElement];

    int sum = INT_MAX;
    int total = 0;
    for(int i=startElement; i<=endElement; i++) total+=A[i];

    for(int i=startElement; i<endElement; i++) sum = min(sum, total + (mcm(A, startElement, i) + mcm(A, i+1, endElement)));
    
    return (memoizationTable[startElement][endElement]=sum);
}