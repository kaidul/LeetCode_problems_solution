class Solution {
public:
    bool isValidSerializationRecur(int& currPos, int& nextTokenPos, string const& preorder) {
        
        if(nextTokenPos >= preorder.length()) {
            return false;
        }
        
        currPos = nextTokenPos;
        int commaPos = preorder.find(',', currPos);
        if(commaPos == string::npos) {
            commaPos = preorder.length();
        }
        string token = preorder.substr(currPos, commaPos - currPos);
        nextTokenPos = commaPos + 1;
        
        if(token == "#") {
            return true;
        }
        
        bool isLeftValid = isValidSerializationRecur(currPos, nextTokenPos, preorder);
        bool isRightValid = isValidSerializationRecur(currPos, nextTokenPos, preorder);
        
        return (isLeftValid and isRightValid);
    }
    
    bool isValidSerialization(string preorder) {
        if(preorder.empty()) return true;
        int indx = 0;
        int nextPos = 0;
        bool isValid = isValidSerializationRecur(indx, nextPos, preorder);
        return (isValid and indx == preorder.length() - 1);
    }
};