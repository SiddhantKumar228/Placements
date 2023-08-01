#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    // Constructor
    Node(int val)
    {
        this->prev = NULL;
        this->data = val;
        this->next = NULL;
    }
};

// Inserting node at beginning
void insertAtBeginning(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Print linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Main function
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtBeginning(head, tail, 47);
    insertAtBeginning(head, tail, 35);
    insertAtBeginning(head, tail, 23);
    insertAtBeginning(head, tail, 12);
    insertAtBeginning(head, tail, 4);
    print(head);

    cout << "\nHead = " << head->data;
    cout << "\nTail = " << tail->data;
}