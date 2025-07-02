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
    ListNode* MergeList(ListNode* list1, ListNode* list2){
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val <= temp2->val){
                temp->next = temp1;
                temp1 = temp1->next;
            } else{
                temp->next = temp2;
                temp2= temp2->next;
            }

            temp = temp->next;
        }

        if(temp1!=NULL){
            temp->next = temp1;
        } else{
            temp->next = temp2;
        }

        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        for(int i=0;i<lists.size();i++){
            head = MergeList(head,lists[i]);
        }

        return head;
    }
};