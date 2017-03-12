class Solution {
    int getMinute(string& timePoint) {
        int colon = timePoint.find(':');
        assert(colon != string::npos);
        int hour = atoi(timePoint.substr(0, colon).c_str());
        int minute = atoi(timePoint.substr(colon + 1).c_str());
        minute += (hour * 60);
        return minute;
    }
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = (int)timePoints.size();
        vector<int> minutes(n);
        for(int i = 0; i < n; i++) {
            minutes[i] = getMinute(timePoints[i]);
        }
        sort(minutes.begin(), minutes.end());
        int result = INT_MAX;
        for(int i = 0; i < n - 1; i++) {
            int diff = minutes[i + 1] - minutes[i];
            result = min(result, min(diff, 1440 - diff));
        }
        int diff = minutes[n - 1] - minutes[0];
        result = min(result, min(diff, 1440 - diff));
        return result;
    }
};