#include <bits/stdc++.h>
using namespace std;

struct Queue
{
    int front, rear, cap;
    string *queue;
    Queue(int c)
    {
        front = rear = 0;
        cap = c;
    }

    ~Queue() { delete[] queue; }

    //Function for enqueing:
    void enqueue(string data)
    {
        if (cap == rear)
        {
            cout << "The queue is full.\n";
            return;
        }
        else
        {
            queue[rear] = data;
            rear++;
        }
        return;
    }

    //Function for dequeing:
    void dequeue()
    {
        if (front = rear)
        {
            cout << "The queue is empty.\n";
            return;
        }
        else
        {
            front++;
        }
        return;
    }

    //Function for displaying the queue:
    void display()
    {
        int i;
        if (front == rear)
        {
            cout << "The queue is empty.\n";
            return;
        }
        cout << "The queue is:\n";
        for (i = front; i < rear; ++i)
        {
            cout << queue[i] << " ";
        }
        return;
    }
};

int main()
{
    Queue q(5);

    q.enqueue("20BBS0121");
    q.enqueue("20BBS0122");
    q.enqueue("20BBS0123");
    q.enqueue("20BBS0124");
    q.enqueue("20BBS0125");

    q.dequeue();
    q.dequeue();
    
    q.display();

    return 0;
}