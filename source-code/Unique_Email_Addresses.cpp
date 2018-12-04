class Solution {
    string normalizeEmail(string const& email) {
        int at = email.find('@');
        string localName = email.substr(0, at);
        string domainName = email.substr(at + 1);
        string modifiedLocalName = "";
        for (int i = 0; i < (int)localName.length() and localName[i] != '+'; i++) {
            if (localName[i] == '.') {
                continue;
            }
            modifiedLocalName += localName[i];
        }
        
        return modifiedLocalName + "@" + domainName;
    }
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniqueEmailSet;
        for (string const& email : emails) {
            string normalizedEmail = normalizeEmail(email);
            uniqueEmailSet.insert(normalizedEmail);
        }
        
        return (int) uniqueEmailSet.size();
    }
};