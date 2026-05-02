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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr || k==0){
            return head;
        }
        int len=1;
        ListNode* tail=head;
        while(tail->next!=nullptr){
            tail=tail->next;
            len++;
        }
        k=k%len;
        if(k==0){
            return head;
        }
        tail->next=head;

        ListNode* newtail=head;
        for(int i=1;i<len-k;i++){
            newtail=newtail->next;
        }
        ListNode* newhead=newtail->next;
        newtail->next=nullptr;

        return newhead;
    }
};