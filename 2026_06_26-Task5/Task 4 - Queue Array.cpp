#include <iostream>
#include <string>

using namespace std;

class Queue {
public:
    string arr[100];
    int front; 
    int rear; //tail

    Queue() {
        front = 0; 
        rear = 0;  
    }

    // Enqueue 
    void enqueue(string name) {

        // mmoverear to next position
        rear++;
        // enter new rear to rear position
        arr[rear] = name;
        
        cout << "Enqueued: " << name << endl;
    }

    // dequeue
    void dequeue() {
        cout << arr[front] << " is dequeued." << endl;
        
        // move front tonext element
        front++;
    }

    // peek
    string peek() {
        if (front == 0) {
            cout << "Queue is empty!" << endl;
            return "";
        }
        return arr[front];
    }

    // display all
    void display() {
        cout << "Queue elements (front to rear):" << endl;
        for (int i = front; i <= rear; i++) {
            cout << i << ". " << arr[i] << endl;
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