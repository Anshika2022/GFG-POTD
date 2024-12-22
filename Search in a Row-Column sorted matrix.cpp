class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int i=0,j=mat[0].size()-1,n=mat.size();
        while(i<n and j>=0){
            int temp = mat[i][j];
            if(temp==x)return true;
            else if(temp<x)i++;
            else j--;
        }
        return false;
    }
};
