#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void display(Node *&head)
{
    if (head == NULL)
    {
        cout << "Stack is empty." << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

void peek(Node *&head)
{
    if (head == NULL)
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "Elements at top of stack is : " << head->data;

    return;
}

void push(Node *&head, int d)
{
    Node *newNode = new Node(d);
    newNode->next = head;
    head = newNode;

    return;
}

void pop(Node *&head)
{
    if (head == NULL)
    {
        cout << "Stack is empty." << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

int main()
{
    Node *head = NULL;

    push(head, 50);
    push(head, 40);
    push(head, 30);
    push(head, 20);
    push(head, 10);
    display(head);
    pop(head);
    display(head);
    peek(head);

    return 0;
}
