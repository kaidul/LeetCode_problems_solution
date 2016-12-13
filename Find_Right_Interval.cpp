/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
    int lowerBound(int left, int right, unordered_map<int, int>& indxMap, vector<Interval>& intervals) {
        int key = intervals[left - 1].end;
        int indx = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(intervals[mid].start >= key) {
                indx = indxMap[intervals[mid].start];
                right = mid - 1;
            } else {
                left = mid + 1;    
            }
        }
        return indx;
    }
    
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> result(n);
        unordered_map<int, int> indxMap;
        for(int i = 0; i < n; ++i) {
            indxMap[intervals[i].start] = i;
        }
        auto compare = [](Interval const& lhs, Interval const& rhs) {
            return lhs.start < rhs.start;
        };
        sort(intervals.begin(), intervals.end(), compare);
        for(int i = 0; i < n; ++i) {
            result[indxMap[intervals[i].start]] = lowerBound(i + 1, n - 1, indxMap, intervals);
        }
        return result;
    }
};