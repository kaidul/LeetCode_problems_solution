// O(logn)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;
        int n = citations.size();
        int hIndx = 0;
        int left = 0, right = n - 1;
        while(left <= right) {
            if(left == right) {
                return min(citations[left], n - left);
            }
            int mid = left + (right - left) / 2;
            if(citations[mid] < n - mid) {
                left = mid + 1;
            } else {
                hIndx = max(hIndx, n - mid);
                right = mid;
            }
        }
        return hIndx;
    }
};
// O(n)
/*
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int hIndx = 0;
        int n = citations.size();
        for(int i = n - 1; i >= 0; --i) {
            if(citations[i] < n - i) break;
            hIndx = max(hIndx, n - i);
        }
        return hIndx;
    }
};
*/