class Solution {
  public:
    int mini;
    stack<int>st;
    Solution() {
        // CodeGenius
    }
    void push(int x) {
        if(st.empty()) mini=x;
        else if(x<=mini){
            st.push(mini);
            mini=x;
        }
        st.push(x);
    }
    void pop() {
        if(st.empty()) return;
        int temp=st.top();
        st.pop();
        if(temp==mini && !st.empty() ){
            mini=st.top();
            st.pop();
        }
    }
    int peek() {
        if(st.empty()) return -1;
        return st.top();
    }
    int getMin() {
        if(st.empty()) return -1;
        return mini;
    }
};
//JAVA CODE
class Solution {
    Stack<Integer> st;
    Stack<Integer> minSt;
    
    public Solution() {
        st = new Stack<>();
        minSt = new Stack<>();
    }

    // Add an element to the top of Stack
    public void push(int x) {
        // code here
        st.push(x);
        
        if(minSt.isEmpty() || minSt.peek() >= x)
        minSt.push(x);
    }

    // Remove the top element from the Stack
    public void pop() {
        // code here
        if(st.isEmpty())
        return;
        
        int x = st.pop();
        
        if(minSt.peek() == x)
        minSt.pop();
    }

    // Returns top element of the Stack
    public int peek() {
        // code here
        if(st.isEmpty())
        return -1;
        
        return st.peek();
    }

    // Finds minimum element of Stack
    public int getMin() {
        // code here
        if(minSt.isEmpty())
        return -1;
        
        return minSt.peek();
    }
}
