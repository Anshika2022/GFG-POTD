class Solution {
  public:
    bool solve(vector<int>& arr, int sum,int i,vector<vector<int>>&dp){
        //base case 
        if(sum==0) return true;
        if(i==arr.size()) return false;
        //recursive case
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool pick=false,nopick=false;
        if(arr[i]<=sum) pick=solve(arr,sum-arr[i],i+1,dp);
        nopick=solve(arr,sum,i+1,dp);
        return dp[i][sum]= (pick || nopick);
    }
        
    bool isSubsetSum(vector<int>& arr, int sum) {
        // CodeGenius
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return solve(arr,sum,0,dp);
        
    }
    
    bool equalPartition(vector<int>& arr) {
        // CodeGenius
        int total=0;
        for(int i=0;i<arr.size();i++) total+=arr[i];
        if(total%2!=0) return false;
        return isSubsetSum(arr,total/2);
        
        
    }
};
