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

// Inserting node at end
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

// Deleting node from end
void delFromEnd(Node *&head, Node *&tail)
{
    Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp;
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

    insertAtEnd(head, tail, 12);
    insertAtEnd(head, tail, 23);
    insertAtEnd(head, tail, 34);
    insertAtEnd(head, tail, 49);
    insertAtEnd(head, tail, 67);

    cout << "\nOriginal List: ";
    print(head);

    delFromEnd(head, tail);
    delFromEnd(head, tail);
    cout << "\nList After Deletion: ";
    print(head);

    cout << "\nhead = " << head->data;
    cout << "\ntail = " << tail->data;
}