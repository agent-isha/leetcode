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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> allValues;

        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            

            while (temp != NULL) {
                allValues.push_back(temp->val);
                temp = temp->next;
            }
        }  
        if (allValues.empty()) return nullptr;
        sort(allValues.begin(),allValues.end());
        ListNode*head= new ListNode(allValues[0]);
        ListNode*curr=head;
        
        for(int i=1;i<allValues.size();i++){
            curr->next=new ListNode(allValues[i]);
            curr=curr->next;
        }
        return head;

        
    }
};