// there are at most 4 * 4 * 4b* 4 = 256 possible times only. So lets try them all
class Solution {
    void search(int indx, vector<int>& digits, string curr, string& result, int& diff, int const target) {
        if(indx == 4) {
            int total = atoi(curr.substr(0, 2).c_str()) * 60 + atoi(curr.substr(2).c_str());
            if(total == target) {
                return;
            }
            int currDiff = total - target > 0 ? total - target : 1440 + total - target;
            if(currDiff < diff) {
                diff = currDiff;
                result = curr.substr(0, 2) + ":" + curr.substr(2);
            }
            return;
        }
        for(int i = 0; i < digits.size(); i++) {
            if(indx == 0 and digits[i] > 2) { continue; }
            if(indx == 1 and atoi(curr.c_str()) * 10 + digits[i] > 23) { continue; }
            if(indx == 2 and digits[i] > 5) { continue; }
            if(indx == 3 and atoi(curr.substr(2).c_str()) * 10 + digits[i] > 59) { continue; }
            
            search(indx + 1, digits, curr + to_string(digits[i]), result, diff, target);
        }
    }
public:
    string nextClosestTime(string time) {
        vector<int> digits;
        unordered_set<int> digitSet;
        digitSet.insert(atoi(time.substr(0, 1).c_str()));
        digitSet.insert(atoi(time.substr(1, 1).c_str()));
        digitSet.insert(atoi(time.substr(3, 1).c_str()));
        digitSet.insert(atoi(time.substr(4).c_str()));
        if(digitSet.size() == 1) {
            return time;
        }
        for(auto it = digitSet.begin(); it != digitSet.end(); ++it) {
            digits.push_back(*it);
        }
        string result = "";
        int target = atoi(time.substr(0, 2).c_str()) * 60 + atoi(time.substr(3).c_str());
        int diff = INT_MAX;
        search(0, digits, "", result, diff, target);
        
        return result;
    }
};