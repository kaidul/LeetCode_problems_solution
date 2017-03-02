class RandomizedSet {
    unordered_map<int, int> indices; //index->value
    vector<int> values; // value->index
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        indices = unordered_map<int, int>();
        values = vector<int>();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(indices.find(val) != indices.end()) {
            return false;
        }
        indices[val] = values.size();
        values.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(indices.find(val) == indices.end()) {
            return false;
        }
        int indx = indices[val];
        if(indx != values.size() - 1) {
            values[indx] = values[values.size() - 1];
            indices[values[indx]] = indx;
        }
        values.pop_back();
        indices.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return values[rand() % (int)values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */