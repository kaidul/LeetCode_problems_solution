class RandomizedCollection {
    unordered_map<int, set<int> > indices;
    vector<int> values;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        indices = unordered_map<int, set<int> >();
        values = vector<int>();
        srand(time(NULL));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ret = true;
        if(!indices.count(val)) { // indices.find(val) == indices.end() won't work 
            indices[val] = set<int>();
            ret = false;
        }
        indices[val].insert(values.size());
        values.push_back(val);
        return ret;
        
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(!indices.count(val)) {
            return false;
        }
        set<int> pos = indices[val];
        int indx = *pos.begin();
        int lastPos = values.size() - 1;
        int lastVal = values[lastPos];
        
        swap(values[indx], values[lastPos]);
        values.pop_back();
        
        indices[val].erase(indx);
        if(indices[val].size() == 0) {
            indices.erase(val);
        }
        
        if(indices.count(lastVal)) {
            indices[lastVal].erase(lastPos);
            indices[lastVal].insert(indx);
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return values[rand() % (int)values.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */