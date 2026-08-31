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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr)return {-1,-1};
        ListNode* p=head;
        ListNode* q=p->next;
        ListNode* r=q->next;
        int mn=INT_MAX;
        int cnt=1;
        int first=-1;
        int prev=-1;
        while(r!=nullptr){
            if((q->val>p->val && q->val>r->val)||(q->val<p->val && q->val<r->val)){
                if(first==-1){
                    first=cnt;
                }else{
                    mn=min(mn,cnt-prev);
                }
                prev=cnt;
            }
            p=p->next;
            q=q->next;
            r=r->next;
            cnt++;
        }
        if(first==-1 || first==prev)return {-1,-1};
        int mx=prev-first;
        return {mn,mx};
    }
};