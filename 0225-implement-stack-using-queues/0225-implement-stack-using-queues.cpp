class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    
    MyStack() {
    }

    void push(int x) {
        
        // Put new element into q2
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2
        swap(q1, q2);
    }

    int pop() {
        
        int value = q1.front();
        q1.pop();
        
        return value;
    }

    int top() {
        
        return q1.front();
    }

    bool empty() {
        
        return q1.empty();
    }
};