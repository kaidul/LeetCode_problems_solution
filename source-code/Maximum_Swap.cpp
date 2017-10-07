class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.length();
        vector<int> rMax(n, 0);
        rMax[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; i--) {
            rMax[i] = rMax[i + 1];
            if(s[i] > s[rMax[i + 1]]) {
                rMax[i] = i;
            }
        }
        for(int i = 0; i < s.length() - 1; i++) {
            if(s[i] < s[rMax[i + 1]]) {
                swap(s[i], s[rMax[i + 1]]);
                break;
            }
        }
        return atoi(s.c_str());
    }
};