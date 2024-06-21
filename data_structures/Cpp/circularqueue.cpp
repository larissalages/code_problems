#include <iostream>
#include <stack>
using namespace std;

#define SIZE 10

class CircularQueue
{
    int a[SIZE];
    int rear;
    int front;

public:
    CircularQueue()
    {
        rear = front = -1;
    }

    bool isFull()
    {
        if (front == 0 && rear == SIZE - 1)
        {
            return true;
        }
        if (front == rear + 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(int x);
    int dequeue();
    void display();
    int size();
};

void CircularQueue ::enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue is full";
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % SIZE;

        a[rear] = x;
        cout << endl
             << "Inserted " << x << endl;
    }
}

int CircularQueue ::dequeue()
{
    int y;

    if (isEmpty())
    {
        cout << "Queue is empty\n"
             << endl;
    }
    else
    {
        y = a[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
        return (y);
    }
}

void CircularQueue ::display()
{
    int i;
    if (isEmpty())
    {
        cout << endl
             << "\nEmpty Queue\n"
             << endl;
    }
    else
    {
        cout << endl
             << "Front -> " << front;
        cout << endl
             << "Elements -> ";
        for (i = front; i != rear; i = (i + 1) % SIZE)
        {
            cout << a[i] << "\t";
        }
        cout << a[i];
        cout << endl
             << "Rear -> " << rear << "\n";
    }
}

int CircularQueue ::size()
{
    if (rear >= front)
    {
        return (rear - front) + 1;
    }
    else
    {
        return (SIZE - (front - rear) + 1);
    }
}

int main()
{
    CircularQueue cq;
    int n;
    int x;
    while (1)
    {
        cout << "\n1. enqueue\n2. dequeue\n3. size\n4. Display Elements\n5. Exit\n";
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter  the No. ";
            cin >> x;
            cq.enqueue(x);
            break;

        case 2:
            cout << "Removed element: " << cq.dequeue() << endl;
            break;
        case 3:
            cout << endl
                 << "Size of queue: " << cq.size() << endl;
            break;
        case 4:
            cq.display();
            break;
        case 5:
            return 0;
            break;
        default:
            break;
        }
    }
}