#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;
	while(t--)
	{
		ll n,a,b,c,d;
		cin>>n>>a>>b>>c>>d;
		ll grain_left = (a-b)*n,grain_right = (a+b)*n,total_left = c-d,total_right = c+d;
		if((grain_left > total_right) || (grain_right < total_left))
			cout<<"No";
		else
			cout<<"Yes";
	cout<<"\n";
	}

	return 0;
}
