// BELLMAN FORD ALGORITHM TO DETECT NEGATIVE CYCLE IN GRAPHS....





#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
using ii= pair<ll,ll>;
#define F first
#define S second
#define MP make_pair
#define PB push_back


struct Edge{                                    // we implement it using struct edge where each edge stores the edge details..
    ll a,b,c;                                   //a->node,b->node,c->cost            (c)
                                                                             //a--------->b  
};


vector<Edge> v;                                 // instead of creating a vector of piars , create a vector of edges where each element of the
                                                // vector is an edge....
void Bellman_Ford(ll n,ll m)                    // n-> nodes_no, m-> no_of_edges..
{
    vector<ll> d(n,1e18);      //holding min distance of nodes....
    d[0]= 0;                   // initializing src at 0 distance
    
    ll x;                      // x-> flag for negative cycle....
    
    for(ll i=0;i;i++)        // after i iterations, i nodes will have attained there min distance provided -ve cycles not involved...
    {<n
        x=-1;
        
        for(ll j=0;j<m;j++)    // loop on all edges 
        {
            if(d[v[j].b]>d[v[j].a]+v[j].c)     // relax distance if u get any min_path
            {
                d[v[j].b]=d[v[j].a]+v[j].c;
                x= v[j].a;                    
            }
        }
    }
    
    
    if(x!=-1)
    {
        cout<<"possible\n";     // got a negative cycle....
    }
    
    else{
        cout<<"not possible\n";    // otherwise not....
    }
    
    
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n,m;
	    cin>>n>>m;
	    
	    v.resize(m+1);                  // very important ...u may get RE if u dont resize v
	    v.clear();                      // u must clear v if there are more than 1 test cases....
	    
	    
	    for(ll i=0;i<m;i++)
	    {
	        ll x,y,z;
	        cin>>x>>y>>z;
	        
	        v.PB({x,y,z});        
	    }
	    
	    
	    Bellman_Ford(n,m);
	    
	    
	}
}





