class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        int n = num.size();
        if(n < 4) return result;

        vector <int> solution(4);
        sort(num.begin(), num.end());
        for(int i = 0; i < n - 3; ++i) {
            for(int j = i + 1; j < n - 2; ++j) {
                int start = j + 1, end = n - 1;

                while(start < end) {
                    int sum = num[start] + num[end] + num[i] + num[j];
                    if(sum == target) {
                        solution.at(0) = num[i];
                        solution.at(1) = num[j];
                        solution.at(2) = num[start];
                        solution.at(3) = num[end];
                        result.push_back(solution);
                        while(start > n - 1 and num[start] == num[start + 1])
                            start++;
                        while(end > i + 2 and num[end] == num[end - 1])
                            end--;
                        start++, end--;
                    } else if(sum > target) {
                        while(end > i + 2 and num[end] == num[end - 1])
                            end--;
                        end--;
                    } else if(sum < target) {
                        while(start > n - 1 and num[start] == num[start + 1])
                            start++;
                        start++;
                    }
                }

                while(j < n - 1 and num[j] == num[j + 1]) j++;
            }
            while(i < n - 1 and num[i] == num[i + 1]) i++;
        }
        return result;
    }
};