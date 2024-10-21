#include <iostream>
using namespace std;

class Node
{
public:
    int coefficient;
    int exponent;
    Node *next;

    Node(int coefficient, int exponent)
    {
        this->coefficient = coefficient;
        this->exponent = exponent;
        this->next = NULL;
    }
};

void displayPolynomial(Node *poly)
{
    while (poly != NULL)
    {
        cout << poly->coefficient << "x^" << poly->exponent;
        if (poly->next != NULL)
        {
            cout << "+";
        }
        poly = poly->next;
    }
    cout << endl
         << endl;
    return;
}

Node *addPolynomial(Node *&poly1, Node *&poly2)
{
    Node *result = NULL;
    Node **lastPtrRef = &result;

    while (poly1 != NULL || poly2 != NULL)
    {
        int coef = 0;
        int expo = 0;

        if (poly1 != NULL && (poly2 == NULL || poly1->exponent > poly2->exponent))
        {
            coef = poly1->coefficient;
            expo = poly1->exponent;
            poly1 = poly1->next;
        }
        else if (poly2 != NULL && (poly1 == NULL || poly2->exponent > poly1->exponent))
        {
            coef = poly2->coefficient;
            expo = poly2->exponent;
            poly2 = poly2->next;
        }
        else
        {
            coef = poly1->coefficient + poly2->coefficient;
            expo = poly1->exponent;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        Node *newNode = new Node(coef, expo);
        *lastPtrRef = newNode;
        lastPtrRef = &newNode->next;
    }
    return result;
}

int main()
{
    // Create a polynomial 3x^2 + 4x^1 + 5
    Node *poly1 = new Node(3, 3);
    poly1->next = new Node(4, 2);
    poly1->next->next = new Node(5, 1);
    poly1->next->next->next = new Node(11, 0);
    cout << "Pollynomial 1 :";
    displayPolynomial(poly1);

    // Create a polynomial 5x^2 + 9x^1 + 1
    Node *poly2 = new Node(5, 2);
    poly2->next = new Node(9, 1);
    poly2->next->next = new Node(1, 0);
    cout << "Pollynomial 2 :";
    displayPolynomial(poly2);

    cout << "After Addition of polynomial" << endl;
    Node *res = addPolynomial(poly1, poly2);
    cout << "Resultant polynomial = ";
    displayPolynomial(res);

    return 0;
}