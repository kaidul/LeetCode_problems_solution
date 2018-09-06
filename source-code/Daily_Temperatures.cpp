class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        stack<int> indexStack;
        indexStack.push(0);
        for(int i = 1; i < n; i++) {
            if(temperatures[i] > temperatures[i - 1]) {
                while(!indexStack.empty() and temperatures[indexStack.top()] < temperatures[i]) {
                    int indx = indexStack.top();
                    result[indx] = i - indx;
                    indexStack.pop();
                }
            }
            indexStack.push(i);
        }
        while(!indexStack.empty()) {
            int indx = indexStack.top();
            result[indx] = 0;
            indexStack.pop();
        }
        
        return result;
    }
};