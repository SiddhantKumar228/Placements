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
    head = newNode;
}

// Deleting node from beginning
void delFromBeginning(Node *&head, Node *&tail)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "Underflow";
        return;
    }
    head = head->next;
    temp->next = NULL;
    delete temp;
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

    insertAtBeginning(head, tail, 67);
    insertAtBeginning(head, tail, 49);
    insertAtBeginning(head, tail, 38);
    insertAtBeginning(head, tail, 25);
    insertAtBeginning(head, tail, 12);

    cout << "\nOriginal List: ";
    print(head);

    delFromBeginning(head, tail);
    delFromBeginning(head, tail);
    cout << "\nList After Deletion: ";
    print(head);

    cout << "\nhead = " << head->data;
    cout << "\ntail = " << tail->data;
}
