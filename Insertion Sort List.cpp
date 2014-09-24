class Solution {
public:
    /*
 * @param head: head node
 * @param move: the node needed to be inserted
 * return: the node before the insertion position
 */
ListNode *find_insertion_position(ListNode *head, ListNode *move) {
    while(head->next && head->next->val <= move->val) {
        head = head->next;
    }
    return head;
}
 
ListNode *insertionSortList(ListNode *head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *iter = head;
    ListNode *sentinal = new ListNode(numeric_limits<int>::min());
    while(iter) {
        ListNode *next = iter->next;
        
        ListNode *insert_pos = find_insertion_position(sentinal, iter);
        iter->next = insert_pos->next;
        insert_pos->next = iter;
        iter = next;
    }
    return sentinal->next;
}
};