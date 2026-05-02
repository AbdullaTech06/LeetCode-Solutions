/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        Node* temp=head;
        while(temp!=nullptr){
            Node* copy=new Node(temp->val);
            copy->next=temp->next;
            temp->next=copy;
            temp=copy->next;
        }

        temp=head;
        while(temp!=nullptr){
            if(temp->random){
                temp->next->random=temp->random->next;
            }
            temp=temp->next->next;
        }
        temp=head;
        Node* dummy=new Node(-1);
        Node* res=dummy;

        while(temp!=nullptr){
            Node* copy=temp->next;
            temp->next=copy->next;
            res->next=copy;
            res=copy;
            temp=temp->next;
        }
        return dummy->next;
    }
};