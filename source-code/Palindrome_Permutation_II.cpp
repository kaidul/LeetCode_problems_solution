class Solution {
#define MAX 256

    void generatePalindromesImpl(int left, int right, vector<int>& freq, string& solution, vector<string>& result) {
        if(left > right) {
            result.push_back(solution);
            return;
        }
        for(int i = 0; i < MAX; ++i) {
            if(freq[i] >= 2) {
                solution[left] = solution[right] = (char)i;
                freq[i] -= 2;
                generatePalindromesImpl(left + 1, right - 1, freq, solution, result);
                freq[i] += 2;
            } else if(freq[i] == 1 and left == right) {
                // freq[i]--;
                solution[left] = (char)i;
                generatePalindromesImpl(left + 1, right - 1, freq, solution, result);
                // freq[i]++;
            }
        }
    }
    
public:
    vector<string> generatePalindromes(string s) {
        vector<string> result;
        int n = s.length();
        vector<int> freq(MAX, 0);
        for(int i = 0; i < n; ++i) {
            freq[s[i]]++;
        }
        int oddParity = 0;
        for(int i = 0; i < MAX; ++i) {
            if(freq[i] & 1) {
                oddParity++;
            }
        }
        if(n & 1) {
            if(oddParity != 1) {
                return result;
            }
        } else {
            if(oddParity > 0) {
                return result;    
            }
        }

        string solution = s;
        generatePalindromesImpl(0, n - 1, freq, solution, result);
        return result;
    }
};