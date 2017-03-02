/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return head;
        unordered_map <RandomListNode*, RandomListNode*> Map;
        RandomListNode *head2 = new RandomListNode(head->label);
        Map[head] = head2;
        RandomListNode *newHead = head2;
        RandomListNode *next, *random;
        while(head) {
            next = head->next, random = head->random;

            if(next) {
                if(!Map[next]) {
                    head2->next = new RandomListNode(next->label);
                    Map[next] = head2->next;
                } else {
                    head2->next = Map[next];
                }

            }

            if(random) {
                if(!Map[random]) {
                    head2->random = new RandomListNode(random->label);
                    Map[random] = head2->random;
                } else {
                    head2->random = Map[random];
                }
            }


            head2 = head2->next;
            head = next;
        }
        return newHead;
    }
};