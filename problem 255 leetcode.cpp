#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {
        // Initialize the two queues
    }

    void push(int x) {
        // Push element into the first queue
        q1.push(x);
    }

    int pop() {
        // Move all elements except the last one from q1 to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        // The last element is the top of the stack
        int topElement = q1.front();
        q1.pop();
        // Swap q1 and q2
        swap(q1, q2);
        return topElement;
    }

    int top() {
        // Similar to pop, but we don't remove the last element
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topElement = q1.front();
        // Move the last element to q2
        q2.push(topElement);
        q1.pop();
        // Swap q1 and q2
        swap(q1, q2);
        return topElement;
    }

    bool empty() {
        return q1.empty();
    }
};

// Example usage:
int main() {
    MyStack stack;
    stack.push(1);
    stack.push(2);
    cout << stack.top() << endl; // Output: 2
    cout << stack.pop() << endl; // Output: 2
    cout << stack.empty() << endl; // Output: false
    return 0;
}
