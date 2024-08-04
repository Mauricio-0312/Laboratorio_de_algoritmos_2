/*
Alumno: Mauricio Fragachan
Carnet: 2010265

Explicacion de la solucion del problema:
Se lee el numero de filas y columnas de la matriz. Luego se inicializa la matriz A de dimensiones n x m con todos sus elementos
inicializados en 1. Luego se lee la matriz B de dimensiones n x m y se actualiza la matriz A de la siguiente manera:
Si un elemento de la matriz B es 0, entonces se actualizan todos los elementos de la fila y columna correspondiente en la matriz A
a 0. Luego se verifica si la matriz A es valida, es decir, para cada fila i y columna j se debe cumplir lo siguiente:

Si al hacer ejecutar la operacion logica OR con las entradas de cada fila i junto a las entradas de la columna j, se debe obtener
el mismo elemento que esta almacenado en B[i][j]. 

Si la matriz A es valida, se imprime "YES" y luego se imprime la matriz A, sino se imprime "NO".

*/

#include <iostream>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    int B[n][m];
    int A[n][m];
    
    //Inicializar los elementos de A en 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            A[i][j] = 1;
        }
    }

    //Leer la matriz B y actualizar la matriz A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            cin >> B[i][j];
            if (B[i][j] == 0) {
                for (int k = 0; k < m; k++) {
                    A[i][k] = 0;
                }
                for (int k = 0; k < n; k++) {
                    A[k][j] = 0;
                }
            }
        }
    }

    //Verificar si la matriz A es valida
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool logicalValue = 0;
            for (int k = 0; k < m; k++) {
                logicalValue = logicalValue || A[i][k];
            }
            for (int k = 0; k < n; k++) {
                logicalValue = logicalValue || A[k][j];
            }
            if (logicalValue != B[i][j]) {
                cout << "NO\n";
                return 0;
            }
        }
        
    }
    
    //Imprimir la matriz A
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}

