class LFUCache {
private:
    struct ListNode {
        int key;
        int value;
        ListNode* prev;
        ListNode* next;
        ListNode(int _key, int _value):
            key(_key),
            value(_value),
            prev(nullptr),
            next(nullptr) {
        }
    };

    class Chain {
    public:
        int freq;
        ListNode* head;
        ListNode* tail;
        Chain* prev;
        Chain* next;
        Chain(): freq(0), prev(nullptr), next(nullptr) {
            head = nullptr;
            tail = nullptr;
        }

        Chain(Chain* _prev) {
            freq = _prev->freq + 1;
            prev = _prev;
            next = _prev->next;
            if(_prev->next) {
                _prev->next->prev = this;
            }
            _prev->next = this;
            head = nullptr;
            tail = nullptr;
        }
    };

    Chain* head;

    void removeChain(Chain* chain) {
        if(chain->prev) {
            chain->prev->next = chain->next;
        } else {
            head = chain->next;
        }
        if(chain->next) {
            chain->next->prev = chain->prev;
        }
        delete chain;
    }

    void removeNode(int key) {
        Chain* chain = Map[key].first;
        ListNode* node = Map[key].second;
        Map.erase(key);
        
        if(node->prev) {
            node->prev->next = node->next;
        } else {
            chain->head = node->next;
        }
        if(node->next) {
            node->next->prev = node->prev;
        } else {
            chain->tail = node->prev;
        }
        delete node;
    }
    
    Chain* updateChain(Chain* chain) {
        if(!chain->next or chain->next->freq > chain->freq + 1) {
            chain->next = new Chain(chain);
        }
        Chain* newChain = chain->next;

        if(!chain->head and !chain->tail) {
            removeChain(chain);
        }

        return newChain;
    }

    void setHead(Chain* chain, ListNode* node) {
        Map[node->key] = {chain, node};
        node->next = chain->head;
        node->prev= nullptr;
        if(chain->head) {
            chain->head->prev = node;
        }
        chain->head = node;
        if(!chain->tail) {
            chain->tail = node;
        }
    }

    int capacity;
    int currLen;

    unordered_map<int, pair<Chain*, ListNode*> > Map;

public:

    LFUCache(int capacity) {
        this->capacity = capacity;
        head = new Chain();
        Map = unordered_map<int, pair<Chain*, ListNode*> >();
        currLen = 0;
    }

    int get(int key) {
        if(Map.find(key) == Map.end()) {
            return -1;
        }
        Chain* chain = Map[key].first;
        ListNode* node = Map[key].second;
        int value = node->value;
        removeNode(key);
        Chain* newChain = updateChain(chain);
        ListNode* newNode = new ListNode(key, value);
        setHead(newChain, newNode);

        return value;
    }

    void put(int key, int value) {

        if(capacity == 0) {
            return;
        }

        ListNode* newNode = new ListNode(key, value);
        
        if(Map.find(key) != Map.end()) {
            Chain* chain = Map[key].first;
            removeNode(key);
            Chain* newChain = updateChain(chain);
            setHead(newChain, newNode);
            return;
        }

        if(currLen == capacity) {
            Chain* chain = head;
            ListNode* node = chain->tail;
            removeNode(node->key);
            updateChain(chain);
            currLen--;
        }
        if(head->freq > 0) {
            Chain* newHead = new Chain();
            newHead->next = head;
            head->prev = newHead;
            head = newHead;
        }
        setHead(head, newNode);

        currLen++;
    }
};