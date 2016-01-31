class Solution {
public:
    // http://en.wikipedia.org/wiki/3SUM
    int threeSumClosest(vector<int> &num, int target) {
        if(num.empty()) return 0;
        
        sort(num.begin(), num.end());
        int min= INT_MAX; // int min = numeric_limit<int>::max();
        int record;
        
        for(int i = 0, n = num.size(); i < n - 2; i++) {

            int start = i + 1, end = n - 1;

            while(start < end) {
                int sum = num[start] + num[end] + num[i];
                if(sum == target) {
                    min = 0;
                    record = sum;
                    break;
                } else if(sum > target) {
                    if(sum - target < min) {
                        min = sum - target;
                        record = sum;
                    }
                    end--;
                } else if(sum < target) {
                    if(target - sum < min) {
                        min = target - sum;
                        record = sum;
                    }
                    start++;
                }
                while(i < num.size() - 1 and num[i] == num[i + 1]) 
                    i++;
            }

        }
        return record;
        
    }
};