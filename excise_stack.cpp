#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stacks 
{
    private:
        int arr[MAX_SIZE];
        int top1, top2;

    public:
        Stacks() 
        {
            top1 = -1;
            top2 = MAX_SIZE;
        }

    void push1(int x) {
        if (top1 < top2 - 1) 
        {
            arr[++top1] = x;
        } 
        else 
        {
            cout << "Stack Overflow!" << endl;
        }
    }

    void push2(int x) 
    {
        if (top1 < top2 - 1) 
        {
            arr[--top2] = x;
        } 
        else 
        {
            cout << "Stack Overflow!" << endl;
        }
    }

    int pop1() 
    {
        if (top1 >= 0) 
        {
            int x = arr[top1--];
            return x;
        } 
        else 
        {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
    }

    int pop2() 
    {
        if (top2 < MAX_SIZE) 
        {
            int x = arr[top2++];
            return x;
        } 
        else 
        {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
    }
};

int main() 
{
    Stacks ts;
    ts.push1(10);
    ts.push2(20);
    ts.push1(30);
    ts.push2(40);
    cout << ts.pop1() << endl;
    cout << ts.pop2() << endl;
    cout << ts.pop1() << endl;
    cout << ts.pop2() << endl;
    return 0;
}
