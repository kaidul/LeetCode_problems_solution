class Solution {
public:
    // http://yucoding.blogspot.com/2013/04/leetcode-question-61-next-permutation.html
    /*
    From the wikipedia, one classic algorithm to generate next permutation is:
        Step 1: Find the largest index k, such that A[k] < A[k + 1]. 
                If not exist, this is the last permutation. (in this problem just reverse the vector and return.)
        Step 2: Find the largest index l, such that A[l] > A[k] and l > k.
        Step 3: Swap A[k] and A[l].
        Step 4: Reverse A[k + 1] to the end.
    */
    void nextPermutation(vector<int> &num) {
        int k = -1;
        int l;
        //step1
        for (int i = num.size() - 1; i > 0; --i) {
            if (num[i - 1] < num[i]) {
                k = i - 1;
                break;
            }
        }
        if (k == -1) {
            reverse(num.begin(), num.end());
            return;
        }

        //step2
        for (int i = num.size() - 1; i > k; --i) {
            if (num[i] > num[k]) {
                l = i;
                break;
            }
        }
        //step3
        int tmp = num[l];
        num[l] = num[k];
        num[k] = tmp;
        //step4
        reverse(num.begin() + k + 1, num.end());
    }
};