class Solution {
  public:
    int solve(int n){
        int prev1=1;
        int prev2=1;
        int curr;
        if(n<=1) return n;
        for(int i=2;i<=n;i++){
            curr=prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
    int countWays(int n) {
        // CodeGenius
        return solve(n);
    }
};
