class Solution {
    void restoreIpAddressesRecur(int indx, int cnt, string const& s, string& ipAddr, vector<string>& result) {
        if(indx >= s.length()) {
            return;
        } 
        if(cnt == 3) {
            if(indx < s.length() - 1 and s[indx] == '0') {
                return;
            }
            string octet = s.substr(indx);
            if(octet.length() > 3) {
                return;
            }
            int iOctet = stoi(octet);
            if(iOctet >= 0 and iOctet <= 255) {
                ipAddr += octet;
                result.push_back(ipAddr);
                ipAddr.erase(ipAddr.length() - octet.length(), octet.length());
            }
            return;
        }
        int maxLen = min((int) s.length(), indx + 3);
        if(s[indx] == '0') {
            maxLen = indx + 1;
        }
        for(int len = indx + 1; len <= maxLen; ++len) {
            string octet = s.substr(indx, len - indx);
            int iOctet = stoi(octet);
            if(iOctet >= 0 and iOctet <= 255) {
                ipAddr += octet;
                ipAddr += '.';
                restoreIpAddressesRecur(len, cnt + 1, s, ipAddr, result);
                ipAddr.erase(ipAddr.length() - octet.length() - 1, octet.length() + 1);
            }
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int len = s.length();
        if(len < 4 or len > 12) {
            return result;
        }
        string ipAddr;
        ipAddr.reserve(len + 4);
        restoreIpAddressesRecur(0, 0, s, ipAddr, result);
        return result;
    }
};