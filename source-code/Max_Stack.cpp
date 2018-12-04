class MaxStack {
    stack<int> stack1;
    stack<int> stack2;
public:
    /** initialize your data structure here. */
    MaxStack() {
        stack1 = stack<int> ();
        stack2 = stack<int> ();
    }
    
    void push(int x) {
        stack1.push(x);
        if (stack2.empty() or x >= stack2.top()) {
            stack2.push(x);
        }
    }
    
    int pop() {
        int element = stack1.top();
        stack1.pop();
        if (!stack2.empty() and stack2.top() == element) {
            stack2.pop();
        }
        return element;
    }
    
    int top() {
        return stack1.top();
    }
    
    int peekMax() {
        return stack2.top();
    }
    
    int popMax() {
        int maxElement = stack2.top();
        stack<int> tmpStack;
        while(!stack1.empty() and stack1.top() != maxElement) {
            int element = stack1.top();
            tmpStack.push(element);
            stack1.pop();
        }
        stack1.pop();
        stack2.pop();
        while(!tmpStack.empty()) {
            int x = tmpStack.top();
            push(x);
            tmpStack.pop();
        }
        
        return maxElement;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */