#include <iostream>
#include <string>

using namespace std;

// Aimar, Ahmad, Anju 
// Delete Anju, insert Ali, insert Jessy
// Display all
// Use class instead of struct 

class Node {
public: 
    string name;
    Node* next; // memory address of next node
    // own next pointer
    // constructor for setting up when new node is created
    Node(string n) {
        name = n; // the string pass here to declare dulu
        next = nullptr;
        // Node* by default
    }
};

class LinkedList {
public:
    Node* head; // memory address of the first node
    // head -> [Aimar | next] -> [Ahmad | next] -> [Anju | nullptr]
    
    LinkedList() {
        head = nullptr; // empty list
    }

    void insertEnd(string name) { // insert at end
        Node* newNode = new Node(name);

        if (head == nullptr) { // empty
            head = newNode;
            return;
        }

        // if not, go to the last node
        Node* current = head;
        while (current -> next != nullptr) {
            current = current -> next;
        }
        current -> next = newNode;
    }

    void insertAfter(string afterName, string newName) {
        Node* current = head;
        
        while (current != nullptr && current -> name != afterName) {
            current = current -> next;
            // find the postition to be inserted
        }

        if (current == nullptr) {
            cout << afterName << "not found." << endl;
            return;
        }

        Node* newNode = new Node(newName);
        newNode -> next = current -> next;
        // Ali points to what Anju is pointing
        current->next = newNode; 
        // Anju now points to Ali 
    }

    // delete node by name 
    void deleteByName (string name) {
        if (head == nullptr) {
            return; //empty list
        }
        if (head -> name == name) {
            Node* temp = head;
            head = head -> next;
            delete temp; // deleted one should be head
            return;
        }
        // search thru list 
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->name == name) {
                
                // Store the node to be deleted
                Node* temp = current->next;
                
                // Bypass the deleted node by linking current node directly to the node after temp
                current->next = temp->next;
                
                // Free the memory of removed node
                delete temp;
                return;
            }
            // Move to next node in the list
            current = current -> next;
        }
        }
    }
    
    // display the linked list
    void display() {
        Node* current = head;
        if (current == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    // Insert initial nodes
    list.insertEnd("Aimar");
    list.insertEnd("Anju");
    list.insertEnd("Jessy");

    cout << "Initial list:" << endl;
    list.display();

    // Insert "Ali" after "Anju"
    list.insertAfter("Anju", "Ali");

    // Insert "Jane" at the end
    list.insertEnd("Jane");

    // Delete "Jessy" from the list
    list.deleteByName("Jessy");

    cout << "\nFinal list:" << endl;
    list.display();

    // ============================================
    // MANUAL LINKED LIST CREATION (FOR REFERENCE)
    // ============================================
    
    // Create nodes dynamically (using 'new' gives each node its own memory address)
    // Node node1, node2, node3; // DON'T DO THIS - they would share the same address
    // Node* node1 = new Node(); // Allocates memory for a new Node object
    // Node* node2 = new Node();
    // Node* node3 = new Node();

    // // Set up the linked list manually
    // node1->name = "Ali";
    // node1->next = node2;     // node1 points to node2
    
    // node2->name = "Ahmet";
    // node2->next = node3;     // node2 points to node3
    
    // node3->name = "Ayse";
    // node3->next = nullptr;   // node3 is the last node

    // // TRAVERSAL - Walk through the list and print each node
    // Node* current = node1;
    // while (current != nullptr) {
    //     cout << current->name << endl;
    //     current = current->next;  // Move to the next node
    // }

    // // ACCESS BY INDEX - Using an array of pointers
    // Node* arr[] = {node1, node2, node3};
    // int choice;
    // cout << "Enter 1-3 to print the name:" << endl;
    // cin >> choice;
    // cout << arr[choice - 1]->name << endl;  // Array index starts at 0

    // // ALTERNATIVE TRAVERSAL (using index instead of pointer)
    // // Node nodes[] = {node1, node2, node3}; // This won't work as expected
    // // int current = 0;
    // // while (current != -1) {
    // //     cout << current->name << endl;
    // //     current = current->next;
    // // }

    return 0;
}