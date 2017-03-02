// backtracking; output limit exceeded
class Solution {
    void readBinaryWatch(int currHour, int currMin, int n, int indx1, vector<int>& hours, int indx2, vector<int>& minutes, vector<string>& result) {
        if(n == 0) {
            string solution = to_string(currHour);
            char minBuffer[2];
            sprintf(minBuffer, "%02d", currMin);
            solution += ":";
            solution += string(minBuffer);
            result.push_back(solution);
            return;
        }
        if(indx2 >= minutes.size()) {
            return;
        }
        for(int i = indx1; i < hours.size(); ++i) {
            if(currHour + hours[i] >= 12) {
                break;
            }
            readBinaryWatch(currHour + hours[i], currMin, n - 1, indx1 + 1, hours, indx2, minutes, result);
        }
        for(int i = indx2; i < minutes.size(); ++i) {
            if(currMin + minutes[i] >= 60) {
                break;
            }
            readBinaryWatch(currHour, currMin + minutes[i], n - 1, indx1, hours, indx2 + 1, minutes, result);
        }
    }
    
public:
    vector<string> readBinaryWatch(int num) {
        vector<int> hours {1, 2, 4, 8};
        vector<int> minutes {1, 2, 4, 8, 16, 32};
        vector<string> result;
        if(num > hours.size() + minutes.size()) {
            return result;    
        }
        readBinaryWatch(0, 0, num, 0, hours, 0, minutes, result);
        
        return result;
    }
};

// bit manipulation; AC
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> result;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (bitset<10>(h << 6 | m).count() == num) {
                    result.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));    
                }
            }
        }
        return result;
    }
};