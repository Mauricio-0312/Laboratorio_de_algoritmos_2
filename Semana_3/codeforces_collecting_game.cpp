#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Alumno: Mauricio Fragachan
Carnet: 2010265

Explicación de merge sort:

Creamos una funcion recursiva (mergeSort) que se va a llamar asi misma dos veces, una vez para el subarray izquierdo y una segunda vez
para el subarray derecho y asi sucesivamente, hasta que lleguemos a subarrays de tamaño 1 (Ese es nuestro caso base). Luego, se ejecuta
la funcion merge, la cual compara los elementos de dos subarrays ordenados para devolver un arreglo con todos los elementos
ordenados. Por ende, esta funcion merge se va ejecutando desde los subarrays de tamaño mas pequeño hasta llegar al arreglo de
tamaño inicial, pero ordenado.

La funcion merge funciona con tres pointers, dos para la posicion actual de cada uno de los dos subarrays a comparar y uno
para la posicion actual del array resultante. Los tres se inicializan a 0 y se empiezan a comparar los elementos y a medida
que se van añadiendo elementos al array resultante ordenado, se van actualizando los palores de los punteros para seguir
comparando los elementos. 

En el caso que al comparar dos subarrays ya no haya mas elementos de un subarray con que comparar, entonces la funcion merge toma
los elementos restantes del otro subarray (el cual ya esta ordenado) y los coloca en el array resultante.

Para resolver este problema, utilice el siguiente razonamiento.

Primero, ordenamos el arreglo usando merge sort. Luego, creamos dos variables (score e index), donde respectivamente vamos a
almacenar el score actual y el indice cuyos elementos a la izquierda los podemos remover habiendo
escogido el elemento actual. Es decir, inicializamos el score a 0, luego le sumamos el valor del primer elemento y vamos 
comparando los elementos a la derecha, si son menores o iguales al score, incrementamos index en una unidad y sumamos el correspondiente 
elemento al score, asi sucesivamente hasta encontrar un elemento que no sea menor o igual que el score. Luego, en la siguiente iteracion,
sabemos que si escogemos el siguiente elemento, todos los elementos que podian ser removidos para el elemento anterior tambien lo
seran para este elemento, por ende, a lo minimo podemos remover index-1 elementos para el nuevo elemento. Luego, vamos a seguir
comparando los elementos a la derecha con el score y repetimos la misma logica. Despues, seguimos con las siguientes iteraciones.

En el caso de que index sea igual al indice del elemento escogido, entonces debemos sumar el valor de dicho elemento al score e
incrementar index por una unidad. Esto sucede en el caso en que para el elemento anterior no hayamos podido remover elementos 
a su derecha porque no cumplen la condición de ser menor o igual que el score.

En cada iteracion almacenamos en un vector la cantidad de elementos que podemos remover para el elemento actual, dicha cantidad
seria igual a index-1. Luego, al final imprimimos todas las cantidades correspondientes para cada elemento.

*/

// Merge two subarrays L and M into arr
void merge(vector<pair<int, int>> &arr, int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  pair<int,int> L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(vector<pair<int, int>> &arr, int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  
  cout << endl;
  
}

vector<pair<int,int > > data;
vector<int> finalNumbers;
int main() {
    int t, n;
    cin >> t;
 
    for(int i =0 ;i < t; i++) {
    
        cin >> n;
        data.resize(n);
        finalNumbers.resize(n);
        for(int j =0 ; j< n; j++) {
            cin >> data[j].first;
            data[j].second = j;
        }
        
        mergeSort(data, 0, n - 1);
        long  long score = 0; 
        int index = 0;
        
        for(int i =0 ; i< n; i++) {
            if (i == index) {
                score += data[i].first;
                index++;
            }
            while( index < n && score >= data[index].first) {
                score += data[index].first;
                index++;
            }
 
            finalNumbers[data[i].second] = index-1;
        }
 
        for(int j=0 ; j< n; j++) {
            cout << finalNumbers[j] << " ";
        }
        cout << endl;
 
    }
 
 
 
    return 0;
}