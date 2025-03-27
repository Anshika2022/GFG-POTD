class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int count=0;
        int maxi=-1;
        int i=0;
        int j=0;
        int n=arr.size();
        while(i<n && j<n ){
            if(arr[i]<=dep[j]){
                count++;
                i++;
            }
            else{
                count--;
                j++;
            }
            maxi=max(maxi,count);
        }
        maxi=max(maxi,count);
        return maxi;
    }
};
