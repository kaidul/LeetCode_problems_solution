class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k <= 0) return num;
        int n = num.length();
        stack<int> indx;
        indx.push(0);
        int i = 1;
        while(i < n and k > 0) {
            if(indx.empty()) {
                indx.push(i);
                i++;
            }
            while(i < n and num[i] >= num[indx.top()]) {
                indx.push(i);
                i++;
            }
            num[indx.top()] = '#';
            indx.pop();
            k--;
        }
        while(k > 0) {
            num[indx.top()] = '#';
            indx.pop();
            k--;
        }
        string result;
        for(i = 0; i < n and !(num[i] > '0' and num[i] <= '9'); ++i);
        for(; i < n; ++i) {
            if(num[i] != '#') {
                result += num[i];
            }
        }
        if(result.empty()) result = "0";
        return result;
    }
};