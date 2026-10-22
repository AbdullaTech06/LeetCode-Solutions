/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* h1=NULL;
        ListNode* h2=NULL;
        ListNode* t=head;
        ListNode* t1=NULL;
        ListNode* t2=NULL;
        while(t!=NULL){
            if(t->val<x){
                if(h1==NULL){
                    h1=new ListNode(t->val);
                    t1=h1;
                }else{
                    t1->next=new ListNode(t->val);
                    t1=t1->next;
                }
            }else{
                if(h2==NULL){
                    h2=new ListNode(t->val);
                    t2=h2;
                }else{
                    t2->next=new ListNode(t->val);
                    t2=t2->next;
                }
            }
            t=t->next;
        }
        if(h1==NULL)return h2;
        t1->next=h2;
        return h1;
    }
};