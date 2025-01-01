class Solution {
    public ArrayList<ArrayList<String>> anagrams(String[] arr) {
        // code here
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<arr.size();i++){
            string temp=arr[i];
            sort(temp.begin(),temp.end());
            mp[temp].push_back(arr[i]);
        }
        vector<vector<string>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
}
