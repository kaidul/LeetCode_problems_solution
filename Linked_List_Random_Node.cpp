/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // Reservoir sampling - randomly choosing a sample of k items from a list S containing n items,
 // where n is either a very large or unknown number. Typically n is large enough that the list doesn't fit into main memory.
class Solution {
private:
    ListNode* head;
    default_random_engine generator;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        generator = default_random_engine();
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* iter = head;
        int value = iter->val;
        for(int k = 1; iter->next; ++k) {
            iter = iter->next;
            uniform_int_distribution<int> distribution(0, k);
            if(distribution(generator) == k) {
                value = iter->val;
            }
        }
        return value;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */