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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*temp=head;
        if(head==NULL||head->next==NULL){
            return NULL;
            
        }
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        int a=count/2;
        int count2=-1;
        ListNode*temp2=head;
        while(temp2){
            count2++;
            if(count2==a-1){
                temp2->next=temp2->next->next;
                break;
            }else{
                temp2=temp2->next;
            }

        }
        return head;

        
    }
};