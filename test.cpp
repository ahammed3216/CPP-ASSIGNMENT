#include <iostream>
#include <memory>

class MinStack {
private:
    std::unique_ptr<int[]> dynamic_array;
    size_t size;
    int top;

public:
    // Constructor
    MinStack(int val) : size(val), dynamic_array(std::make_unique<int[]>(size)), top(-1) {}

    // Push operation to add an element to the stack
    void push(int val) {
        if (top >= static_cast<int>(size) - 1) {
            std::cout << "Stack is overflow!!!" << std::endl;
            return;
        }

        top++;
        dynamic_array[top] = val;
    }

    // Additional functions can be added here

    // Example: Pop operation to remove the top element from the stack
    void pop() {
        if (top >= 0) {
            top--;
        } else {
            std::cout << "Stack is underflow!!!" << std::endl;
        }
    }

    // Example: Function to get the top element of the stack
    int topElement() const {
        if (top >= 0) {
            return dynamic_array[top];
        } else {
            std::cout << "Stack is empty!!!" << std::endl;
            return -1; // Return a default value indicating an empty stack
        }
    }
};

int main() {
    MinStack myStack(5);

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    std::cout << "Top element: " << myStack.topElement() << std::endl;

    myStack.pop();
    std::cout << "Top element after pop: " << myStack.topElement() << std::endl;

    return 0;
}
