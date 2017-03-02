class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string result = "";
        if(denominator == 0) return result;
        if(numerator == 0) return "0";
        unordered_map<long, int> appeared;
        
        long q = abs((long)numerator / (long)denominator);
        result += string((numerator < 0) ^ (denominator < 0), '-');
        result += to_string(q);
        long r = abs((long)numerator % (long)denominator);
        if(r == 0) return result;
        result += '.';
        
        while(r) {
            appeared[r] = (int)result.length();
            r *= 10L;
            result += to_string(r / abs((long)denominator));
            r %= abs((long)denominator);
            if(appeared.find(r) != appeared.end()) {
//                string prefix = result.substr(0, appeared[r]);
//                string recur = result.substr(appeared[r]);
//                result = prefix + '(' + recur + ')';

                result.insert(appeared[r], "(");
                result += ')';
                break;
            }
        }
        
        return result;
    }
};