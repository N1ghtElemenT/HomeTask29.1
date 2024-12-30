#include <iostream>
#include "Queue.h"
using namespace std;

int main() 
{
    int capacity;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    Queue<int> queue(capacity);

    while (true) 
    {
        cout << "\nChoose an action:" << endl;
        cout << "1. Enqueue (Add element)" << endl;
        cout << "2. Dequeue (Remove element)" << endl;
        cout << "3. Show elements" << endl;
        cout << "4. Check if the queue is empty" << endl;
        cout << "5. Check if the queue is full" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1: {
            if (queue.IsFull())
            {
                cout << "The queue is full!\n";
            }
            else
            {
                int value;
                cout << "Enter the value to enqueue: ";
                cin >> value;
                if (queue.Enqueue(value))
                {
                    cout << "Value added to the queue.\n";
                }
                else
                {
                    cout << "Failed to add value to the queue.\n";
                }
            }
            break;
        }
        case 2:
        {
            int removedValue;
            if (queue.Dequeue(removedValue))
            {
                cout << "Removed value: " << removedValue << "\n";
            }
            else
            {
                cout << "The queue is empty. Cannot remove elements.\n";
            }
            break;
        }
        case 3:
        {
            cout << "Queue elements: ";
            queue.Show();
            break;
        }
        case 4:
        {
            cout << (queue.IsEmpty() ? "The queue is empty.\n" : "The queue is not empty.\n");
            break;
        }
        case 5:
        {
            cout << (queue.IsFull() ? "The queue is full.\n" : "The queue is not full.\n");
            break;
        }
        case 6:
        {
            cout << "Goodbye!\n";
            return 0;
        }
        default:
        {
            cout << "Invalid choice.\n";
        }
        }
    }

    return 0;
}