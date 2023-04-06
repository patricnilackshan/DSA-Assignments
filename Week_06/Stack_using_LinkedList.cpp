#include <iostream>
#include <chrono>

using namespace std;

// Definition of the node structure
struct Node {
    int data;
    Node* next;
};

// The top pointer of the stack
Node* top = NULL;


// Push function to insert data into the stack
void Push(int value) {
    // Allocate a new node and set its value and next pointer
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;

    // Update the top pointer to point to the new node
    top = newNode;
}


// Pop function to remove/delete data from the stack
void Pop() {
    // If the stack is empty, print a message and return
    if (top == NULL) {
        cout << "Stack is empty.\n";
        return;
    }

    // Save the current top node in a temporary variable
    Node* temp = top;

    // Update the top pointer to point to the next node
    top = top->next;

    // Delete the temporary variable to free memory
    delete temp;
}


// isEmpty function to check whether the stack is empty or not
bool isEmpty() {
    return top == NULL;
}


// isFull function to check whether the stack is full or not
bool isFull() {
    // Linked list implementation doesn't have a fixed size limit, so it's always false.
    return false;
}


// StackTop function to find what is at the top of the stack
int StackTop() {
    // If the stack is empty, print a message and return -1
    if (top == NULL) {
        cout << "Stack is empty.\n";
        return -1;
    }

    // Return the data value of the top node
    return top->data;
}


// Display function to print the elements in the stack
void Display() {
    // If the stack is empty, print a message and return
    if (top == NULL) {
        cout << "Stack is empty.\n";
        return;
    }

    // Traverse the stack from top to bottom and print the data values of each node
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}


int main() {
    auto start = std::chrono::high_resolution_clock::now();
    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Time taken for Stack using LinkedList: " << duration.count() << " milliseconds.\n";
}