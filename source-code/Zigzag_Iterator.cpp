class ZigzagIterator {
public:
#define VECTOR_NUM 2
    int curr;
    vector<int> v1, v2;
    vector<int>::iterator it1, it2;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        this->v1 = v1;
        this->v2 = v2;
        it1 = this->v1.begin();
        it2 = this->v2.begin();
        curr = 0;
    }

    int next() {
        int ret;
        if(curr == 0) {
            if(it1 != v1.end()) {
                ret = *it1;
                ++it1;    
            } else if(it2 != v2.end()) {
                ret = *it2;
                ++it2;
            }
        } else if(curr == 1) {
            if(it2 != v2.end()) {
                ret = *it2;
                ++it2;    
            } else if(it1!= v1.end()) {
                ret = *it1;
                ++it1;
            }
        }
        ++curr;
        curr %= VECTOR_NUM;
        return ret;
    }

    bool hasNext() {
        return  it1 != v1.end() or it2 != v2.end();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */