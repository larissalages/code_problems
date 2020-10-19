
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        
        if(a>=4){
            cout<<a/2<<"\n";
            if(a%2==0){
                for(int j=0;j<a;j+=2){
                    cout<<2<<" "<<j+1<<" "<<j+2<<"\n"; 
                }
            }
            else{
                cout<<3<<" "<<1<<" "<<2<<" "<<a<<"\n";
                for(int j=2;j<a-2;j+=2){
                    cout<<2<<" "<<j+1<<" "<<j+2<<"\n";
                }
            }
        }
        else{
            cout<<1<<"\n";
            if(a==1){
                cout<<1<<" "<<1<<"\n";
            }
            else if(a==2){
                cout<<2<<" "<<1<<" "<<2<<"\n";
            }
            else{
                cout<<3<<" "<<1<<" "<<2<<" "<<3<<"\n";
            }
        }
    }
}
