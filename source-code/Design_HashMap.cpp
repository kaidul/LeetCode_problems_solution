class MyHashMap {
    int[] entry;

    /** Initialize your data structure here. */
    public MyHashMap() {
        entry = new int[1000001];
        for(int i = 0; i < entry.length; i++) {
            entry[i] = -1;
        }
    }
    
    /** value will always be non-negative. */
    public void put(int key, int value) {
        entry[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    public int get(int key) {
        return entry[key];
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    public void remove(int key) {
        entry[key] = -1;
    }
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */