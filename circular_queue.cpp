#include <iostream>
using namespace std;

int cqueue[5];
int front = -1, rear = -1, n = 5;

void insertElement(int val) {
    //overflow
    if ((rear + 1) % n == front) {
        cout << "Queue Overflow \n";
        return;
    }
    // Handle empty queue case
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % n;
    }
    cqueue[rear] = val;
}

void deleteElement() {
    //if the queue is empty
    if (front == -1) {
        cout << "Queue is empty \n";
        return;
    }
    cout << "Element deleted from queue is: " << cqueue[front] << endl;
    // Handle single element case
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % n;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements are: ";
    int f = front;
    while (true) {
        cout << cqueue[f] << " ";
        if (f == rear) break;
        f = (f + 1) % n;
    }
    cout << endl;
}

int main() {
    cout << "CIRCULAR QUEUE\n";
    cout <<"----------------";
    int ch, val;
    do {
        cout << "\n1) Insert \n";
        cout << "2) Delete \n";
        cout << "3) Display \n";
        cout << "4) Exit \n";
        cout << "\nEnter the choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Input for insertion: ";
                cin >> val;
                insertElement(val);
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting \n";
                break;
            default:
                cout << "Invalid choice! \n";
        }
    } while (ch != 4);
    return 0;
}

