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

// Insert new node at position
void insertAtPos(Node *&head, Node *&tail, int pos, int val)
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
    // Count the number of nodes
    Node *temp = head;
    int count = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    // Position is beginning
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
    }

    // Position is End
    else if (pos == count + 1)
    {
        tail->next = newNode;
        tail = newNode;
    }
    // Position is middle
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
        prev->next = newNode;
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
    insertAtPos(head, tail, 1, 34);
    insertAtPos(head, tail, 2, 45);
    insertAtPos(head, tail, 3, 53);
    insertAtPos(head, tail, 4, 67);

    insertAtPos(head, tail, 1, 29);
    insertAtPos(head, tail, 6, 78);
    insertAtPos(head, tail, 3, 50);

    print(head);
    cout << "\n";
    cout << "head = " << head->data << "\n";
    cout << "tail = " << tail->data;
}