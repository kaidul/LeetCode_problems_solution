/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

 // bad design; with extra space
 /*
class NestedIterator {
    vector<int> container;
    int indx;
    
    void NestedIteratorUtil(vector<NestedInteger> &nestedList) {
         for(int i = 0; i < nestedList.size(); ++i) {
            if(nestedList[i].isInteger()) {
                container.push_back(nestedList[i].getInteger());
            } else {
                NestedIteratorUtil(nestedList[i].getList());
            }
        }       
    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        container.clear(); indx = 0;
        NestedIteratorUtil(nestedList);
    }

    int next() {
        return container[indx++];
    }

    bool hasNext() {
        return indx < container.size();
    }
};
*/

// stack based solution; extract as much as we need at a moment and keep reference in stack
// not faster than above one, but memory efficient
class NestedIterator {
    stack<NestedInteger*> container;
    
    bool isEmpty(vector<NestedInteger>& nestedList) {
        
        for(int i = 0; i < (int)nestedList.size(); ++i) {
            if(nestedList[i].isInteger()) {
                return false;
            }
            else if(!isEmpty(nestedList[i].getList())) {
                return false;
            }
        }
        return true;
    }
    
    void fetchNextInteger() {
        while(!container.empty() and !container.top()->isInteger()) {
            vector<NestedInteger>& nestedList = container.top()->getList();
            container.pop();
            for(int n = (int)nestedList.size(), i = n - 1; i >= 0; --i) {
                if(nestedList[i].isInteger()) {
                    container.push(&nestedList[i]);
                } 
                else if(!isEmpty(nestedList[i].getList())) {
                    container.push(&nestedList[i]);
                } 
            }
        }
    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if(!container.empty()) {
            container = stack<NestedInteger*>();
        }
        for(int n = (int)nestedList.size(), i = n - 1; i >= 0; --i) {
            if(nestedList[i].isInteger()) {
                container.push(&nestedList[i]);
            } 
            else if(!isEmpty(nestedList[i].getList())) {
                container.push(&nestedList[i]);
            }
        }
    }

    int next() {
        if(!container.top()->isInteger()) {
            fetchNextInteger();
        }
        int front = container.top()->getInteger();
        container.pop();
        return front;
    }

    bool hasNext() {
        return !container.empty();
    }
};
/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */