class Solution {
public:
    bool checkRecord(string s) {
        int consLate = 0, late = 0, absent = 0;
        for(int i = 0; i < (int)s.length(); i++) {
            if(s[i] == 'A') {
                absent++;
                late = 0;
            } else if(s[i] == 'L') {
                late++;
                consLate = max(consLate, late);
            } else {
                late = 0;
            }
        }
        return consLate <= 2 and absent < 2; 
    }
};