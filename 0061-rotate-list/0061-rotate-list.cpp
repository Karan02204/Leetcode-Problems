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
        
        k = k % size;
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i =0;i<k;i++){
            fast = fast->next;
        }

        while(fast->next!=NULL){
            fast =fast->next;
            slow = slow->next;
        }

        fast->next = head;
        head = slow->next;
        slow->next= NULL;

        return head;
    }
};