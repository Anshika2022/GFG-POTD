class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Your code here
        priority_queue<pair<int,vector<int>>>maxHeap;
        for(auto &i:points){
            int x=i[0],y=i[1];
            int dist=x*x + y*y;
            maxHeap.push({dist,i});
            if(maxHeap.size()>k) maxHeap.pop();
        }
        vector<vector<int>>ans;
        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};
