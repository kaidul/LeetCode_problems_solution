class Solution {
public:
    void swap(string &str, int idx, int k) {
        for(int i = idx + k; i > idx; --i) {
            char tmp = str[i];
            str[i] = str[i - 1];
            str[i - 1] = tmp;
        }
    }
    void getPermutationUtils(string &str, int idx, int n, int k, int *fact) {
        if (k == 0 or idx == n) return;
        swap(str, idx, k / fact[n - idx - 1]);
        getPermutationUtils(str, idx + 1, n, k % fact[n - idx - 1], fact);
    }
    string getPermutation(int n, int k) {
        string str = "";
        int fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; //n factorail
        for (int i = 1; i <= n; i++) {
            str += char(i + '0');
        }
        getPermutationUtils(str, 0, n, k - 1, fact);
        return str;

    }
};