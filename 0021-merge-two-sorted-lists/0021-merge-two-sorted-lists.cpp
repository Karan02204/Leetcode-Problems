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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        if(temp1 == NULL) return temp2;
        if(temp2 == NULL) return temp1;

        ListNode dummy(0);
        ListNode* temp = &dummy;

        while(temp1!=NULL && temp2!=NULL){
           if(temp1->val <= temp2->val){
            temp->next = temp1;
            temp1 = temp1->next;
           }else{
            temp->next = temp2;
            temp2 = temp2->next;
           }

           temp = temp->next;
        }

        if(temp1==NULL){
            temp->next = temp2;
        }

        if(temp2 == NULL){
            temp->next = temp1;
        }

        return dummy.next;
    }
};