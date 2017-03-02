class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector <vector<int> > result;
        size_t n = num.size();
        if(n < 3) return result;

        vector<int> solution(3);
        sort(num.begin(), num.end());
        for(int i = 0; i < n - 2; ++i) {
            int start = i + 1, end = n - 1;

            while(start < end) {
                int sum = num[start] + num[end] + num[i];
                if(sum == 0) {
                    solution.at(0) = num[i];
                    solution.at(1) = num[start];
                    solution.at(2) = num[end];
                    result.push_back(solution);
                    // these loops will skip same elements and fasten the algorithm
                    // while(start < n - 1 and num[start] == num[start + 1]) start++;
                    // while(end > i + 1 and num[end] == num[end - 1]) end--;
                    start++, end--;
                } else if(sum > 0) {
                    // while(end > i + 1 and num[end] == num[end - 1]) end--;
                    end--;
                } else {
                    // while(start < n - 1 and num[start] == num[start + 1]) start++;
                    start++;
                }
            }
            while(i < n - 1 and num[i] == num[i + 1]) i++;
        }

        return result;
    }
};