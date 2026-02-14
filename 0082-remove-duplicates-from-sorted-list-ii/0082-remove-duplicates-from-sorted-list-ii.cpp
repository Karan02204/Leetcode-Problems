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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr!=NULL && curr->next != NULL){
            if(curr->val == curr->next->val){
                ListNode* temp = curr;
                while(temp->next != NULL && temp->val == temp->next->val){
                    temp = temp->next;
                }

                if(curr == head){
                    head = temp->next;
                }else{
                    prev->next = temp->next;
                }

                curr = temp->next;
            } 
            else{
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
    }
};