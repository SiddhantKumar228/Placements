#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Constructor
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

// Inserting New Node At Beginning
void insertAtBeginning(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    // Linked List is Empty
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    // Linked List is Non-empty
    newNode->next = head;
    head = newNode;
}

// Traverse & Print the Linked List
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// Main Function
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtBeginning(head, tail, 34);
    insertAtBeginning(head, tail, 12);
    insertAtBeginning(head, tail, 25);
    insertAtBeginning(head, tail, 59);
    insertAtBeginning(head, tail, 49);

    print(head);
    cout << "\n";
    cout << "head = " << head->data << "\n";
    cout << "tail = " << tail->data;
}