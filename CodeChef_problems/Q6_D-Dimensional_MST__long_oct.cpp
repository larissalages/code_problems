/*
contest link : https://www.codechef.com/OCT20B
question link : https://www.codechef.com/OCT20B/problems/DDIMMST
*/
#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll ;
typedef pair<int,int> pii ;
const int nax = 2e5+5 ;
int par[nax] ;
ll ans=0 ;
int root(int x){

    while(par[x]!=x){
        par[x] = par[par[x]] ;
        x = par[x] ;
    }
    return x ;
}
void uni(int x,int y){
   int p = root(x) ;
   int q = root(y) ;
   par[q] = p ;
}
ll doagain(vector<pair<ll,int> > mp[], vector<vector<ll> > msksum , int n, int d,set<int> rootset, vector<int> roots, int cntcmp){

       ll maxedge[n],idx[n] ;
             vector<pair<ll,int> >mpp[3][(1<<d)] ;
        auto it = rootset.begin() ;
        int root1 = *it ;
        it++ ;
        int root2 = *it ;
        for(int mask=0;mask<(1<<d);mask++){
             for(int i=0;i<n;i++){
                int rootcmp = roots[mp[mask][i].second] ;
                if(rootcmp==root1){
                    mpp[1][mask].push_back({mp[mask][i].first,mp[mask][i].second}) ;
                }
                if(rootcmp==root2){
                    mpp[2][mask].push_back({mp[mask][i].first,mp[mask][i].second}) ;
                }
             }
        }
        while(cntcmp>1){
            for(int i=0;i<n;i++){
              maxedge[i]=-1 ;
              idx[i]=-1 ;
             }
   for(int k=0;k<n;k++){
        ll mxedg=0,mid ;
        int whroot ;
        int rootcmp = root(k) ;
        if(rootcmp==root1){
            whroot = 2 ;
        }
        if(rootcmp==root2){
            whroot = 1 ;
        }
        for(int mask=0;mask<(1<<d);mask++){
            ll sum = msksum[k][mask],id ;
            int cpmask = mask^((1<<d)-1)  ;
               for(int i=mpp[whroot][cpmask].size()-1;i>=0;i--){

                    int rootcmp2 = root( mpp[whroot][cpmask][i].second ) ;
                    if( rootcmp!=rootcmp2   ){
                        sum+=mpp[whroot][cpmask][i].first ;
                        id = mpp[whroot][cpmask][i].second ;
                        break ;
                    }
               }
            if(sum>=mxedg){
                mxedg = sum ;
                mid = id ;
            }
        }
        if( maxedge[rootcmp]<=mxedg ){
            maxedge[rootcmp] = mxedg ;
            idx[rootcmp] = mid ;
        }
   }
   for(int k=0;k<n;k++){
     if(maxedge[k]==-1)continue ;
     int root1 = root(k),root2 = root(idx[k]) ;
     if(root1 == root2)continue ;
     uni(root1,root2);
     ans+=maxedge[k] ;
     cntcmp-- ;
   }
        }
}

ll modifiedbovurka(vector<pair<ll,int> > mp[], vector<vector<ll> > msksum , int n, int d){

   ans = 0 ;
   int cmpmask ;
   int cntcmp = n ;
   ll maxedge[n],idx[n] ;
   set<int> rootset ;
   vector<int> roots(n) ;
   int badcase = 0 ;
   while(cntcmp>1){

        for(int i=0;i<n;i++){
            maxedge[i]=-1 ;
            idx[i]=-1 ;
        }


   for(int k=0;k<n;k++){
        ll mxedg=0,mid ;
        int root1 = root(k) ;
        for(int mask=0;mask<(1<<d);mask++){
            ll sum = msksum[k][mask],id ;
            int cmpmask = mask^((1<<d)-1)  ;
            
            if(sum + mp[cmpmask].back().first < mxedg){
                continue ;
            }

               for(int i=n-1;i>=0;i--){

                    int root2 = root( mp[cmpmask][i].second ) ;
                    if( root1!=root2   ){
                       sum+=mp[cmpmask][i].first ;
                        id = mp[cmpmask][i].second ;
                        break ;
                    }
               }
            if(sum>=mxedg){
                mxedg = sum ;
                mid = id ;
            }
        }
        if( maxedge[root1]<=mxedg ){
            maxedge[root1] = mxedg ;
            idx[root1] = mid ;
        }
   }
   for(int k=0;k<n;k++){
     if(maxedge[k]==-1)continue ;
     int root1 = root(k),root2 = root(idx[k]) ;
     if(root1 == root2)continue ;
     uni(root1,root2);
     ans+=maxedge[k] ;
     cntcmp-- ;
   }
   rootset.clear() ;
   if(d==2 && n>50001){
        badcase = 1 ;
   for(int k=0;k<n;k++){
       int root1 = root(k) ;
       rootset.insert(root1) ;
       roots[k] = root1 ;
   }
   if(rootset.size()==2){
       break ;
   }
   }

   }
   if(badcase){
     doagain(mp,msksum,n,d,rootset,roots,cntcmp) ;
   }

}
int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   for(int i=0;i<nax;i++){
     par[i] = i ;
   }
   int n,d ;
   cin>>n>>d ;
   vector<int> input[n] ;
   vector<pair<ll,int> > mp[(1<<d)] ;
   vector<vector<ll> > masksum(n) ;
   for(int i=0;i<n;i++){
      masksum[i].resize(1<<d) ;
   }
   for(int i=0;i<n;i++){
     int x ;
     for(int j=0;j<d;j++){
        cin>>x ;
        input[i].push_back(x) ;
     }
   }
   for(int ind=0;ind<n;ind++){
   for(int i=0;i<(1<<d);i++){
        ll sum = 0 ;
        for(int j=0;j<d;j++){
            int bit = i&(1<<j) ;
            if(bit){
                sum+=input[ind][j] ;
            }else{
                sum-=input[ind][j] ;
            }
        }
        mp[i].push_back({sum,ind}) ;
        masksum[ind][i] = sum ;
   }
   }
   for(int i=0;i<(1<<d);i++){
      sort(mp[i].begin(),mp[i].end()) ;
   }
   modifiedbovurka(mp,masksum,n,d) ;
   cout<<ans<<"\n" ;

return 0 ;}

