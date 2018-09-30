class Solution {
public:
    void shift(string& permutation, int idx, int k) {
        for(int i = idx + k - 1; i >= idx; --i) {
            swap(permutation[i], permutation[i + 1]);
        }
    }

    void getPermutationUtils(string& permutation, int idx, int k, vector<int>& fact) {
        int n = (int) permutation.length();
        if (k == 0 or idx == n) return;
        shift(permutation, idx, k / fact[n - idx - 1]);
        getPermutationUtils(permutation, idx + 1, k % fact[n - idx - 1], fact);
    }
    
    string getPermutation(int n, int k) {
        string permutation = "";
        vector<int> fact{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; //n factorial
        for (int i = 1; i <= n; i++) {
            permutation += char(i + '0');
        }
        getPermutationUtils(permutation, 0, k - 1, fact);
        return permutation;

    }
};