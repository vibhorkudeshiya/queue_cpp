/*22070123132 Experiment - Queue*/
#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Queue {
private:
    int front, rear;
    int queue[MAX_SIZE];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insert(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot insert more elements." << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        cout << "Inserted: " << value << endl;
    }

    void deleteElement() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot delete an element." << endl;
            return;
        }
        int deletedValue = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        cout << "Deleted: " << deletedValue << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    int choice, value;
    while (true) {
        cout << "Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            queue.insert(value);
            break;

        case 2:
            queue.deleteElement();
            break;

        case 3:
            queue.display();
            break;

        case 4:
            cout << "Exiting the program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
}
