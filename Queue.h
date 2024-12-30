#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue 
{
private:
    T* data;
    int front;
    int rear;
    int capacity;
    int size;

public:
    explicit Queue(int capacity) : capacity(capacity), size(0), front(0), rear(-1) 
    {
        data = new T[capacity];
    }

    ~Queue() 
    {
        delete[] data;
    }

    bool IsEmpty() const 
    {
        return size == 0;
    }

    bool IsFull() const 
    {
        return size == capacity;
    }

    bool Enqueue(const T& value) 
    {
        if (IsFull()) 
        {
            return false;
        }
        rear = (rear + 1) % capacity;
        data[rear] = value;
        ++size;
        return true;
    }

    bool Dequeue(T& value) 
    {
        if (IsEmpty()) 
        {
            return false;
        }
        value = data[front];
        front = (front + 1) % capacity;
        --size;
        return true;
    }

    void Show() const 
    {
        if (IsEmpty()) 
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int count = size;
        int index = front;
        while (count--) 
        {
            cout << data[index] << " ";
            index = (index + 1) % capacity;
        }
        cout << endl;
    }
};