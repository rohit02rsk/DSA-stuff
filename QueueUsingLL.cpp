#include <bits/stdc++.h>
using namespace std;
  
struct QNode 
{
    string data;
    QNode* next;
    QNode(string d)
    {
        data = d;
        next = NULL;
    }
};
  
struct Queue
{
    QNode *front, *rear;
    Queue()
    {
        front = rear = NULL;
    }
  
    void enQueue(string x)
    {
        QNode* temp = new QNode(x);
  
        if (rear == NULL) 
        {
            front = rear = temp;
            return;
        }
  
        rear->next = temp;
        rear = temp;
    }
  
    void deQueue()
    {
        if (front == NULL)
            return;
  
        QNode* temp = front;
        front = front->next;
  
        if (front == NULL)
            rear = NULL;
  
        delete (temp);
    }

    void Display() 
    {
        QNode *temp = front;
        if ((front == NULL) && (rear == NULL)) 
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        cout<<"Queue elements are: ";
        while (temp != NULL) 
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    Queue q;

    cout << "Enter 1 for enqueueing item.\n";
    cout << "Enter 2 for dequeueing item.\n";
    cout << "Enter 3 for displaying the queue.\n";

    while(1)
    {
        int ch;
        cout<<"Enter the code: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                string item;
                cout<<"Enter item to enqueue: ";
                cin>>item;
                q.enQueue(item);
                break;
            }
            case 2:
            {
                q.deQueue();
                break;
            }
            case 3:
            {
                q.Display();
                break;
            }
            default:
            {
                cout<<"Please enter a valid code.\n";
                break;
            }
        }
    }
    return 0;
}