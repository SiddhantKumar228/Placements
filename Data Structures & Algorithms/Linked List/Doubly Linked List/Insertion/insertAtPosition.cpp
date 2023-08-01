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

// Inserting node at Position
void insertAtPos(Node *&head, Node *&tail, int pos, int val)
{
    Node *newNode = new Node(val);

    // Count the number of nodes
    Node *temp = head;
    int count = 1;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    // Position is first
    if (pos == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Position is last
    else if (pos == count)
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Position is mid
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        count = 1;
        while (count < pos)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        newNode->prev = prev;
        prev->next = newNode;
        newNode->next = curr;
        curr->prev = newNode;
    }
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

    insertAtPos(head, tail, 1, 23);
    insertAtPos(head, tail, 2, 35);
    insertAtPos(head, tail, 3, 47);
    insertAtPos(head, tail, 4, 67);
    insertAtPos(head, tail, 5, 89);

    insertAtPos(head, tail, 3, 40);
    print(head);
    cout << "\n";
    cout << "\nHead = " << head->data;
    cout << "\nTail = " << tail->data;
}