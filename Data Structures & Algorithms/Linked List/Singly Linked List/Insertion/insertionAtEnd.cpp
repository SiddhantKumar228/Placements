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

// Inserting new node at end
void insertAtEnd(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    // Linked list is empty
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    // Linked list is non-empty
    tail->next = newNode;
    tail = newNode;
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

    insertAtEnd(head, tail, 45);
    insertAtEnd(head, tail, 67);
    insertAtEnd(head, tail, 19);
    print(head);
    cout << "\n";
    cout << "head = " << head->data << "\n";
    cout << "tail = " << tail->data;
}