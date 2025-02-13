class Solution {
  public:
  void inorder(Node *root,vector<int>&ans){
        if(!root) return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    bool findTarget(Node *root, int target) {
        // your code here.
        vector<int>ans;
        inorder(root,ans);
        int s=0,e=ans.size()-1;
        while(s<e){
            if(ans[s]+ans[e]==target) return true;
            else if(ans[s]+ans[e]>target) e--;
            else s++;
        }
        return false;
    }
};
