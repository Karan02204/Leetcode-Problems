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
    ListNode* reverseList(ListNode* head){
        ListNode* temp = head , *prev=nullptr;

        while(temp!=nullptr){
            ListNode* next = temp->next;
            temp->next = prev;
            prev= temp;
            temp = next;
        }

        return prev;
    }

    ListNode* findkth(ListNode* temp , int k){
        k-=1;
        while(temp && k>0){
            k--;
            temp = temp->next;
        }

        return temp;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;
        ListNode* leftNode = findkth(head,left);
        ListNode* rightNode = findkth(head,right);

        ListNode* curr = head;
        ListNode* prevLeft = NULL;

        if(left!=1){
            while(curr->next != leftNode){
                curr = curr->next;
            }

            prevLeft = curr;
        }

        ListNode* nextNode = rightNode->next;
        rightNode->next = NULL;

        ListNode* newHead = reverseList(leftNode);
        
        if(prevLeft){
            prevLeft->next = newHead;
        } else{
            head = newHead;
        }

        leftNode->next = nextNode;

        return head;

    }
};