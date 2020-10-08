// Author:Nishtha

#include <bits/stdc++.h> 
using namespace std; 
  
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long
#define pb push_back 
#define mp make_pair 
#define F first 
#define S second 
#define all(x) x.begin(), x.end() 
#define clr(x) memset(x, 0, sizeof(x)) 
#define sortall(x) sort(all(x)) 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pl; 
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<pii> vpii; 

int checkPrecedence(char c){
  if(c=='^')
    return 3;
  else if (c=='*' || c=='/')
    return 2;
  else if(c=='+' || c=='-')
    return 1;
  else return -1;
}

void infixToPostfix(string s){
  stack<char>st;
  st.push('N');
  fi(i,0,s.size()){
    // operand mile to print kra do 
    if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z')||(s[i]>=0 && s[i]<=9)) 
      cout<<s[i];
    // open parenthis ho to push kr do stack m
    else if(s[i] == '(')  
      st.push('('); 
    //  ‘)’ mile to pop aur print kro stack m se jab tk open wala na mile 
    else if(s[i] == ')'){ 
      while(st.top() != 'N' && st.top() != '('){ 
        char c = st.top(); 
        st.pop(); 
        cout<<c; 
      } 
      if(st.top() == '(') { 
        char c = st.top(); 
        st.pop(); 
      } 
    } 
    // agar operator milta h to
    else{
      while(st.top()!='N' && checkPrecedence(s[i])<=checkPrecedence(st.top())){
        char c=st.top();
        st.pop();
        cout<<c;
      }
      st.push(s[i]);
    }
  }
  // jo bacha print kara do
  while(st.top()!='N'){
    char c=st.top();
    st.pop();
    cout<<c;
  }
}

int Eval(string s){
  stack<int>st;
  int result,i;
  for(i=0;i<s.size();i++){
    if(!(s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-')){
      st.push(s[i]-'0');
    }else{
      int x2=st.top();
      st.pop();
      int x1=st.top();
      st.pop();
      switch(s[i])
      {
        case '+':result=x1+x2;
         break;
        case '-':result=x1-x2;
         break;
        case '*':result=x1*x2;
         break;
        case '/':result=x1/x2;
         break;
      }
      st.push(result);        
    }    
  }
  return st.top();
}

// Drive Code 
int main() 
{  
  // #ifndef ONLINE_JUDGE 
  // freopen("input.txt", "r", stdin); 
  // freopen("output.txt", "w", stdout); 
  // #endif
  // Fast Input/Output 
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0); 

  // Test Cases 
  ll t = 1; 
  // cin >> t;

  while (t--) { 
    string s;
    cout<<"Enter postfix string for evaluation"<<"\n";
    cin>>s;
    // infixToPostfix(s);
  } 

  return 0; 
} 
