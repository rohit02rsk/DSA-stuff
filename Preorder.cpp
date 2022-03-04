#include <bits\stdc++.h>
using namespace std;

struct node
{
    string data;
    struct node *left;
    struct node *right;
};

struct node *newNode(string data)
{
    node *temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
};

void insert_node(struct node *root, string n1, string n2, char lr)
{
    if (root == NULL)
        return;
    if (root->data == n1)
    {
        switch (lr)
        {
        case 'l':
            root->left = newNode(n2);
            break;
        case 'r':
            root->right = newNode(n2);
            break;
        }
    }
    else
    {
        insert_node(root->left, n1, n2, lr);
        insert_node(root->right, n1, n2, lr);
    }
}

/* Function to print the preorder traversal of the tree */
void preorder(struct node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    struct node *root = NULL;
    int n;
    cout << "\nEnter the number of edges : ";
    cin >> n;
    cout << "\nInput the nodes of the binary tree in order \n\nparent-child-left(or)right-\n\n";
    while (n--)
    {
        char lr;
        string n1, n2;
        cin >> n1 >> n2;
        cin >> lr;
        if (root == NULL)
        {
            root = newNode(n1);
            switch (lr)
            {
            case 'l':
                root->left = newNode(n2);
                break;
            case 'r':
                root->right = newNode(n2);
                break;
            }
        }
        else
        {
            insert_node(root, n1, n2, lr);
        }
    }

    cout << "\nPreorder Traversal : ";
    preorder(root);
    return 0;
}