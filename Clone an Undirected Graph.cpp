class Solution {
  public: 
    unordered_map<Node*,Node*>alreadymade;
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        if(alreadymade.find(node)!=alreadymade.end()) return alreadymade[node];
        Node* clone1=new Node(node->val);
        alreadymade[node]=clone1;
        for(auto it:node->neighbors){
            clone1->neighbors.push_back(cloneGraph(it));
        }
        return clone1;
    }
};
