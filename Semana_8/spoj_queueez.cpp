/*
Alumno: Mauricio Fragachan
Carnet: 2010265

Explicacion de la solucion del problema: 
Se implementa una cola usando una lista doblemente enlazada circular. La cola tiene tres operaciones:
1. Enqueue: Agregar un elemento al final de la cola
2. Dequeue: Eliminar el elemento del frente de la cola
3. getFront: Obtener el elemento del frente de la cola

Se decidio implementar la cola usando una lista doblemente enlazada circular ya que esta estructura de datos permite agregar y
eliminar elementos del inicio y del final de la cola en tiempo constante.

El codigo lee el numero de queries y luego procesa cada query. Si la query es de tipo 1, se agrega un elemento a la cola.
Si la query es de tipo 2, se elimina el elemento del frente de la cola. Si la query es de tipo 3, se imprime el elemento del
frente de la cola en caso de no estar vacia, sino se imprime "Empty".


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

    bool isEmpty() {
        return head == nullptr;
    }

    int getHead() {
        if (head == nullptr) {
            return -1;
        }
        return head->data;
    }
};

class Queue {
private:
    CircularDoublyLinkedList list;

public:
    void enqueue(int value) {
        list.insert(value);
    }

    void dequeue() {
        list.deleteFront();
    }

    bool isEmpty() {
        return (list.isEmpty());
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return list.getHead();
    }

};

//main function
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Variables to store the number of queries and the type of query
    int t, queryType;
    cin >> t;

    Queue *queue = new Queue;

    // Loop through the queries
    while (t != 0) {
        cin  >> queryType;
        int element;

        // If the query is of type 1
        if (queryType == 1) {
            // Read the element
            cin >> element;

            // Add the element to the queue
            queue->enqueue(element);
            // cout << "\n";
        }
        // If the query is of type 2
        else if (queryType == 2) {
            // Remove an element from the queue
            queue->dequeue();
            // cout << "\n";
        }
        else if (queryType == 3) {
            // Print the element at the front of the queue
            int front = queue->getFront();
            // cout << front << "\n";
            if (front == -1)
            {
                /* code */
                cout << "Empty!\n";
            }else{

                cout << front << "\n";
            }
            
        }

        t--;
    }

    return 0;
}