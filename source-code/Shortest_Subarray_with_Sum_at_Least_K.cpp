class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = (int) A.size();
        vector<int> cumSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cumSum[i] = A[i - 1] + cumSum[i - 1];
        }
        int minLength = INT_MAX;
        deque<int> dQ;
        for (int i = 0; i <= n; i++) {
            while (!dQ.empty() and cumSum[i] <= cumSum[dQ.back()]) {
                dQ.pop_back();
            }
            while (!dQ.empty() and cumSum[i] >= K + cumSum[dQ.front()]) {
                minLength = min(minLength, i - dQ.front());
                dQ.pop_front();
            }
            dQ.push_back(i);
        }
        
        return minLength != INT_MAX ? minLength : -1;
    }
};

// 82/93 test case passed, TLE solution
class Solution {
    int lowerBound(int left, int right, int const low, vector<int> const& cumSum, int const K) {
        if (left > right) {
            return INT_MAX;
        }
        int mid = left + (right - left) / 2;
        if (cumSum[mid] - cumSum[low - 1] >= K) {
            return min(mid - low + 1, lowerBound(left, mid - 1, low, cumSum, K));
        }
        int leftResult = lowerBound(left, mid - 1, low, cumSum, K);
        if (leftResult != INT_MAX) {
            return leftResult;
        }
        return min(leftResult, lowerBound(mid + 1, right, low, cumSum, K));
    }
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = (int) A.size();
        vector<int> cumSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cumSum[i] = A[i - 1] + cumSum[i - 1];
        }
        int length = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int left = i, right = n;
            length = min(length, lowerBound(left, right, i, cumSum, K));
        }
        
        return length != INT_MAX ? length : -1;
    }
};