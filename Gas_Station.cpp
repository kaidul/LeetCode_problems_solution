class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = (int) gas.size();
        for(int i = 0; i < n; ++i) {
            bool flag = true;
            for(int j = i, tank = 0; j < n + i and flag; ++j) {
                int idx = j % n;
                tank += gas[idx];
                tank -= cost[idx];
                if(tank < 0) {
                    flag = false;
                }
            }
            if(flag) return j;
        }
        return -1;
    }
};