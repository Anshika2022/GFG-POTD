class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
         vector<vector<int>>result;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            vector<int>ans;
            Node* curr=q.front();
            q.pop();
            ans.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            result.push_back(ans);
        }
        return result;
    }
};
