class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here
        int ans=0;
        unordered_map<int,int> mm;
        for(int x:a){
            if(!mm[x])ans++;
            mm[x]=1;
        }
        for(int x:b){
            if(!mm[x])ans++;
            mm[x]=1;
        }
        return ans;
    }
};
