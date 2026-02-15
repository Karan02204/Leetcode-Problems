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
    ListNode* reverseList(ListNode* temp){
        ListNode* prev = NULL;
        while(temp!=NULL){
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* curr = head;

        while(curr->next!=NULL){
            ListNode* nextNode = curr->next;
            ListNode* newHead = reverseList(nextNode);
            curr->next = newHead;
            curr = newHead;
        }
    }
};