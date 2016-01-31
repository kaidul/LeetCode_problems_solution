/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
        // TLE
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            ListNode *iter = new ListNode(numeric_limits<int>::max());
            ListNode *head = iter;
            bool found = true;
            int indx = -1;
            while(found) {
                found = false;
                for(int i = 0, n = lists.size(); i < n; ++i) {
                    if(lists[i]) {
                        found = true;
                        if(!iter->next) {
                            iter->next = lists[i];
                            indx = i;
                        } else if(iter->next->val <= lists[i]->val) {
                            iter->next = lists[i];
                            indx = i;
                        }
                    }
                }
                if(found) {
                    iter = iter->next;
                    lists[indx] = lists[indx]->next;
                }
            }
            return head->next;
        }
    **/
    /**
    // O(k * n log k * n) TLE
    priority_queue <int> Q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int i = 0, n = lists.size(); i < n; ++i) {
            while(lists[i]) {
                Q.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }
        if(Q.empty()) return nullptr;
        ListNode *head = new ListNode(Q.top());
        ListNode *iter = head;
        Q.pop();
        while(!Q.empty()) {
            iter->next = new ListNode(Q.top());
            Q.pop();
            iter = iter->next;
        }
        return head;
    }
    **/

    // O(n * k log k)
    priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int i = 0, n = lists.size(); i < n; ++i) {
            if(lists[i]) {
                Q.push(make_pair(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        }
        ListNode *head = new ListNode(0);
        ListNode *iter = head;
        while(!Q.empty()) {
            int indx = Q.top().second;
            int value = Q.top().first;
            Q.pop();
            iter->next = new ListNode(value);
            if(lists[indx]) {
                Q.push(make_pair(lists[indx]->val, indx));
                lists[indx] = lists[indx]->next;
            }
            iter = iter->next;
        }
        return head->next;
    }
};