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
    ListNode* swapPairs(ListNode* head) {
       ListNode* temp = head;
       ListNode* dummy = new ListNode(0);
       ListNode* start = dummy;
       if(head==NULL){
        return NULL;
       }

       if(head->next==NULL){
        return head;
       }
       while(temp!=NULL && temp->next!=NULL){
        ListNode* nextNode = temp->next;
        start->next = nextNode;
        temp->next = nextNode->next;
        nextNode->next = temp;

        temp = temp->next;
        start = start->next->next;
       }

       return dummy->next; 
    }
};