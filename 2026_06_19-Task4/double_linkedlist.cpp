#include <iostream>
#include <string>

using namespace std;

class Node {
public: 
    string name;
    Node* next = nullptr;  // points to next node
    Node* prev = nullptr;  // points to prev node

    // constructor: createnew node with name 
    Node(string n) {
        name = n;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    Node* head;  // Points to first node in the list

    LinkedList() {
        head = nullptr;  // Empty list
    }

    // new node at the end of list
    void insertEnd(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            // List is empty, new node jadi head
            head = newNode;
            return;
        }

        // goes to last head
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        
        // Link the new node at the end
        current->next = newNode;
        newNode->prev = current;
    }

    // new node after a specific node
    void insertAfter(string afterName, string newName) {
        Node* current = head;
        
        // Find node with given name
        while (current != nullptr && current->name != afterName) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << afterName << " not found." << endl;
            return;
        }

        Node* newNode = new Node(newName);
        
        // set new node's links first
        newNode->next = current->next;
        newNode->prev = current;

        // Update the next node's prev link if it exists
        if (current->next != nullptr) {
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
        
        // Case 1: Delete head node
        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;  // New head has no previous node
            }
            delete temp;
            return;
        }
        
        // Case 2: Delete other node (not head)
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->name == name) {
                Node* temp = current->next;  // Node to delete
                
                // Bypass temp: current →> temp->next
                current->next = temp->next;
                
                // Update the prev link of the node after temp
                if (temp->next != nullptr) {
                    temp->next->prev = current;
                }
                
                delete temp;
                return;
            }
            current = current->next;
        }
        
        cout << name << " not found." << endl;
    }
    
    // Display list in going forward order
    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }

    // Display the list in reverse order
    void displayReverse() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        // Traverse to the last node
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        // Traverse backwards using prev pointers
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->prev;
        }
    }
};

int main() {
    LinkedList list;

    // Insert initial nodes
    list.insertEnd("Aimar");
    list.insertEnd("Anju");
    list.insertEnd("Jessy");

    cout << "\nInitial list:" << endl;
    list.display();

    // Insert "Ali" after "Anju"
    cout << "\nAfter inserting Ali after Anju:" << endl;
    list.insertAfter("Anju", "Ali");
    list.display();

    // Insert "Jane" at the end
    cout << "\nAfter inserting Jane at the end:" << endl;
    list.insertEnd("Jane");
    list.display();

    // Delete "Jessy"
    cout << "\nAfter deleting Jessy:" << endl;
    list.deleteByName("Jessy");
    list.display();

    cout << "\nReverse linked list:" << endl;
    list.displayReverse();

    cout << "\nFinal list (in order):" << endl;
    list.display();

    // yay!!!!

    return 0;
}