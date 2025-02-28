class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int>st;
        for(string&i : arr){
            if(i=="+" ||i=="*" ||i=="-" ||i=="/"){
                int b=st.top(); st.pop();
                int a=st.top(); st.pop();
                int result;
                if(i=="+") result=a+b;
                else if(i=="-") result=a-b;
                else if(i=="*") result=a*b;
                else if(i=="/") result=a/b;
                st.push(result);
            }
            else st.push(stoi(i));
        }
        return st.top();
    }
};
