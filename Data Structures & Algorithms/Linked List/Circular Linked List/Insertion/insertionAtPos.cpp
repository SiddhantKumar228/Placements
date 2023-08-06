#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

void insertCreate(Node *&head, Node *&tail, int val)
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
    tail->next = head;
}

void insertAfter(Node *&head, Node *&tail, int after, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    while (temp->data != after)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertBefore(Node *&head, Node *&tail, int before, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    while (temp->next->data != before)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void print(Node *head, Node *tail)
{
    Node *temp = head;
    while (temp != tail)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertCreate(head, tail, 1);
    insertCreate(head, tail, 3);
    insertCreate(head, tail, 5);
    insertCreate(head, tail, 7);
    print(head, tail);
    cout << "\n";
    // insert after
    insertAfter(head, tail, 3, 4);
    print(head, tail);
    cout << "\n";
    // insert before
    insertBefore(head, tail, 7, 6);
    print(head, tail);
}