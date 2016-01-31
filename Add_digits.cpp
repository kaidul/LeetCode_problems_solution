class Solution {
public:
    int addDigits(int num) {
        /*
        while(true) {
            int backup = num;
            int sum = 0;
            while(num > 0) {
                sum += (num % 10);
                num /= 10;
            }
            num = backup;
            if(num == sum) {
                return num;
            }
            num = sum;
        }
        return num;
        */
        if(num == 0) return num;
        int mod = num % 9;
        return (mod != 0) ? mod : 9;
    }
};