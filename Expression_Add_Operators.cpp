class Solution {
public:
    void addOperatorsUtil(string num, int target, long long diff, long long currValue, string solution, vector<string>& result) {
        if(num.length() == 0 and target == currValue) {
            result.push_back(solution);
        }
        for(int i = 1; i <= num.length(); ++i) {
            string curr = num.substr(0, i);
            if(curr.length() > 1 and curr[0] == '0') {
                break;
            }
            string next = num.substr(i);
            if(solution.length() > 0) {
                addOperatorsUtil(next, target, stoll(curr), currValue + stoll(curr), solution + '+' + curr, result);
                addOperatorsUtil(next, target, -stoll(curr), currValue - stoll(curr), solution + '-' + curr, result);
                addOperatorsUtil(next, target, diff * stoll(curr), (currValue  - diff) + diff * stoll(curr), solution + '*' + curr, result);
            } else {
                addOperatorsUtil(next, target, stoll(curr), currValue + stoll(curr), curr, result);
            }   
        }
    }
    
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string solution;
        addOperatorsUtil(num, target, 0LL, 0LL, solution, result);
        return result;
    }
};