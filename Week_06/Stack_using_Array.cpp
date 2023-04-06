#include <iostream>
#include <chrono>

using namespace std;

const int maximum_size = 10; // Maximum size of the stack
int top = -1; // Index of the top element
int arr[maximum_size]; // Array to store the elements


void Push(int x) {
  // Check if the stack is full
  if (top >= maximum_size - 1) {
    cout << "Stack Overflow\n";
    return;
  }

  // Increment the top index and insert the element
  arr[++top] = x;
}


int Pop() {
  // Check if the stack is empty
  if (top < 0) {
    cout << "Stack Underflow\n";
    return -1;
  }

  // Get the top element and decrement the top index
  int x = arr[top--];
  return x;
}


bool isEmpty() {
  // Check if the stack is empty
  return (top < 0);
}


bool isFull() {
  // Check if the stack is full
  return (top >= maximum_size - 1);
}


int StackTop() {
  // Check if the stack is empty
  if (top < 0) {
    cout << "Stack is Empty\n";
    return -1;
  }

  // Get the top element
  int x = arr[top];
  return x;
}


void Display() {
  // Check if the stack is empty
  if (top < 0) {
    cout << "Stack is Empty\n";
    return;
  }

  // Print the elements in the stack
  for (int i = top; i >= 0; i--) {
    cout << arr[i] << " ";
  }
  cout << endl;
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
    std::cout << "Time taken for Stack using Array: " << duration.count() << " milliseconds.\n";
}