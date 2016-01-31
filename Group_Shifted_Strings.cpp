class Solution {
public:
    string getHash(string key) {
        string hash = "#";
        for(int i = 1; i < key.length(); ++i) {
            int diff = ((key[i] - key[i  -1]) + 26) % 26;
            hash += to_string(diff);
            hash += '#';
        }
        return hash;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> result;
        unordered_map <string, vector<string>> hashMap;
        for(string s: strings) {
            string key = getHash(s);
            if(hashMap.find(key) != hashMap.end()) {
                hashMap[key].push_back(s);
            } else {
                vector<string> grp{s};
                hashMap[key] = grp;
            }
        }
        for(auto it = hashMap.begin(); it != hashMap.end(); ++it) {
            sort(it->second.begin(), it->second.end());
            result.push_back(it->second);
        }
        return result;
    }
};