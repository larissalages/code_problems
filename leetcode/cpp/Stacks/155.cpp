class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
     stack<int> st;
    stack<int> min_st;
    void push(int x) {
        st.push(x);
    int val =x;
   if(min_st.size()>0 && min_st.top()<x)
   {
       val =min_st.top();
   }
    min_st.push(val);
    }

    void pop() {
       if(!st.empty())
   { st.pop();
     min_st.pop();
   }
    }

    int top() {
       if(st.empty())
    return -1;
    else
    return st.top();

    }

    int getMin() {
        if(st.empty())
    return -1;
    else
    return min_st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
