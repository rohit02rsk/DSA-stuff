#include<iostream>
#include<cstring>
using namespace std;

#define capacity 6
string queue[capacity];
int front = -1, rear = -1;

// Here we check if the Circular queue is full or not
int checkFull(){
    if ((front == rear + 1) || (front == 0 && rear == capacity - 1)){
        return 1;
    }
    return 0;
}

// Here we check if the Circular queue is empty or not
int checkEmpty(){
    if (front == -1) 
    {
        return 1;
    }
  return 0;
}

// Addtion in the Circular Queue
void enqueue(string value)
{
    if (checkFull())
      cout<<"Overflow condition\n"<<endl;
    
    else
    {
        if (front == -1) 
            front = 0;
        
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        cout<<value<<"Enqueued in Queue"<<endl;
  }
}

// Removal from the Circular Queue
string dequeue() 
{
    string variable;
    if (checkEmpty()) 
    {
        cout<<"Underflow condition"<<endl;
        return " ";
    } 
    else
    {
        variable = queue[front];
        if (front == rear)
        {
            front = rear = -1;
        } 
        else 
        {
            front = (front + 1) % capacity;
        }
    cout<<variable<<"dequeued from circular queue"<<endl;
    return " ";
  }
}

// Display the queue
void print(){
    int i;
    if (checkEmpty())
       cout<<"Nothing to dequeue"<<endl;
    else
    {
        cout<<"The queue looks like:"<<endl;
        for (i = front; i != rear; i = (i + 1) % capacity)
        {
            cout<<queue[i]<<endl;
        }
    cout<<queue[i];
  }
}

int main() {
  // Not possible as the Circular queue is empty
  dequeue();

  enqueue("20BBS0121");
  enqueue("20BBS0122");
  enqueue("20BBS0123");
  enqueue("20BBS0124");
  enqueue("20BBS0125");
  

  print();
  dequeue();
  dequeue();

  print();

  enqueue("20BBS0126");
  enqueue("20BBS0127");
  enqueue("20BBS0128");
  enqueue("20BBS0129");
  print();
  return 0;
}