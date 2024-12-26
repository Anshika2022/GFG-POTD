class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        unordered_map<int,int> mm;
        for(int x:arr){
            if(mm[target-x])return true;
            mm[x]=1;
        }
        return false;
    }
};
