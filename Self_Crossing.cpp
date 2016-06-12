class Solution {
	struct Point {
		int x;
		int y;
		Point() {}
		Point(int a, int b): x(a), y(b) {
		}
	};
	
	bool onSegment(Point p, Point q, Point r) {
		if (q.x <= max(p.x, r.x) and q.x >= min(p.x, r.x) and q.y <= max(p.y, r.y) and q.y >= min(p.y, r.y))
			return true;
		
		return false;
	}
 
	int orientation(Point p, Point q, Point r) {
		int val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);
		
		if (val == 0) return 0;
		
		return (val > 0)? 1: 2;
	}
 
	bool doIntersect(Point p1, Point q1, Point p2, Point q2)
	{
		int o1 = orientation(p1, q1, p2);
		int o2 = orientation(p1, q1, q2);
		int o3 = orientation(p2, q2, p1);
		int o4 = orientation(p2, q2, q1);
		
		if (o1 != o2 && o3 != o4)
			return true;
		
		if (o1 == 0 && onSegment(p1, p2, q1)) return true;
		
		if (o2 == 0 && onSegment(p1, q2, q1)) return true;
		
		if (o3 == 0 && onSegment(p2, p1, q2)) return true;
		
		if (o4 == 0 && onSegment(p2, q1, q2)) return true;
		
		return false;
	}
	
	typedef pair<Point, Point> line;
	const int minLinesToConsider = 4;
	
public:
	bool isSelfCrossing(vector<int>& moves) {
		if(moves.empty()) {
			return false;
		}
		list<line> lines;
		int startX = 0, startY = 0;
		int flagX = 1;
		int flagY = 0;
		for(int i = 0; i < (int)moves.size(); ++i) {
			Point a = Point(startX, startY);
			bool xParallel = (i & 1);
			int dx = 0, dy = 0;
			dx += (xParallel ? moves[i] : 0);
			dy += (xParallel ? 0 : moves[i]);
			if(xParallel) {
				if(flagX) {
					dx = -dx;
				}
				flagX ^= 1;
			} else {
				if(flagY) {
					dy = -dy;
				}
				flagY ^= 1;
			}
			int endX = startX + dx, endY = startY + dy;
			Point b = Point(endX, endY);
			
			auto pLine = lines.rbegin();
			++pLine;
			int k = 0;
			while(pLine != lines.rend() and k < minLinesToConsider) {
				line l = *pLine;
				if(doIntersect(a, b, l.first, l.second)) {
					return true;
				}
				++k; ++pLine;
			}
			if((int)lines.size() > minLinesToConsider) {
				lines.pop_front();
			}
			lines.push_back({a, b});
			startY = endY, startX = endX;
		}
		return false;
	}
};

// better solution
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        x.insert(x.begin(), 4, 0);
        int n = (int)x.size();
        int i = 4;
        // check outer spiral
        for(; i < n and x[i] > x[i - 2]; ++i);
        if(i == n) {
            return false;
        }
        if(x[i] >= x[i - 2] - x[i - 4]) {
            x[i - 1] -= x[i - 3];
        }
        // check inner spiral
        for(i++; i < n and x[i] < x[i - 2]; ++i);
        
        return i != n;
    }
};