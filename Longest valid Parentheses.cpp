class Solution {
  public:
    int maxLength(string& s) {
        // code here
         stack<int>st;
        st.push(-1);
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(!st.empty()) maxi=max(maxi,i-st.top());
                else st.push(i);
            }
        }
        return maxi;
    }
};
