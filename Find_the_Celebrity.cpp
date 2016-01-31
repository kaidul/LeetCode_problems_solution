// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if (n < 2) {
            return -1;
        }
         
        int left = 0;
        int right = n - 1;
         
        while (left < right) {
            if (knows(left, right)) {
                left++;
            } else {
                right--;
            }
        }
         
        int candidate = right; // or left
        for (int i = 0; i < n; i++) {
            if (i != candidate and (!knows(i, candidate) or knows(candidate, i))) {
                return -1;
            }
        }
         
        return candidate;
    }
};