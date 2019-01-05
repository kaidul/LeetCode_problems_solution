class Solution {
public:
    int minAddToMakeValid(string S) {
        int balance = 0;
        int parenthesesNeeded = 0;
        for (char parentheses : S) {
            balance += (parentheses == '(') ? +1 : -1;
            if (balance < 0) {
                ++balance;
                ++parenthesesNeeded;
            }
        }
        if (balance > 0) {
            parenthesesNeeded += balance;    
        }
        
        return parenthesesNeeded;
    }
};