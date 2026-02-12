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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        vector<int> arr;
        ListNode* curr =head;

        while(curr!=NULL){
            arr.push_back(curr->val);
            curr=curr->next;
        }

        sort(arr.begin(),arr.end());
        ListNode* newNode = new ListNode(arr[0]);
        ListNode* temp = newNode;

        for(int i=1;i<arr.size();i++){
            ListNode* node = new ListNode(arr[i]);
            temp->next = node;
            temp = temp->next;
        }

        return newNode;
    }
};