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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
        ListNode* temp=head;
        int len=0;
        while(temp!=nullptr){
            len++;
            temp=temp->next;
        }
        if(n == len){
            ListNode* del=head;
            head=head->next;
            delete del;
            return head;
        }
        int x = len-n;
        int cnt=0;
        temp=head;
        ListNode* prev = nullptr;
        while(temp!=nullptr){
            cnt++;
            prev=temp;
            temp=temp->next;
            if(cnt==x){
                prev->next=temp->next;
                delete temp;
                break;
            }
        }
        return head;
    }
};