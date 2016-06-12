class Solution {
    void countingSort(vector<int>& nums, int exp) {
        int n = (int)nums.size();
        vector<int> cnt(10, 0);
        for(int i = 0; i < n; ++i) {
            cnt[(nums[i] / exp) % 10]++;
        }
        for(int i = 1; i < 10; ++i) {
            cnt[i] += cnt[i - 1];
        }
        vector<int>output(n);
        for(int i = n - 1; i >= 0; --i) {
            int indx = (nums[i] / exp) % 10;
            output[cnt[indx] - 1] = nums[i];
            cnt[indx]--;
        }
        swap(nums, output);
    }
    
    void radixSort(vector<int>& nums) {
        if(nums.empty()) return;
        int Max = *max_element(nums.begin(), nums.end());
        
        for(int exp = 1; Max / exp > 0; exp *= 10) {
            countingSort(nums, exp);
        }
    }
    
public:
    int maximumGap(vector<int>& nums) {
        int result = 0;
        // sort(nums.begin(), nums.end()); // O(nlogn)
        radixSort(nums); // O(n)
        for(int i = 1; i < (int)nums.size(); ++i) {
            result = max(result, nums[i] - nums[i - 1]);
        }
        return result;
    }
};

// bucket sort (faster)
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int result = 0;
        if(nums.empty()) return result;
        int n = (int)nums.size();
        
        // bucket sort
        int Min = nums[0], Max = nums[0];
        for(int i = 1; i < n; ++i) {
            if(nums[i] > Max) {
                Max = nums[i];
            }
            if(nums[i] < Min) {
                Min = nums[i];
            }
        }
        int range = Max - Min;
        if(range <= 1) {
            return range;
        }
        vector<int>bucketMax(n, INT_MIN), bucketMin(n, INT_MAX);
        for(int i = 0; i < n; ++i) {
            int indx = 1.0 * (nums[i] - Min) / range * (n - 1);
            bucketMax[indx] = max(bucketMax[indx], nums[i]);
            bucketMin[indx] = min(bucketMin[indx], nums[i]);
        }
        
        int prevMax = bucketMax[0];
        for(int i = 1; i < n; ++i) {
            if(bucketMax[i] != INT_MIN) {
                result = max(result, bucketMin[i] - prevMax);
                prevMax = bucketMax[i];
            }
        }
        return result;
    }
};