class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        vector<int> ans;
        unordered_map<int,int> mm;
        for(int x:a)mm[x]=1;
        for(int x:b){
            if(mm[x]){
                ans.push_back(x);
                mm[x]=0;
            }
        }
        return ans;
    }
};
