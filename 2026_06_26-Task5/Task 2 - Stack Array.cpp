#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    string* arr;
    int capacity; // max size of stack
    int top; // index of top element

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new string[capacity];
        top = -1; // stack is empty
    }
    
    
    // push
    void push(string name) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << name << endl;
            return;
        }
        arr[++top] = name;
        cout << "Pushed: " << name << endl;
    }
    
    // pop
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop" << endl;
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }
    
    // peek
    string peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return "";
        }
        return arr[top];
    }
    
    // if stack empty
    bool isEmpty() {
        return top == -1;
    }
    
    // if stackfull
    bool isFull() {
        return top == capacity - 1;
    }
    
    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
    
        cout << "Stack elements (top to bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
    
    // current size
    int size() {
        return top + 1;
    }
};

int main() {
    // Create a stack with capacity of 5
    Stack stack(5);
    
    stack.push("Aimar");
    stack.push("Ahmad");
    stack.push("Anajana");
    stack.push("Jessy");
    
    stack.display();
    
    // peek
    cout << "\nTop element: " << stack.peek() << endl;
    cout << "Stack size: " << stack.size() << endl;
    
    cout << "\nPopping..." << endl;
    stack.pop();
    
    // ddisplay after pop
    stack.display();
    
    
    return 0;
}