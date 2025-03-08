class Solution {
  public:
  int length(int left,int right,string &s){
          int len=0;
        while(left>=0 && right<s.size()){
            if(s[left]==s[right]){
                len+=2;
                left--;
                right++;
            }
            else break;
        }
        return len;
    }
    string longestPalindrome(string &s) {
       
        int n=s.size();
        int maxlen=1;
        int start=0;
        
        //odd
        for(int i=0;i<n;i++){
            int len=1+length(i-1,i+1,s);
            if(len>maxlen){
            maxlen=len;
            start=i-len/2;
            }
        }
        //even
        for(int i=1;i<n;i++){
            int len=length(i-1,i,s);
            if(len>maxlen){
            maxlen=len;
            start=i-len/2;
            }
        }
        return s.substr(start,maxlen);
    }
};
