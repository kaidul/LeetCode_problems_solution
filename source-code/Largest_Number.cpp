class Solution {
public:
    static bool Compare(int a, int b) {
        string s1 = to_string(a) + to_string(b);
        string s2 = to_string(b) + to_string(a);
        return s1 > s2;
    }
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), Compare);
        int n = num.size();
        if(num[0] == 0) return "0";
        string s;
        for(int i = 0; i < n; i++) {
            s.append( to_string(num[i]) );
        }
        return s;
    }
};