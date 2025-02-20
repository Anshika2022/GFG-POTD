class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int>leftmaxheap;
        priority_queue<int,vector<int>,greater<int>>rightminheap;
        vector<double>ans;
        for(int i=0;i<arr.size();i++){
            leftmaxheap.push(arr[i]);
            
            int ele=leftmaxheap.top();
            rightminheap.push(ele);
            leftmaxheap.pop();
            
            if(rightminheap.size()>leftmaxheap.size()){
                int ele=rightminheap.top();
                leftmaxheap.push(ele);
                rightminheap.pop();
            }
            double median;
            if(leftmaxheap.size()!=rightminheap.size())
            median=leftmaxheap.top();
            else
            median=(double)(leftmaxheap.top()+rightminheap.top())/2;
            ans.push_back(median);
        }
        return ans;
    }
};
