/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 // http://zhaohongze.com/wordpress/2013/12/09/leetcode-max-points-on-a-line/
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        //key is slope, value is the number of points in the line of a given slope
        //this map will be reused
        if (points.size() <= 1){
            return points.size();
        }
        unordered_map<double, int> slopePointNumMap;
        int result = 0;
        for (unsigned i = 0; i < points.size(); i++) {
            slopePointNumMap.clear();
 
            Point anchorPoint = points[i];
            int samePointCount = 0;
            int anchorPointMaxSameLinePointCount = 1;
            for (unsigned j = i + 1; j < points.size(); j++) {
                Point currentPoint = points[j];
                int currentPointMaxSameLinePointCount = 0;
                //same point should be count in every line
                if (anchorPoint.x == currentPoint.x && anchorPoint.y == currentPoint.y){
                    samePointCount++;
                } else {//not same point
                    double slope = std::numeric_limits<double>::infinity();
                    if (anchorPoint.x != currentPoint.x){//avoid divide 0 error
                        slope = (double)(anchorPoint.y - currentPoint.y) / (anchorPoint.x - currentPoint.x);
                    }
                    if (slopePointNumMap.find(slope) == slopePointNumMap.end()){//slope first appear
                        slopePointNumMap[slope] = 1;
                    }
                    slopePointNumMap[slope]++;
                    int currentLinePointCount = slopePointNumMap[slope];
                    if (currentLinePointCount > anchorPointMaxSameLinePointCount){
                        anchorPointMaxSameLinePointCount = currentLinePointCount;
                    }
                }
            }
            if (anchorPointMaxSameLinePointCount + samePointCount > result) {
                result = anchorPointMaxSameLinePointCount + samePointCount;
            }
        }
        return result;
    }
};