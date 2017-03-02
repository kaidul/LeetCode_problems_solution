class Stack {
public:
    queue <int> Q1;
    queue <int> Q2;
    // Push element x onto stack.
    void push(int x) {
        while(!Q1.empty()) {
            Q2.push(Q1.front());
            Q1.pop();
        }
        Q1.push(x);
        while(!Q2.empty()) {
            Q1.push(Q2.front());
            Q2.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        Q1.pop();
    }

    // Get the top element.
    int top() {
        return Q1.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return Q1.empty();
    }
};