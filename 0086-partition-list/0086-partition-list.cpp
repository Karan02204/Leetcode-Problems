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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        ListNode* dummy = new ListNode(0);
        ListNode* start = dummy;
        ListNode* dummy2 = new ListNode(-1);
        ListNode* start2= dummy2;

        if(head==NULL){
            return NULL;
        }
        while(temp!=NULL){
            if(temp->val<x){
                start->next = temp;
                start = start->next;
            } else{
                start2->next = temp;
                start2 = start2->next;
            }

            temp = temp->next;
        }
        start2->next = NULL;
        start->next = dummy2->next;

        return dummy->next;
    }
};