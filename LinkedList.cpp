#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
  string data;
  Node *next;
};

class LinkedList
{
  Node *head;

public:
  LinkedList()
  {
    head = NULL;
  }

  void insert(string val)
  {
    Node *new_node = new Node;
    new_node->data = val;
    new_node->next = NULL;

    if (head == NULL)
      head = new_node;

    else
    {
      new_node->next = head;
      head = new_node;
    }
  }

  bool search(string val)
  {
    int pos;
    Node *temp = head;
    while (temp != NULL)
    {
      if (temp->data == val)
        return true;
      temp = temp->next;
    }
    return false;
  }

  void remove(string val)
  {
    if (head->data == val)
    {
      delete head;
      head = head->next;
      return;
    }

    if (head->next == NULL)
    {
      if (head->data == val)
      {
        delete head;
        head = NULL;
        return;
      }
      cout << "Value not found!" << endl;
      return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
      if (temp->next->data == val)
      {
        Node *temp_ptr = temp->next->next;
        delete temp->next;
        temp->next = temp_ptr;
        return;
      }
      temp = temp->next;
    }

    cout << "Value not found" << endl;
  }

  void display()
  {
    Node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main()
{
  LinkedList l;
  cout << "Enter 1 for adding item.\n";
  cout << "Enter 2 for deleting item.\n";
  cout << "Enter 3 for displaying the list.\n";
  cout << "Enter 4 for searching for an item.\n";

  while (1)
  {
    int ch;
    cout << "Enter the code: ";
    cin >> ch;

    switch (ch)
    {
    case 1:
    {
      string item;
      cout << "Enter item to add: ";
      cin >> item;
      l.insert(item);
      break;
    }
    case 2:
    {
      string item;
      cout << "Enter item to delete: ";
      cin >> item;
      l.remove(item);
      break;
    }
    case 3:
    {
      l.display();
      break;
    }
    case 4:
    {
      string item;
      cout << "Enter item to search: ";
      cin >> item;
      if (l.search(item))
      {
        cout << item << " is in the list.\n";
      }
      else
      {
        cout << item << " is not in the list.\n";
      }
      break;
    }
    }
  }
  return 0;
}