#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Queue {
private:
    int front, rear, size;
    string arr[MAX];

public:
    Queue() : front(0), rear(-1), size(0) {}

    bool isFull() {
        return size == MAX;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(const string& customer) {
        if (isFull()) {
            cout << "Queue is full! Cannot add more customers." << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = customer;
        size++;
        cout << customer << " added to the queue." << endl;
    }

    string dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! No customers to serve." << endl;
            return "";
        }
        string customer = arr[front];
        front = (front + 1) % MAX;
        size--;
        return customer;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Current Queue: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % MAX] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue customerQueue;
    int choice;
    string customerName;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Customer to Queue\n";
        cout << "2. Serve Customer\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                getline(cin, customerName);
                customerQueue.enqueue(customerName);
                break;
            case 2:
                cout << "Serving: " << customerQueue.dequeue() << endl;
                break;
            case 3:
                customerQueue.display();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
