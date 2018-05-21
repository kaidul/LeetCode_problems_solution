class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector <int> result;
        unordered_map <int, int> hash;
        for(int i = 0, n = numbers.size(); i < n; ++i) 
            hash[numbers[i]] = i + 1;
        
        for(int i = 0, n = numbers.size(); i < n; ++i) {
            // if(numbers[i] <= target) {
                int indx = hash[target - numbers[i]];
                if(indx > 0 and i + 1 != indx) {
                    result.push_back(i);
                    result.push_back(indx - 1);
                    break;
                }
            // }
        }
        
        return result;
    }
};