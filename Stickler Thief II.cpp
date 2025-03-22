class Solution {
  public:
    int solve(vector<int>& arr,int i,int n,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=arr[i]+solve(arr,i+2,n,dp);
        int nopick=solve(arr,i+1,n,dp);
        return dp[i]= max(pick,nopick);
    }
    int maxValue(vector<int>& arr) {
        //CodeGenius
        int n=arr.size();
        vector<int>dp(n,-1);
        int case1=solve(arr,0,n-1,dp);
        fill(dp.begin(),dp.end(),-1);
        int case2=solve(arr,1,n,dp);
        return max(case1,case2);
        
    }
};
