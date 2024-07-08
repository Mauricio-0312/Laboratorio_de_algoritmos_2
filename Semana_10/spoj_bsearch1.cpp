/*
Alumno: Mauricio Fragachan
Carnet: 2010265

Explicacion de la solucion del problema:
Se implemento un arbol rojo negro para guardar los datos que se van recibiendo por consola. Cada nodo del arbol guarda el elemento
insertado y su respectivo indice en un campo de tipo par, ademas cada nodo contiene los respectivos apuntadores a los nodos hijos 
y al nodo padre.

Como los datos que se reciben estan ordenados, se chequea primero si el dato introducido previamente es exactamente el mismo que 
el que se desea introducir actualmente, en caso afirmativo, se omite la insercion del elemento, sino se inserta dicho elemento
junto a su indice en el arbol. Esto se hace, ya que lo que se quiere saber luego en cada query es el indice de la primera 
ocurrencia del elemento solicitado, por ende solo se inserta cada elemento una vez junto a su respectivo indice que representa la
primera ocurrencia de si mismo.

Luego, al recibir cada query, se busca en el arbol rojo negro si el elemento solicitado esta presente en el arbol, esto se hace
usando el metodo buscar del arbol. Si el elemento esta presente, se imprime por consola el elemento, sino se imprime -1.

*/

#include <iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    pair<int,int> data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int index, int val) : data(index, val), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
public:
    Node* root;

    RedBlackTree() : root(nullptr) {}

    void rotateLeft(Node* node) {
        Node* rightChild = node->right;
        node->right = rightChild->left;

        if (rightChild->left != nullptr) {
            rightChild->left->parent = node;
        }

        rightChild->parent = node->parent;

        if (node->parent == nullptr) {
            root = rightChild;
        } else if (node == node->parent->left) {
            node->parent->left = rightChild;
        } else {
            node->parent->right = rightChild;
        }

        rightChild->left = node;
        node->parent = rightChild;
    }

    void rotateRight(Node* node) {
        Node* leftChild = node->left;
        node->left = leftChild->right;

        if (leftChild->right != nullptr) {
            leftChild->right->parent = node;
        }

        leftChild->parent = node->parent;

        if (node->parent == nullptr) {
            root = leftChild;
        } else if (node == node->parent->left) {
            node->parent->left = leftChild;
        } else {
            node->parent->right = leftChild;
        }

        leftChild->right = node;
        node->parent = leftChild;
    }

    void fixInsertion(Node* node) {
        while (node != root && node->parent->color == RED) {
            if (node->parent == node->parent->parent->left) {
                Node* uncle = node->parent->parent->right;

                if (uncle != nullptr && uncle->color == RED) {
                    node->parent->color = BLACK;
                    uncle->color = BLACK;
                    node->parent->parent->color = RED;
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->right) {
                        node = node->parent;
                        rotateLeft(node);
                    }

                    node->parent->color = BLACK;
                    node->parent->parent->color = RED;
                    rotateRight(node->parent->parent);
                }
            } else {
                Node* uncle = node->parent->parent->left;

                if (uncle != nullptr && uncle->color == RED) {
                    node->parent->color = BLACK;
                    uncle->color = BLACK;
                    node->parent->parent->color = RED;
                    node = node->parent->parent;
                } else {
                    if (node == node->parent->left) {
                        node = node->parent;
                        rotateRight(node);
                    }

                    node->parent->color = BLACK;
                    node->parent->parent->color = RED;
                    rotateLeft(node->parent->parent);
                }
            }
        }

        root->color = BLACK;
    }

    Node* searchNode(Node* node, int val) {
        if (node == nullptr || node->data.second == val) {
            return node;
        }

        if (val < node->data.second) {
            return searchNode(node->left, val);
        }

        return searchNode(node->right, val);
    }

    void insert(int index, int val) {
        Node* newNode = new Node(index, val);

        Node* current = root;
        Node* parent = nullptr;

        while (current != nullptr) {
            parent = current;

            if (val < current->data.second) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        newNode->parent = parent;

        if (parent == nullptr) {
            root = newNode;
        } else if (val < parent->data.second) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }

        fixInsertion(newNode);
    }

    bool search(int val) {
        Node* node = searchNode(root, val);
        return (node != nullptr);
    }


    
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    int previousInsertedNumber = 1000000001;
    RedBlackTree tree;

    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        
        if (num != previousInsertedNumber){

            tree.insert(i, num);
            previousInsertedNumber = num;
        }
    }

    for (int j = 0; j < Q; j++) {
        int queriedNumber;
        cin >> queriedNumber;
        Node* node = tree.searchNode(tree.root, queriedNumber);
        if (node != nullptr) {
            cout << node->data.first << "\n";
        } else {
            cout << -1 << "\n";
        }

    }

    return 0;
}