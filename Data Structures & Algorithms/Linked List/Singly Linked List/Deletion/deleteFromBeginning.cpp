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

// Insert new nodes at beginning
void insertAtbeginning(Node *&head, Node *&tail, int val)
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

// Delete nodes from beginning
void deleteFromBeginning(Node *&head, Node *&tail)
{
    // List is empty
    if (head == NULL)
    {
        cout << "Underflow";
        return;
    }

    // List is non-empty
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

// Print list
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

    insertAtbeginning(head, tail, 50);
    insertAtbeginning(head, tail, 40);
    insertAtbeginning(head, tail, 30);
    insertAtbeginning(head, tail, 20);
    insertAtbeginning(head, tail, 10);
    cout << "Original List = ";
    print(head);
    cout << "\n";

    deleteFromBeginning(head, tail);
    deleteFromBeginning(head, tail);
    cout << "List after deletion = ";
    print(head);

    cout << "\n";
    cout << "head = " << head->data << "\n";
    cout << "tail = " << tail->data;
}