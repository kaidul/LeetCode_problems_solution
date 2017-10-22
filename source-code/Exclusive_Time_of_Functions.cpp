class Solution {
    class function {
    public:
        int id;
        int inclusiveTime;
        int startTime;
        int endTime;
        function(int id) {
            this->id = id;
            inclusiveTime = 0;
        }
    };
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int m = (int)logs.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ;
        vector<int> result(n);
        unordered_map<int, int> funcExecTime;
        stack<function> funcStack;
        for(int i = 0; i < m; i++) {
            // parse
            int firstColon = logs[i].find(':');
            int funcId = atoi(logs[i].substr(0, firstColon).c_str());
            int secondColon = logs[i].find(':', firstColon + 1);
            string startOrEnd = logs[i].substr(firstColon + 1, secondColon - firstColon - 1);
            int time = atoi(logs[i].substr(secondColon + 1).c_str());
            
            if(startOrEnd == "start") {
                function curr = function(funcId);
                curr.startTime = time;
                funcStack.push(curr);
            }
            else if(startOrEnd == "end") {
                function curr = funcStack.top();
                curr.endTime = time;
                int totalTime = curr.endTime - curr.startTime + 1;
                int exclusiveTime = totalTime - curr.inclusiveTime;
                funcStack.pop();
                if(!funcStack.empty()) {
                    // caller function
                    funcStack.top().inclusiveTime += totalTime;
                }
                funcExecTime[curr.id] += exclusiveTime;
            }
        }
        for(auto it = funcExecTime.begin(); it != funcExecTime.end(); ++it) {
            pQ.push({it->first, it->second});
        }
        int i = 0;
        while(!pQ.empty()) {
            result[i++] = pQ.top().second;
            pQ.pop();
        }
        return result;
    }
};