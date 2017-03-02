class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int result = 0;
        int n = (int)timeSeries.size();
        for(int i = 0; i < n; i++) {
            int start = timeSeries[i];
            int end = start + duration - 1;
            while(i + 1 < n and timeSeries[i + 1] <= end) {
                end = timeSeries[i + 1] + duration - 1;
                i++;
            }
            result += (end - start + 1);
        }
        
        return result;
    }
};