#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    string data;
    struct Node* link;
};
 
struct Node* top;
 
void push(string data)
{
    struct Node* temp;
    temp = new Node();
 
    if (!temp)
    {
        cout << "\nHeap Overflow";
        exit(1);
    }
 
    temp->data = data;
    temp->link = top;
    top = temp;
}

int isEmpty()
{
    return top == NULL;
}

string peek()
{
    if (!isEmpty())
        return top->data;
    else
        exit(1);
}
 
void pop()
{
    struct Node* temp;

    if (top == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}

void display()
{
    struct Node* temp;
 
    if (top == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "-> ";
            temp = temp->link;
        }
        cout << endl;
    }
}
 
int main()
{
    cout << "Enter 1 for pushing item.\n";
    cout << "Enter 2 for popping top item.\n";
    cout << "Enter 3 for displaying the stack.\n"; 
    cout << "Enter 4 for displaying the top.\n"; 

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
                cout<<"Enter item to push: ";
                cin>>item;
                push(item);
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                cout << "The top is: " << peek() << endl;
                break;
            }
            default:
            {
                cout<<"Please enter a valid code.\n";
            }
        }
    }   
    return 0;
}