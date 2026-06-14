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
    int pairSum(ListNode* head) {
        ListNode* l=head;
        ListNode* r=head;
        while(r!=nullptr && r->next!=nullptr){
            l=l->next;
            r=r->next->next;
        }

        ListNode* prev=nullptr;
        ListNode* curr=l;

        while(curr!=nullptr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        int ans=0;
        ListNode* f=head;
        ListNode* s=prev;
        while(s!=nullptr && f!=nullptr){
            ans=max(ans,f->val+s->val);
            f=f->next;
            s=s->next;
        }
        return ans;
    }
};