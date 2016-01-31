// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersionSearch(int left, int right) {
        if(left >= right) {
            return left;
        }
        int mid = left + (right - left) / 2;
        if(isBadVersion(mid)) {
            return firstBadVersionSearch(left, mid);
        } else {
            return firstBadVersionSearch(mid + 1, right);
        }
    }
    int firstBadVersion(int n) {
        return firstBadVersionSearch(1, n);
    }
};