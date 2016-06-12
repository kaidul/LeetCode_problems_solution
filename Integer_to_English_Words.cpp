class Solution {
    const int billion   = 1000000000;
    const int million   = 1000000;
    const int thousand  = 1000;
    const int hundred   = 100;
    const int ten       = 10;
    
    const string units[4]   = {"Billion", "Million", "Thousand", "Hundred"};
    const string tens[8]    = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const string tens2[10]  = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const string numbers[10]= {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    
    void process(int q, string& result) {
        int q1 = q / hundred;
        int r1 = q % hundred;
        if(q1 > 0) {
            result += numbers[q1];
            result += " ";
            result += units[3];
            result += " ";
        }
        
        if(r1 > 0) {
            int q2 = r1 / ten;
            int r2 = r1 % ten;
            if(q2 > 0) {
                if(q2 == 1) {
                    result += tens2[r2];
                    result += " ";
                } else {
                    result += tens[q2 - 2];
                    result += " ";
                }
            }
            
            if(q2 != 1 and r2 > 0) {
                result += numbers[r2];
                result += " ";
            }
        }
    }
    
public:
    string numberToWords(int num) {
        if(num == 0) return numbers[0];
        
        string result = "";
        int q = num / billion;
        int r = num % billion;
        if(q > 0) {
            process(q, result);
            result += units[0];
            result += " ";
        }
        
        num = r;
        q = num / million;
        r = num % million;
        if(q > 0) {
            process(q, result);
            result += units[1];
            result += " ";
        }
        
        num = r;
        q = num / thousand;
        r = num % thousand;
        if(q > 0) {
            process(q, result);
            result += units[2];
            result += " ";
        }
        
        if(r > 0) {
            process(r, result);
        }
        
        if(result[(int)result.length() - 1] == ' ') {
            result.erase((int)result.length() - 1, 1);
        }
        
        return result;
    }
};