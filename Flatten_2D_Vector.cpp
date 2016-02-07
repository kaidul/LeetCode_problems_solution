class Vector2D {
    vector<int>::iterator iter;
    vector<vector<int>> vec2d;
    int currIndx;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        this->vec2d = vec2d;
        currIndx = 0;
        if(!vec2d.empty()) {
            iter = this->vec2d[currIndx].begin();
        }
    }

    int next() {
        int value = (*iter);
        ++iter;
        return value;
    }

    bool hasNext() {
        while(currIndx < (int) vec2d.size() - 1 and iter == vec2d[currIndx].end()) {
            iter = vec2d[++currIndx].begin();
        }
        return (!vec2d.empty() and iter != vec2d.back().end());
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */