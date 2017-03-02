class Solution {
public:
    string toHex(int num) {
        // sprintf hack
        /*
        char hex[8];
        sprintf(hex, "%x", num);
        return hex;
        */
        
        string hex = "00000000";
        static const char HEX[] = "0123456789abcdef";
        for(int indx = hex.length() - 1; indx >= 0; --indx) {
            hex[indx] = HEX[(num & 0xF)];
            num >>= 0x04;            
        }
        int offset = 0;
        for(int i = 0; i < hex.length() - 1 and hex[i] == '0'; ++i) {
            ++offset;
        }
        return hex.substr(offset, hex.length() - offset);
    }
};