//1047. Remove All Adjacent Duplicates In String(Leetcode)
//Solution using Stack data structure
class Solution {
public:
    string removeDuplicates(string S) {
        reverse(S.begin(),S.end()); //reversing input string because stacks are LIFO
        string output = "";         //Last In First Out
        stack <char> st;
        for(auto x : S){
            if(!(st.empty()) && x == st.top() ){
                st.pop();
            }else{
                st.push(x);
            }
        }
        while(!(st.empty())){
            output+=st.top();
            st.pop();
        }
        return output;
    }
};