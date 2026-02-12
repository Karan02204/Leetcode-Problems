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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* curr = head;
        vector<int> arr;
        while(curr!=NULL){
            arr.push_back(curr->val);
            curr = curr->next;
        }

        reverse(arr.begin() , arr.end());

        ListNode* newHead = new ListNode(arr[0]);
        ListNode* temp = newHead;

        for(int i=1;i<arr.size();i++){
            ListNode* node = new ListNode(arr[i]);
            temp->next = node;
            temp = node;
        }

        return newHead;
    }
};