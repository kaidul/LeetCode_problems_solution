class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> fruitMap;
        int result = 1;
        for (int left = 0, right = 0; right < (int)tree.size(); right++) {
            fruitMap[tree[right]]++;
            while(left < right and fruitMap.size() > 2) {
                fruitMap[tree[left]]--;
                if (fruitMap[tree[left]] == 0) {
                    fruitMap.erase(tree[left]);
                }
                left++;
            }
            result = max(result, right - left + 1);
        }
        
        return result;
    }
};