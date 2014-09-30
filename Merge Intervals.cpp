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
    static bool comparefunc (const Interval& a, const Interval& b) {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> result;
        if(intervals.empty()) return result;
        sort (intervals.begin(), intervals.end(), comparefunc);
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i].start > result.back().end) result.push_back(intervals[i]);
            else result.back().end = max(result.back().end, intervals[i].end);
        }
        return result;
    }
};