/*22070123132 Experiment - Linked List based Queue Implementation*/
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void add_queue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        std::cout << value << " Added to the queue." << std::endl;
    }

    void del_queue() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
        } else {
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;  // Queue is now empty
            }
            std::cout << temp->data << " deleted element from the queue." << std::endl;
            delete temp;
        }
    }

    void display() {
        if (isEmpty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        Node* current = front;
        std::cout << "Queue elements: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Queue myQueue;
    int choice, value;

    while (true) {
        std::cout << "Queue Menu:" << std::endl;
        std::cout << "1. Add in queue" << std::endl;
        std::cout << "2. Delete in queue" << std::endl;
        std::cout << "3. Display" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter a value to add in queue: ";
                std::cin >> value;
                myQueue.add_queue(value);
                break;
            case 2:
                myQueue.del_queue();
                break;
            case 3:
                myQueue.display();
                break;
            case 4:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
