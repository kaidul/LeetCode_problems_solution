// Runtime beats 100% of cpp submissions with huge margin
class Solution {
    class edge {
    public:
        int x;
        int height;
        bool isLeft;
        edge(){}
        edge(int a, int b, bool c):
            x(a), height(b), isLeft(c) {
        }
    };
    
    static bool compare(edge const& lhs, edge const& rhs) {
        if(lhs.x != rhs.x) {
            return lhs.x < rhs.x;
        }
        if(lhs.isLeft and rhs.isLeft) {
            return lhs.height > rhs.height;
        }
        
        if(!lhs.isLeft and !rhs.isLeft) {
            return lhs.height < rhs.height;
        }
        
        return lhs.isLeft;
    }
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;
        if(buildings.empty()) return result;
        int n = (int)buildings.size();
        multiset<int> H;
        vector<edge> edges;
        for(int i = 0; i < n; ++i) {
            edges.push_back(edge(buildings[i][0], buildings[i][2], true));
            edges.push_back(edge(buildings[i][1], buildings[i][2], false));
        }
        sort(edges.begin(), edges.end(), compare);
        
        // solution #1
        /*
        for(int i = 0; i < (int)edges.size(); ++i) {
            if(edges[i].isLeft) {
                if(H.empty() or edges[i].height > *(--H.end())) {
                    result.push_back({edges[i].x, edges[i].height});
                }
                H.insert(edges[i].height);
            } else {
                H.erase(H.find(edges[i].height));
                if(H.empty()) {
                    result.push_back({edges[i].x, 0});
                }
                else if(edges[i].height > *(--H.end())) {
                    result.push_back({edges[i].x, *(--H.end())});
                }
            }
        }
        */
        
        // solution #2
        int prev = 0;
        for(int i = 0; i < (int)edges.size(); ++i) {
            if(edges[i].isLeft) {
                H.insert(edges[i].height);
            } else {
                H.erase(H.find(edges[i].height));
            }
            int curr = (H.empty() ? 0 : *(--H.end()));
            if(curr != prev) {
                result.push_back({edges[i].x, curr});
                prev = curr;
            }
        }
            
        return result;
    }
};