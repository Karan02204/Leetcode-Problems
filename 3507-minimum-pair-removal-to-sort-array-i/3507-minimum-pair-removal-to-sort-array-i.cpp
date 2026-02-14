class Solution {
public:

    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    bool isNonDecreasing(ListNode* head) {
        while(head && head->next) {
            if(head->next->val < head->val)
                return false;
            head = head->next;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        if(nums.size() <= 1) return 0;

        ListNode* head = new ListNode(nums[0]);
        ListNode* temp = head;

        for(int i = 1; i < nums.size(); i++) {
            temp->next = new ListNode(nums[i]);
            temp = temp->next;
        }

        int operations = 0;

        while(!isNonDecreasing(head)) {

            ListNode* prev = NULL;
            ListNode* curr = head;

            int minSum = INT_MAX;
            ListNode* minPrev = NULL;
            ListNode* minNode = NULL;

            while(curr && curr->next) {
                int sum = curr->val + curr->next->val;
                if(sum < minSum) {
                    minSum = sum;
                    minPrev = prev;
                    minNode = curr;
                }
                prev = curr;
                curr = curr->next;
            }

            minNode->val = minSum;
            ListNode* deleteNode = minNode->next;
            minNode->next = deleteNode->next;
            delete deleteNode;

            operations++;
        }

        return operations;
    }
};
