class MinStack {
private:
    class Stack {
    private:
        struct Node {
            int data;
            Node *next;
            Node(int const& data, Node *next)
                : data(data)
                , next(next) {
            }
        };
        Node *head = nullptr;
        int elements = 0;
    public:
        ~Stack() {
            Node *next;
            for(Node* loop = head; loop != nullptr; loop = next) {
                next = loop->next;
                delete loop;
            }
        }
        void push(int const& data) {
            head = new Node(data, head);
            ++elements;
        }
        bool empty() const {
            return head == nullptr;
        }
        int size() const {
            return elements;
        }
        int top() const {
            assert(head != nullptr);
            return head->data;
        }
        void pop() {
            assert(head != nullptr);
            Node *tmp = head;
            head = head->next;
            --elements;
            delete tmp;
        }
    };
    // Stack stack1, stack2;
    // using custom data-structure yields MLE :/
    stack<int>stack1, stack2;
public:
    void push(int x) {
        stack2.push(x);
        if(stack1.empty() or x <= stack1.top()) {
            stack1.push(x);
        }
    }

    void pop() {
        int top = stack2.top();
        stack2.pop();
        if(top == stack1.top()) {
            stack1.pop();
        } 
    }

    int top() {
        return stack2.top();
    }

    int getMin() {
        return stack1.top();
    }
};