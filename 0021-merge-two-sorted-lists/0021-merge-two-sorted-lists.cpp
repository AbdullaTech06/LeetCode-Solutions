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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1=list1;
        ListNode* temp2=list2;
        ListNode* ans= new ListNode(-1);
        ListNode* t=ans;
        while(temp1 && temp2){
            if(temp1->val>temp2->val){
                t->next=new ListNode(temp2->val);
                temp2=temp2->next;
                t=t->next;
            }else{
                t->next=new ListNode(temp1->val);
                temp1=temp1->next;
                t=t->next;
            }
        }
        while(temp1){
            t->next=new ListNode(temp1->val);
            temp1=temp1->next;
            t=t->next;
        }
        while(temp2){
            t->next=new ListNode(temp2->val);
            temp2=temp2->next;
            t=t->next;
        }
        return ans->next;
    }
};