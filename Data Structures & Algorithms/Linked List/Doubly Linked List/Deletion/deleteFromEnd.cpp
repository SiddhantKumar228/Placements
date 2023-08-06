#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        this->prev = NULL;
        this->data = val;
        this->next = NULL;
    }
};

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
    newNode->prev = tail;
    tail = newNode;
}

void delFromEnd(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Underflow";
        return;
    }
    Node *temp = tail;
    tail = tail->prev;
    temp->prev = NULL;
    tail->next = NULL;
    delete temp;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtEnd(head, tail, 33);
    insertAtEnd(head, tail, 11);
    insertAtEnd(head, tail, 55);
    insertAtEnd(head, tail, 22);
    insertAtEnd(head, tail, 44);
    print(head);
    cout << "\nHead = " << head->data;
    cout << "\nTail = " << tail->data;
    cout << "\n\n";
    delFromEnd(head, tail);
    print(head);
    cout << "\nHead = " << head->data;
    cout << "\nTail = " << tail->data;
}