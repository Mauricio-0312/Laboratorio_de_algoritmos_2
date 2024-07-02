/*
Alumno: Mauricio Fragachan
Carnet: 2010265

Explicacion de la solucion del problema: 
Se implementa una pila usando una lista doblemente enlazada circular. La pila tiene tres operaciones:
1. Push: Agregar un elemento al tope de la pila
2. Pop: Eliminar el tope de la pila
3. Front: Obtener el elemento del tope de la pila

Se decidio implementar la pila usando una lista doblemente enlazada circular ya que esta estructura de datos permite agregar y
eliminar elementos del frente y del final de la pila en tiempo constante.

El codigo lee el numero de queries y luego procesa cada query. Si la query es de tipo 1, se agrega un elemento a la pila.
Si la query es de tipo 2, se elimina el tope de la pila. Si la query es de tipo 3, se imprime el tope de la pila en 
caso de no estar vacia, sino se imprime "Empty!".

*/

#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class CircularDoublyLinkedList {
private:
    Node* head;

public:
    CircularDoublyLinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;

        if (head == nullptr) {
            // If the list is empty, make the new node the head
            head = newNode;
            head->prev = head;
            head->next = head;
        } else {
            // Insert the new node at the end of the list
            Node* lastNode = head->prev;
            lastNode->next = newNode;
            newNode->prev = lastNode;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void deleteFront() {
        if (head == nullptr) {
            // List is empty, nothing to delete
            return;
        }

        if (head->next == head) {
            // Only one node in the list, delete it and set head to nullptr
            delete head;
            head = nullptr;
        } else {
            // More than one node in the list, delete the head node
            Node* nextNode = head->next;
            Node* lastNode = head->prev;

            nextNode->prev = lastNode;
            lastNode->next = nextNode;

            delete head;
            head = nextNode;
        }
    }

    void deleteBack() {
        if (head == nullptr) {
            // List is empty, nothing to delete
            return;
        }

        if (head->next == head) {
            // Only one node in the list, delete it and set head to nullptr
            delete head;
            head = nullptr;
        } else {
            // More than one node in the list, delete the last node
            Node* lastNode = head->prev;
            Node* prevNode = lastNode->prev;

            prevNode->next = head;
            head->prev = prevNode;

            delete lastNode;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    int getHead() {
        if (head == nullptr) {
            return -1;
        }
        return head->data;
    }

    int getLastElement() {
        if (head == nullptr) {
            return -1;
        }
        return head->prev->data;
    }
};

class Stack {
private:
    CircularDoublyLinkedList list;

public:
    void push(int value) {
        list.insert(value);
    }

    void pop() {
        list.deleteBack();
    }

    bool isEmpty() {
        return (list.isEmpty());
    }

    int getTop() {
        if (isEmpty()) {
            return -1;
        }
        return list.getLastElement();
    }

};

//main function
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Variables to store the number of queries and the type of query
    int t, queryType;
    cin >> t;

    Stack *stack = new Stack;

    // Loop through the queries
    while (t != 0) {
        cin  >> queryType;
        int element;

        // If the query is of type 1
        if (queryType == 1) {
            // Read the element
            cin >> element;

            // Add the element to the stack
            stack->push(element);
            
        }
        // If the query is of type 2
        else if (queryType == 2) {
            // Remove an element from the stack
            stack->pop();
            
        }
        else if (queryType == 3) {
            // Print the element at the top of the stack
            int top = stack->getTop();
            
            if (top == -1)
            {
                /* code */
                cout << "Empty!\n";
            }else{

                cout << top << "\n";
            }
            
        }

        t--;
    }

    return 0;
}