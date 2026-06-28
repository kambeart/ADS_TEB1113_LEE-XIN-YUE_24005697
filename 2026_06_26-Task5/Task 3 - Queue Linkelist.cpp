#include <iostream>
#include <string>

using namespace std;

class Queue {
public:
    struct Node {
        string name;
        Node* next;
        
        Node(string name) {
            this->name = name;
            this->next = NULL;
        }
    };
    
    Node* front;
    Node* rear;

    Queue() {
        front = NULL;
        rear = NULL;
    }

    // enqueue
    void enqueue(string name) {
        Node* newNode = new Node(name);
        
        if (front == NULL) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        
        cout << "Enqueued: " << name << endl;
    }

    // dequeue
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        cout << front->name << " is dequeued." << endl;
        
        Node* temp = front;
        front = front->next;
        
        if (front == NULL) {
            rear = NULL;
        }
        
        delete temp;
    }

    // peek
    string peek() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return "";
        }
        return front->name;
    }

    // display all
    void display() {
        if (front == NULL) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        cout << "Queue elements (front to rear):" << endl;
        Node* current = front;
        int position = 1;
        
        while (current != NULL) {
            cout << position << ". " << current->name << endl;
            current = current->next;
            position++;
        }
    }
};

int main() {
    Queue q;

    q.enqueue("Aimar");
    q.enqueue("Ahmad");
    q.enqueue("Anajana");

    q.display();

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();

    cout << "\nAfter dequeue the front:" << endl;
    q.display();

    cout << "Front element: " << q.peek() << endl;

    return 0;
}