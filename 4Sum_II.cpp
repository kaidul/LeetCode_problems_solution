class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        int result = 0;
        unordered_map<int,int> sumMap1;
        unordered_map<int,int> sumMap2;
    
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                int sum1 = A[i] + B[j];
                int sum2 = C[i] + D[j];
                sumMap1[sum1]++;
                sumMap2[sum2]++;
            }
        }
        for(auto num1 : sumMap1) {
            int number = num1.first;
            if(sumMap2.find(-1 * number) != sumMap2.end()) {
                result += num1.second * sumMap2[-1 * number];
            }
        }
        return result;
    }
};