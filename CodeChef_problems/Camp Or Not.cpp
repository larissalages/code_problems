#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        int D, i, sum, j;
        cin>>D;
        int d[D],p[D];
        for(i=0;i<D;i++)
        {
            cin>>d[i]>>p[i];
        }
        int Q;
        cin>>Q;
        int d1[Q],p1[Q];
        for(i=0;i<Q;i++)
        {
            cin>>d1[i]>>p1[i];
        }
        for(i=0;i<Q;i++)
        {
            sum=0;
            for(j=0;j<D;j++)
            {
                if(d1[i]>=d[j])
                    sum+=p[j];
                else
                    break;
            }
            if(sum>=p1[i])
                cout<<"Go Camp"<<endl;
            else
                cout<<"Go Sleep"<<endl;
        }
    }
}
