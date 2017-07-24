// dp, 70/74 passed. Don't know why some testcases showing some deviation
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = (int) nums.size();
        if(k > n) { return 0.0; }
        long long sum = 0LL;
        double resultAvg = 0.0;
        for(int i = 0; i < k; i++) {
            sum += nums[i];
        }
        resultAvg = (double)sum / k;
        vector<long long> sumDp(n, 0LL);
        vector<int> countDp(n, 0);
        sumDp[k - 1] = sum;
        countDp[k - 1] = k;
        for(int i = k; i < n; i++) {
            long long sum1 = sumDp[i - 1] + nums[i];
            long long sum2 = sum + nums[i] - nums[i - k];
            double avg1 = (double)sum1 / (countDp[i - 1] + 1);
            double avg2 = (double)sum2 / k;
            if(avg1 - avg2 >= 0.001) {
                sumDp[i] = sum1;
                countDp[i] = countDp[i - 1] + 1;
            } else {
                sumDp[i] = sum2;
                countDp[i] = k;
            }
            resultAvg = max(resultAvg, max(avg1, avg2));
            sum += nums[i];
            sum -= nums[i - k];
        }
        return resultAvg;
    }
};

// AC
class Solution {
    // return true if mid is larger than maximum average
    bool islargerThanAvg(vector<int>& nums, double mid, int k) {
        double sum = 0;
        for(int i = 0; i < k; i++) {
            sum += (nums[i] - mid);
        }
        if(sum >= 0) {
            return false;
        }
        double last = 0;
        for(int i = k; i < nums.size(); i++) {
            sum += (nums[i] - mid);
            last += (nums[i - k] - mid);
            if(last < 0) {
                sum -= last;
                last = 0;
            }
            if (sum >= 0) {
                return false;
            }
        }
        return true; 
    }
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double left = INT_MAX, right = INT_MIN;
        for(int num : nums) { 
            right = max(right, double(num));
            left = min(left, double(num));
        }
        while(right - left > 0.00001) {
            double mid = left + (right - left) / 2;
            if(islargerThanAvg(nums, mid, k)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return left;
    }
};