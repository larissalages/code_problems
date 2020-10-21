class Solution {
public:
int largestRectangleArea(vector<int> &A) {
    int res = 0;
    A.push_back(0);

    stack<int> st;

    for(auto i=0; i<A.size(); i++)
    {
        if(st.empty() || A[i] >= A[st.top()])
            st.push(i);
        else
        {
            int j = st.top();
            st.pop();
            res = max(res, A[j]*(st.empty() ? i : i - st.top() - 1));
            i--;
        }
    }

    return res;
}
};
