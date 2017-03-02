class TwoSum {
    unordered_map<int, int> hash;
public:
 
     // Add the number to an internal data structure.
     void add(int number) {
         hash[number]++;
     }
     
     // Find if there exists any pair of numbers which sum is equal to the value.
     bool find(int value) {
         for(auto h: hash) {
             int u = h.first, v = value - u;
             if(u == v) {
                 if(h.second > 1) return true;
             } else {
                 if(hash.count(v) > 0) return true;
             }
         }
         return false;
     }
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);