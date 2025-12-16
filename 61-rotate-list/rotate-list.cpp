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
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode*temp=head;
        int count =0;
        while(temp){
            count++;
            temp=temp->next;
        }
        k = k % count;
        if (k == 0) return head;

        int a=count-k;
        ListNode*temp2=head;
        int c=1;
        ListNode dummy(0);
        ListNode*curr=&dummy;
        while(temp2){
            
            if(c==a){
                curr->next=temp2->next;
                temp2->next=NULL;
                break;

                

            }
            c++;
            temp2=temp2->next;
        }
        ListNode* tail = curr->next;
        while (tail->next) {
            tail = tail->next;
        }

        
        tail->next = head;

        return curr->next;
        
    }
};