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
    ListNode* getKthNode(ListNode* temp,int k){
        k-=1;
        while(temp!=nullptr && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            ListNode* nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || k==1){
            return head;
        }
        ListNode* temp=head;
        ListNode* prevlast=nullptr;

        while(temp!=nullptr){
            ListNode* kthnode=getKthNode(temp,k);
            if(kthnode==nullptr){
                if(prevlast){
                    prevlast->next=temp;
                }
                break;
            }
            ListNode* nextnode=kthnode->next;
            kthnode->next=nullptr;
            reverse(temp);
            if(temp==head){
                head=kthnode;
            }else{
                prevlast->next=kthnode;
            }
            prevlast = temp;
            temp = nextnode;
        }
        return head;
    }
};