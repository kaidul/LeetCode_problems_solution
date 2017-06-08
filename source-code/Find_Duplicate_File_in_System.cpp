class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> duplicateMap;
        
        for(string& path: paths) {
            int i = 0, m = (int)path.length();
            while(i < m and path[i] != ' ') {
                i++;
            }
            string pathPrefix = path.substr(0, i);
            
            while(i < m) {
                // skip space
                while(i < m and path[i] == ' ') { i++; }
                
                string fileName;
                while(i < m and path[i] != '(') {
                    fileName += path[i];
                    i++;
                }
                i++;
                
                string fileContent;
                while(i < m and path[i] != ')') {
                    fileContent += path[i];
                    i++;
                }
                i++;
                
                string file = pathPrefix + "/" + fileName;
                duplicateMap[fileContent].push_back(file);
            }
        }
        
        for(auto iter = duplicateMap.begin(); iter != duplicateMap.end(); iter++) {
            if(iter->second.size() > 1) {
                result.push_back(iter->second);    
            }
        }
        
        return result;
    }
};