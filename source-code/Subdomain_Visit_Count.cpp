class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> visitFreq;
        for(string cpDomain : cpdomains) {
            int spacePos = cpDomain.find(" ");
            int noOfVisit = atoi(cpDomain.substr(0, spacePos).c_str());
            string domain = cpDomain.substr(spacePos + 1);
            vector<string> subDomains;
            while(true) {
                subDomains.push_back(domain);
                int dotPos = domain.find(".");
                if(dotPos == string::npos) {
                    dotPos = domain.length();
                    break;
                }
                domain = domain.substr(dotPos + 1);
            }
            for(string subDomain : subDomains) {
                visitFreq[subDomain] += noOfVisit;
            }
        }
        vector<string> result;
        for(auto entry : visitFreq) {
            result.push_back(to_string(entry.second) + " " + entry.first);
        }
        
        return result;
    }
};