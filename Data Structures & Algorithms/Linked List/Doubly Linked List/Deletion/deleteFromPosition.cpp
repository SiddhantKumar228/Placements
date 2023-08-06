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

void insertAtPos(Node *&head, Node *&tail, int pos, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    Node *temp = head;
    int count = 1;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (pos == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else if (pos == count + 1)
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else
    {
        count = 1;
        Node *prev = NULL;
        Node *curr = head;
        while (count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        newNode->next = curr;
        newNode->prev = prev;
        curr->prev = newNode;
        prev->next = newNode;
    }
}

void delFromPos(Node *&head, Node *&tail, int pos)
{
    if (head == NULL)
    {
        cout << "Underflow";
        return;
    }
    Node *temp = head;
    int count = 1;
    while (temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (pos == 1)
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else if (pos == count)
    {
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
    }
    else
    {
        count = 1;
        Node *prev = NULL;
        Node *curr = head;
        while (count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next->prev = prev;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
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
    insertAtPos(head, tail, 1, 11);
    insertAtPos(head, tail, 2, 22);
    insertAtPos(head, tail, 3, 33);
    insertAtPos(head, tail, 4, 44);
    insertAtPos(head, tail, 5, 55);
    insertAtPos(head, tail, 6, 66);
    insertAtPos(head, tail, 7, 77);
    print(head);
    cout << "\nHead = " << head->data;
    cout << "\nTail = " << tail->data;
    cout << "\n\n";
    delFromPos(head, tail, 1);
    print(head);
    cout << "\n";
    delFromPos(head, tail, 6);
    print(head);
    cout << "\n";
    delFromPos(head, tail, 3);
    print(head);
    cout << "\nHead = " << head->data;
    cout << "\nTail = " << tail->data;
}