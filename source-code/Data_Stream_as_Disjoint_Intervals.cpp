/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
    class Compare {
    public:
        bool operator()(Interval const& lhs, Interval const& rhs) {
            if(lhs.start == rhs.start) {
                return lhs.end < rhs.end;
            }
            return lhs.start < rhs.start;
        }
    };
    set<Interval, Compare> intervalSet;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        intervalSet = set<Interval, Compare>();
    }
    
    void addNum(int val) {
        set<Interval>::iterator iter = (intervalSet.insert(Interval(val, val))).first;
        while(iter != intervalSet.begin() and iter->start == val) {
            --iter;
        }
        set<Interval>::iterator nxt = iter;
        ++nxt;
        int start = val, end = val;
        if(nxt != intervalSet.end() and iter->end + 1 >= nxt->start) {
            start = iter->start;
            end = max(iter->end, nxt->end);
            intervalSet.erase(iter);
            intervalSet.erase(nxt);
            intervalSet.insert(Interval(start, end));
        }
        
        iter = intervalSet.find(Interval(start, end));
        nxt = iter; ++nxt;
        while(nxt != intervalSet.end() and iter->end + 1 >= nxt->start) {
            start = iter->start;
            end = max(iter->end, nxt->end);
            nxt = intervalSet.erase(iter);
            nxt = intervalSet.erase(nxt);
            intervalSet.insert(Interval(start, end));
            iter = intervalSet.find(Interval(start, end));
            nxt = iter; ++nxt;
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> result(intervalSet.size());
        copy(intervalSet.begin(), intervalSet.end(), result.begin());
        return result;
    }
};
/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */