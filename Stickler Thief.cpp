class Solution {
  public:
    int solve(vector<int>& arr,int n){
        if(n==1) return arr[0];
        if(n==2) return max(arr[0],arr[1]);
        int prev=arr[0];
        int sprev=0;
        int ans=0;
        for(int i=1;i<n;i++){
            ans=max(prev,sprev+arr[i]);
            sprev=prev;
            prev=ans;
        }
        return ans;
        
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        return solve(arr,n);
        
    }
};
