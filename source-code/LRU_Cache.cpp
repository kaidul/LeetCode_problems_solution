class LRUCache {
public:
    LRUCache(int capacity) {
        LRUCache::capacity = capacity;
        len = 0;
        head = tail = nullptr;
    }

    int get(int key) {
        if (table.find(key) != table.end()) {
            ListNode *node = table[key];
            removeNode(node);
            setHead(node);
            return node->value;
        } else {
            return -1;
        }
    }

    void set(int key, int value) {
        if(table.find(key) != table.end()) {
            ListNode *curr = table[key];
            curr->value = value;
            removeNode(curr);
            setHead(curr);
        } else {
            ListNode *curr = new ListNode(key, value);
            if(len < capacity) {
                setHead(curr);
                table[key] = curr;
                len++;
            } else {
                ListNode *tmp = tail;
                tail = tail->prev;
                if(tail) {
                    tail->next = nullptr;
                }
                table.erase(tmp->key);
                delete tmp;
                setHead(curr);
                table[key] = curr;
            }
        }
    }
private:
    struct ListNode {
        int key, value;
        ListNode *prev, *next;
        ListNode(int key, int value)
            : key(key)
            , value(value)
            , prev(nullptr)
            , next(nullptr) {
        }

    };
    unordered_map<int, ListNode*> table;
    ListNode *head, *tail;
    int capacity;
    int len;
    void removeNode(ListNode *node) {
        if(node->prev) {
            node->prev->next = node->next;
        } else {
            head = node->next;
        }
        if(node->next) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
    }

    void setHead(ListNode *node) {
        node->next = head;
        node->prev = nullptr;
        if(head) {
            head->prev = node;
        }
        head = node;
        if(!tail) {
            tail = node;
        }
    }
};