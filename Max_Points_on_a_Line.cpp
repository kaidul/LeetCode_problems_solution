/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        //key is slope, value is the number of points in the line of a given slope
        //this map will be reused
        if (points.size() <= 1) {
            return points.size();
        }

        unordered_map<double, int> Map;
        int result = 0;
        
        for (unsigned i = 0; i < points.size(); i++) {
            Map.clear();
            Point anchorPoint = points[i];
            int samePointCount = 0;
            int Max = 1;
            
            for (unsigned j = i + 1; j < points.size(); j++) {
                Point currentPoint = points[j];
                //same point should be count in every line
                if (anchorPoint.x == currentPoint.x && anchorPoint.y == currentPoint.y) {
                    // slop 0
                    samePointCount++;
                } else {//not same point
                    double slope = std::numeric_limits<double>::infinity();
                    if (anchorPoint.x != currentPoint.x) { //avoid divide 0 error
                        slope = (double)(anchorPoint.y - currentPoint.y) / (anchorPoint.x - currentPoint.x);
                    }
                    if (Map.find(slope) == Map.end()) { //slope first appear
                        Map[slope] = 1;
                    }
                    Map[slope]++;
                    Max = max(Max, Map[slope]);
                }
            }

            int curr = Max + samePointCount;
            result = max(result, curr);
        }
        return result;
    }
};