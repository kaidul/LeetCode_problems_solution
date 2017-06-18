// round robin
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> taskFreq;
        for (char task : tasks) {
            taskFreq[task]++;
        }
        priority_queue<pair<int, char>> pQ;
        for (pair<char, int> taskCount : taskFreq) {
            pQ.push({taskCount.second, taskCount.first});
        }
        int interval = 0;
        int cycle = n + 1;
        while(!pQ.empty()) {
            int tasks = 0;
            vector<pair<int, char>> tmp;
            for(int i = 0; i < cycle; i++) {
                if(!pQ.empty()) {
                    tmp.push_back(pQ.top());
                    pQ.pop();
                    tasks++;
                }
            }
            for(auto task : tmp) {
                if(--task.first) {
                    pQ.push(task);
                }
            }
            interval += !pQ.empty() ? cycle : tasks;
        }
        return interval;
        
    }
};