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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0 , start;
        ListNode* temp = head;
        while(temp!=NULL){
            length++;
            temp = temp->next;
        }
        
        start = length - n;

        if(start == 0){
            ListNode* temp2 = head;
            head = head->next;
            delete temp2;
            return head;
        }

        ListNode* curr = head;
        start -= 1;
        while(curr!=NULL && start >0){
            start--;
            curr = curr->next;
        }

        ListNode* nextNode = curr->next;
        curr->next = nextNode->next;
        delete nextNode;
        return head;

    }
};