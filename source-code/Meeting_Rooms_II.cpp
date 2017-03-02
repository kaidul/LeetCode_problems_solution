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
    static bool compare(Interval const& a, Interval const& b) {
        return a.start < b.start;
    }
    priority_queue<int, vector<int>, greater<int>> Q;
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int rooms = 0;
        Q.push(intervals[0].end);
        rooms++;
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[i].start < Q.top()) {
                ++rooms;
                Q.push(intervals[i].end);
            } else {
                Q.pop();
                Q.push(intervals[i].end);
            }
        }
        return rooms;
    }
};