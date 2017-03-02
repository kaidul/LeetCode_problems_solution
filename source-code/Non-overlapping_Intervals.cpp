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
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        auto compare = [](Interval const& lhs, Interval const& rhs) {
            return lhs.end < rhs.end;
        };
        sort(intervals.begin(), intervals.end(), compare);
        int result = 0;
        if(intervals.empty()) return result;
        int currRight = intervals[0].end;
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i].start < currRight) {
                ++result;
                continue;
            }
            currRight = intervals[i].end;
        }
        return result;
    }
};