class Solution {
public:
 
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        vector<Interval>::iterator it;
        for (it = intervals.begin(); it != intervals.end(); it++) {
            if(newInterval.start < (*it).start) {
                intervals.insert(it, newInterval);
                break;
            }
        }    
        if (it == intervals.end()) { 
            intervals.insert(it, newInterval);
        }
         
         
        if (intervals.empty()) return result;
           
        result.push_back(*intervals.begin());
        for (it = intervals.begin() + 1; it != intervals.end(); it++) {
            if ((*it).start > result.back().end) result.push_back(*it);
            else result.back().end = max(result.back().end, (*it).end);
        }
        return result;
    }
};