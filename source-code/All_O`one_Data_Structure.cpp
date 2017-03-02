class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        freqKeyList = FreqKeyList();
        keyFreqKeyListMap = unordered_map<string, FreqKeyList::iterator> ();
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (keyFreqKeyListMap.find(key) == keyFreqKeyListMap.end()) {
            if (freqKeyList.empty() || freqKeyList.begin()->first != 1) {
                freqKeyList.insert(freqKeyList.begin(), make_pair(1, KeySet()));
            }
            freqKeyList.begin()->second.insert(key);
            keyFreqKeyListMap[key] = freqKeyList.begin();
            return;
        }
        
        FreqKeyList::iterator it = keyFreqKeyListMap[key];
        FreqKeyList::iterator next = it;
        ++next;
        if(next != freqKeyList.end() and next->first == it->first + 1) {
            next->second.insert(key);
        } else {
            next = freqKeyList.insert(next, make_pair(keyFreqKeyListMap[key]->first + 1, KeySet({ key })));    
        }
        keyFreqKeyListMap[key] = next;
        it->second.erase(key);
        if (it->second.empty()) {
            freqKeyList.erase(it);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (keyFreqKeyListMap.find(key) == keyFreqKeyListMap.end()) {
            return;
        }
        FreqKeyList::iterator it = keyFreqKeyListMap[key];
        FreqKeyList::iterator prev = it;
        if (it != freqKeyList.begin()) {
            prev--;
        }
        if (it->first != 1) {
            if (it == freqKeyList.begin() or prev->first != it->first - 1) {
                prev = freqKeyList.insert(it, make_pair(keyFreqKeyListMap[key]->first - 1, KeySet()));
            }
            prev->second.insert(key);
            keyFreqKeyListMap[key] = prev;
        } else {
            keyFreqKeyListMap.erase(key);
        }
        it->second.erase(key);
        if (it->second.empty()) {
            freqKeyList.erase(it);
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return freqKeyList.empty() ? "" : *freqKeyList.rbegin()->second.begin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return freqKeyList.empty() ? "" : *freqKeyList.begin()->second.begin();
    }
private:
    typedef unordered_set<string> KeySet;
    typedef list<pair<int, KeySet>> FreqKeyList;
    FreqKeyList freqKeyList;
    unordered_map<string, FreqKeyList::iterator> keyFreqKeyListMap;
};