#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>
const int N = 1e5 + 2, MOD = 1e9 + 7;
class Stack
{
public:
    int top;
    int *arr;
    int size;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int val)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = val;
            return;
        }
        cout << "Stack Overflow" << endl;
    }
    void pop()
    {
        if (top != -1)
        {
            top--;
            return;
        }
        cout << "Stack underflow" << endl;
    }
    int peek()
    {
        if (top != -1)
            return arr[top];
        cout << "Stack is empty" << endl;
        return -1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
};

signed main()
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    cout << s.peek() << endl;
    s.pop();
    s.pop();
    cout << s.isEmpty() << endl;
    return 0;
}