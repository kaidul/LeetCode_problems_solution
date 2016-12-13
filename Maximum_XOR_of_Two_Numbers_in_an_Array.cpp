// Trie solution TLE !! The world is becomming more brutal
public class Solution {
    class Trie {
        Trie[] children;
        public Trie() {
            children = new Trie[2];
        }
    }
    
    public int findMaximumXOR(int[] nums) {
        if(nums == null || nums.length == 0) {
            return 0;
        }
        // Init Trie.
        Trie root = new Trie();
        for(int num: nums) {
            Trie curNode = root;
            for(int i = 31; i >= 0; i --) {
                int curBit = (num >>> i) & 1;
                if(curNode.children[curBit] == null) {
                    curNode.children[curBit] = new Trie();
                }
                curNode = curNode.children[curBit];
            }
        }
        int max = Integer.MIN_VALUE;
        for(int num: nums) {
            Trie curNode = root;
            int curSum = 0;
            for(int i = 31; i >= 0; i --) {
                int curBit = (num >>> i) & 1;
                if(curNode.children[curBit ^ 1] != null) {
                    curSum += (1 << i);
                    curNode = curNode.children[curBit ^ 1];
                }else {
                    curNode = curNode.children[curBit];
                }
            }
            max = Math.max(curSum, max);
        }
        return max;
    }
}

// AC O(nlog k)
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        if(n < 2) {
            return result;
        }
        int mask = 0;
        const int MSB = 30;
        for(int i = MSB; i >= 0; --i) {
            mask |= (1 << i);
            unordered_set<int> prefixes;
            for(int k = 0; k < n; ++k) {
                prefixes.insert(nums[k] & mask);
            }
            int curr = result | (1 << i);
            for(auto elem: prefixes) {
                if(prefixes.find((int)elem ^ curr) != prefixes.end()) {
                    result = curr;
                    break;
                }
            }
        }
        return result;
    }
};