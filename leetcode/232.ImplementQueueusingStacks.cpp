#include <vector>
#include <list>
#include <iostream>

using namespace std;

class MyQueue {
    list<int> list{};

public:
    MyQueue() = default;

    void push(int x) {
        list.push_back(x);
    }

    int pop() {
        int val = list.front();
        list.pop_front();
        return val;
    }

    int peek() {
        return list.front();
    }

    bool empty() {
        return list.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    return 0;
}

