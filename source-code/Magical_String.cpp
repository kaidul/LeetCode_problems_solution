class Solution {
public:
    int magicalString(int n) {
        string result = "122";
        int i = 2;
        while (result.length() < n) {
            result += string(result[i++] - '0', result.back() ^ 3);
        }
        return count(result.begin(), result.begin() + n, '1');
    }
};