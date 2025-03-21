class Solution {
  public:
  bool isPossible(vector<int> &arr,int k,int mid){
        int sum=0,student=1;
        for(int x:arr){
            sum+=x;
            if(sum>mid){
                student++;
                sum=x;
            }
        }
        return student<=k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k>arr.size())return -1;
        int sum=0,mx=INT_MIN;
        for(int x:arr){
            sum+=x;
            mx=max(mx,x);
        }
        int low=mx,high=sum,mid,ans=INT_MAX;
        while(low<=high){
            mid=(low+high)/2;
            if(isPossible(arr,k,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};
