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
    static bool compare(Interval const& a, Interval const& b) {
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        for(int i = 0; i < (int) intervals.size() - 1; ++i) {
            if(intervals[i].end > intervals[i + 1].start) {
                return false;
            }
        }
        return true;
    }
};