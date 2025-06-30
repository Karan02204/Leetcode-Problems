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
        ListNode* temp = head;
        int size=1;
        if(head == NULL || head->next == NULL || k==0){
            return head;
        }
        while(temp->next!=NULL){
            temp = temp->next;
            size++;
        }
        temp->next = head; // making it a circular list
        k = k%size;
        int steps = size - k;
        ListNode* newTail = head;
        for(int i=1;i<steps;i++){
            newTail = newTail->next;
        }

        ListNode* newhead = newTail->next;
        newTail->next = NULL;

        return newhead;
    }
};