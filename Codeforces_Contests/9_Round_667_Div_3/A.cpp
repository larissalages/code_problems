#include <string>
#include <vector>
 
#include <algorithm>
#include <cmath>
 
using namespace std;
 
int main()
 
{
    int noOfTestCase{};
    cin>>noOfTestCase;
    long long a[noOfTestCase];
    long long b[noOfTestCase];
    for(int i=0;i<noOfTestCase;i++){
        cin>>a[i];
        cin>>b[i];
    }
    for(int i=0;i<noOfTestCase;i++){
        
        if(abs(a[i]-b[i])==0){
          cout<<"0"<<endl;  
        }else if(abs(a[i]-b[i])%10==0){
            cout<<(abs(a[i]-b[i])/10)<<endl;
        }else{
            cout<<(abs(a[i]-b[i])/10)+1<<endl;
        }
     }
 
    return 0;
}
