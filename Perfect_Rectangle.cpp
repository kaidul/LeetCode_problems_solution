class Solution {
    
    bool insert(int x, int y, int pos, unordered_map<int, unordered_map<int, int> >& edgeMap) {
        int& mask = edgeMap[x][y];
        if(mask & pos) {
            return false;
        }
        mask |= pos;
        return true;
    }
    
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<int, unordered_map<int, int> > edgeMap;
        int top = INT_MAX, left = INT_MAX, bottom = INT_MIN, right = INT_MIN;
        
        for(int i = 0; i < rectangles.size(); i++) {
            int x1 = rectangles[i][0], y1 = rectangles[i][1];
            int x2 = rectangles[i][2], y2 = rectangles[i][3];
            top = min(top, x1);
            left = min(left, y1);
            bottom = max(bottom, x2);
            right = max(right, y2);
        
            if(!insert(x1, y1, 1, edgeMap)) {
                return false;
            }
            if(!insert(x1, y2, 2, edgeMap)) {
                return false;
            }
            if(!insert(x2, y1, 4, edgeMap)) {
                return false;
            }
            if(!insert(x2, y2, 8, edgeMap)) {
                return false;
            }
        }

        bool interior[16] = {false};
        interior[3] = interior[5] = interior[10] = interior[12] = interior[15] = true;
        
        for(auto it = edgeMap.begin(); it != edgeMap.end(); ++it) {
            int x = it->first;
            for(auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
                int y = it2->first;
                int mask = it2->second;
                if( ((x != top and x != bottom) or (y != left and y != right)) and !interior[mask] ) {
                    return false;
                }
            }
        }
        return true;
    }
};