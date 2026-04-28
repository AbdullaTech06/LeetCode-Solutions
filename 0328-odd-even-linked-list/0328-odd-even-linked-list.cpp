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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr)return head;
        ListNode* oddhead = new ListNode(-1,nullptr);
        ListNode* evenhead = new ListNode(-1,nullptr);
        ListNode* odd = oddhead;
        ListNode* even = evenhead;
        ListNode* temp = head;
        int cnt=1;
        while(temp!=nullptr){
            if(cnt%2==1){
                odd->next=temp;
                odd=odd->next;
            }else{
                even->next=temp;
                even=even->next;
            }
            cnt++;
            temp=temp->next;
        }
        even->next=nullptr;
        odd->next=evenhead->next;
        return oddhead->next;
    }
};