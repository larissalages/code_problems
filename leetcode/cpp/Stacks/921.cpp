/* Author: Ajeet Kumar Jaiswal*/
class Solution {
public:
    #define pb push_back
    int minAddToMakeValid(string str) {
        // One thing two observe that we have to just check how many balanced parenthesis are there else other have to be given one pair always for i.e (((=>here stack will contain 3 elements and thus can be converted to ()()()=> one for each unbalanced parenthesis
        int n=str.size();
        stack<char>s;
        vector<char>v;
        // Actually Here the concept is same as we apply in normal parenthesis problem but only difference              is that there we used to check whether any condition get false or not but here instead of that              we'll store that closing bracket in a vector and then can calculate their size of stack and vec.
        for(int i=0;i<n;i++){
            if(s.empty()){
                if(str[i]==')'){
                    v.pb(')');
                }
                else{
                    s.push(str[i]);
                }
            }
            // Now we know that stack is containing only opening brackets.
            else{
                char ch=s.top();
                if(str[i]==')'){
                    if(str[i]=')' && ch!='('){
                        v.pb(')');
                    }
                    else{
                        s.pop();
                    }
                }
                else{
                    s.push(str[i]);
                }
            }
        }
        return v.size()+s.size();
    }
};
