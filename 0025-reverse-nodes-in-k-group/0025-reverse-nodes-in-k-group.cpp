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
        ListNode* curr = head, *prev = NULL;

        while(curr!=NULL){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }
    
    ListNode* findkNode(ListNode* temp , int k){
        k -= 1;
        while(temp!=NULL && k>0){
            k--;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head , *prev = NULL;

        while(temp!=NULL){
            ListNode *kth = findkNode(temp , k);
            if(kth == NULL){
                if(prev) prev->next = temp;
                break;
            }

            ListNode* nextNode = kth->next;
            kth->next = NULL;

            reverseList(temp);
            if(temp == head){
                head = kth;
            } else{
                prev->next = kth;
            }

            prev = temp;
            temp = nextNode;
        }

        return head; 
    }
};