#include <iostream>
#include <string>

using namespace std;

/*
Aimar
Ahmad
Anajana
Jessy
*/

class Stack{
    public:
        string name;
        Stack* next = NULL;
        Stack* curr_node = NULL; //added this

    // push 
    void insert_node(string name){
        Stack* newnode = new Stack(); 
        newnode -> name = name; 
        newnode -> next = newnode; 
        curr_node = newnode; //top 
    }

    // pop
    void remove_node(string name){
        Stack* temp = curr_node;
        curr_node = curr_node->next; //move top to next node
        delete temp; //delete the original top
        
    }
    

    // peek
    void peek_node(){
        if ( curr_node == nullptr) {
            cout << "Stack is empty";
        }
        else {
            cout << curr_node;
        }
    }
    
    
    void displaystack(){
        Stack*display_node = curr_node;
        while(display_node != NULL){
            cout << display_node -> name << endl;
            display_node = display_node->next;
        }
    }
};

int main() {
    Stack* node1 = new Stack(); //0x251732e0
    Stack* node2 = new Stack(); //0x251732e1
    Stack* node3 = new Stack(); //0x251732e2
    Stack* node4 = new Stack(); //0x251732e3
    
    node1->name = "Aimar";
    node1->next = node2; //0x251732e1
    
    node2->name = "Ahmad";
    node2->next = node3; //0x251732e2
    
    node3->name = "Anajana";
    node3->next = node4; //0x251732e3
     
    node4->name = "Jessy";
    
    Stack* display_node = node1;
    for(int i = 0; i < 4; i++){
        cout << display_node->name << endl; //0x251732e2
        display_node = display_node->next; //0x251732e3
    }
    
    return 0;
}