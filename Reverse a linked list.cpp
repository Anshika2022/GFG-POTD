class Solution {
  public:
    Node* reverseList(struct Node* head) {
        // code here
        Node *curr=head, *prev=NULL, *next=curr->next;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};
