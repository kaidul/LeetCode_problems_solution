class Solution {
public:
    string intToRoman(int num) {
        const pair<int, string> intToRoman[] = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        string result;
        for(int i = 0, n = sizeof(intToRoman) / sizeof(intToRoman[0]); i < n; ++i) {
            while(intToRoman[i].first <= num) {
                result += intToRoman[i].second;
                num -= intToRoman[i].first;
            }
        }
        return result;
    }
};