class Solution {
    
    bool valid(long target, vector<int>& arr, int m) {
        int cnt = 1;
        long long total = 0LL;
        for(int i = 0; i < arr.size(); i++) {
            total += arr[i];
            if(total > target) {
                total = arr[i];
                cnt++;
                if(cnt > m) {
                    return false;
                }
            }
        }
        return true;
    }
    
    // more efficient, utilize cumulative sum
    bool valid2(long long target, vector<long long>& sums, int m) {
        int count = 0, start = 1, end = (int)sums.size();
        while (start < end) {
            int left = start, right = end, mid = 0;
            while (left <= right) {
                mid = left + (right - left) / 2;
                if (sums[mid] - sums[start - 1] <= target) {
                    left = mid + 1;  
                } else {
                    right = mid - 1;
                }
            }
            
            if (++count > m) {
                return false;
            }
            
            start = left;
        }
        return true;
    };
    
public:
    int splitArray(vector<int>& arr, int m) {
        int maxi = 0;
        int n = (int)arr.size();
        vector<long long> sums(n + 1, 0LL);
        
        for(int i = 0; i < n; i++) {
            maxi = max(maxi, arr[i]);
            sums[i + 1] = sums[i] + arr[i];
        }
        
        if(m == 1) return (int)sums[n];
        if(m == arr.size()) return maxi;
        
        long long left = maxi, right = sums[n];
        while(left <= right) {
            long long mid = left + (right - left) / 2LL;
            if(valid2(mid, sums, m)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return (int)left;
    }
};