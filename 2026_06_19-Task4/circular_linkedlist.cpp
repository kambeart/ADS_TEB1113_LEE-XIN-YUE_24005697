#include <iostream>
#include <string>

using namespace std;

class Node {
    public: 
        string name;
        Node* next = nullptr;  // Points to the next node
        Node* prev = nullptr;  // Points to the previous node
    
        // Constructor - creates a new node with a name
        Node(string n) {
            name = n;
            next = nullptr;
            prev = nullptr;
        }
    };
    
    class LinkedList {
    public:
        Node* head;  // Points to the first node in circular list
    
        LinkedList() {
            head = nullptr;  // Empty list
        }
    
        // new node at the end of the circular list
        void insertEnd(string name) {
            Node* newNode = new Node(name);
    
            if (head == nullptr) {
                // List is empty = point the node to itself
                head = newNode;
                newNode->next = head;
                newNode->prev = head;
                return;
            }
    
            // In circular list, head->prev is always tail
            Node* tail = head->prev;
    
            // new node after the tail
            tail->next = newNode;     // Old tail → new node
            newNode->prev = tail;     // New node ← old tail
            newNode->next = head;     // New node → head (makes it circular)
            head->prev = newNode;     // Head ← new node
        }
    
        // new node after specific node
        void insertAfter(string afterName, string newName) {
            Node* current = head;
            
            // Find node with givne name
            while (current != nullptr && current->name != afterName) {
                current = current->next;
                if (current == head) break;  // Prevent infinite loop in circular list
            }
    
            if (current->name != afterName) {
                cout << afterName << " not found." << endl;
                return;
            }
    
            Node* newNode = new Node(newName);
            
            // Set new node's links dulu
            newNode->next = current->next;
            newNode->prev = current;
            
            // Update the next node's prev link (if not head)
            if (current->next != head) {
                current->next->prev = newNode;
            }
            
            // update current node's next link
            current->next = newNode;
        }
    
        // Delete a node by name
        void deleteByName(string name) {
            if (head == nullptr) {
                return;  // Empty list
            }
    
            // Case 1: delete head node
            if (head->name == name) {
                Node* temp = head;
                
                if (head->next == head) {
                    // Only one node in the list
                    head = nullptr;
                } else {
                    // More than one node
                    Node* tail = head->prev;
                    head = head->next;
                    head->prev = tail;
                    tail->next = head;
                }
                
                delete temp;
                return;
            }
    
            // Case 2: delete node lain (not head)
            Node* current = head;
            
            // Traverse until we find the node before the one to delete
            while (current->next != head) {
                if (current->next->name == name) {
                    Node* temp = current->next; // Node to delete
                    
                    // Bypass temp: current → temp->next
                    current->next = temp->next;
                    
                    // Update the prev link of the node after temp
                    if (temp->next != head) {
                        temp->next->prev = current;
                    } else {
                        // If deleting the tail, update head's prev
                        head->prev = current;
                    }
                    
                    delete temp;
                    return;
                }
                current = current->next;
            }
            
            cout << name << " not found." << endl;
        }
        
        // Display the list in forward order
        void display() {
            if (head == nullptr) {
                cout << "The list is empty." << endl;
                return;
            }
            
            Node* current = head;
            do {
                cout << current->name << endl;
                current = current->next;
            } while (current != head);  // Stop when we circle back to head
        }
    
        // Display the list in reverse order
        void displayReverse() {
            if (head == nullptr) {
                cout << "The list is empty." << endl;
                return;
            }
    
            Node* current = head->prev;  // Start from the tail
            do {
                cout << current->name << endl;
                current = current->prev;
            } while (current != head->prev);  // Stop when we circle back to tail
        }
};

int main() {
    LinkedList list;

    // initial nodes
    list.insertEnd("Aimar");
    list.insertEnd("Anju");
    list.insertEnd("Jessy");

    cout << "\nInitial list:" << endl;
    list.display();

    // Ali after Anju
    cout << "\nAfter inserting Ali after Anju:" << endl;
    list.insertAfter("Anju", "Ali"); 
    list.display();

    // Jane at the end
    cout << "\nAfter inserting Jane at the end:" << endl;
    list.insertEnd("Jane");
    list.display();

    // Delete Jessy
    cout << "\nAfter deleting Jessy:" << endl;
    list.deleteByName("Jessy");
    list.display();

    // Display in reverse
    cout << "\nReverse linked list:" << endl;
    list.displayReverse();

    cout << "\nFinal list (in order):" << endl;
    list.display();

    return 0;
}