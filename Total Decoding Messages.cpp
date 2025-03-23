class Solution {
  public:
    int solve(string &digits,int n,int i,vector<int>&dp){
        //base case
        if(i==n) return 1;
        if(digits[i]=='0') return 0 ;
        //recursive case
        if(dp[i]!=-1) return dp[i];
        int one=solve(digits,n,i+1,dp);
        int two=0;
        if(i!=n-1 && (digits[i]=='1' ||digits[i]=='2' && digits[i+1]<='6' ))
        two = solve(digits,n,i+2,dp);
        return dp[i]= one+two;
    }
    int countWays(string &digits) {
        int n=digits.size();
        vector<int>dp(n+1,-1);
        return solve(digits,n,0,dp);
        
    }
};
