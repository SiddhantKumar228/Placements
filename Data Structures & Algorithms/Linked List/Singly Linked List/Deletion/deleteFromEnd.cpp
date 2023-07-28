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

// Insert node at end
void insertAtEnd(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

// Delete node from end
void deleteFromEnd(Node *&head, Node *&tail)
{
    Node *temp = head;
    // List is empty
    if (head == NULL)
    {
        cout << "Underflow";
        return;
    }

    // List is non-empty
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = NULL;
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
    insertAtEnd(head, tail, 10);
    insertAtEnd(head, tail, 20);
    insertAtEnd(head, tail, 30);
    insertAtEnd(head, tail, 40);
    insertAtEnd(head, tail, 50);
    cout << "Original List = ";
    print(head);
    cout << "\n";

    cout << "List after deletion = ";
    deleteFromEnd(head, tail);
    deleteFromEnd(head, tail);
    print(head);

    cout << "\n";
    cout << "head = " << head->data << "\n";
    cout << "tail = " << tail->data;
}