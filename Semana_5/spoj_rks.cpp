/*
Alumno: Mauricio Fragachan
Carnet: 2010265

Explicación de la implementación de quick sort:

Se implementa la funcion partition la cual escoje un elemento pivote como el ultimo elemento del arreglo, luego se itera a lo
largo del arreglo desde 0 hasta high-1, donde high es el indice del ultimo elemento. Si se ordena de manera decreciente,
en el momento en que se encuentra un elemento menor que el pivote, se establece un pointer hacia el primer elemento del array
y se intercambian dichos elementos, luego se incrementa dicho pointer y se sigue iterando a lo largo del arreglo, repitiendo el
mismo procedimiento hasta que llegamos al penultimo elemento. Luego se intercambia el pivote con el elemento en la posicion
actual del pointer antes mencionado.

Ahora, si se ordena de manera ascendente, el procedimiento es analogo, pero se estaría chequeando en cada iteracion si el
correspondiente elemento es mayor que el pivote y luego se haria swap con el elemento menor que el pivote, cuya posicion esta dada 
por el pointer antes mencionado.

Luego, despues de haber ejecutado partition, se ejecuta quicksort nuevamente para el subarreglo de la izquierda y para el
subarreglo de la derecha hasta llegar al caso base que esta representado por el escenario cuando el indice del extremo izquierdo del
sub arreglo es mayor que el derecho.

Razonamiento para resolver el problema:

Primero, contaremos las ocurrencias de cada número en el arreglo y además, almacenaremos el indice de la primera ocurrencia de
cada número en el arreglo. Almacenaremos los datos en pares con formato (number, (times, firstIndex)).

Ahora, utilizaremos el algoritmo de quick sort para ordenar dichos pares de manera descendente en base a las ocurrencias
de cada numero. Luego, usando quick sort, ordenaremos los subarreglos cuyos elementos tienen la misma cantidad de ocurrencias,
pero de manera ascendente en base al indice de la primera ocurrencia. De esta manera, tendremos nuestro vector de pares ordenado 
de la forma en que se espera. Por ultimo, se recorre dicho vector de pares y se imprime el numero de cada par tantas veces como 
ocurrencias tengamos almacenadas en el par.


*/

#include <iostream>
#include <vector>
#include <utility>
using namespace std;


// function to rearrange vector (find the partition point)
int partitionByOcurrences(vector<pair<int, pair<int,int>>>& data, int low, int high) {
    // select the rightmost element as pivot
    int pivot = data[high].second.first;

    // pointer for smaller element
    int i = (low - 1);

    // traverse each element of the vector
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (data[j].second.first >= pivot) {
            // if element greater than pivot is found
            // swap it with the smaller element pointed by i
            i++;

            // swap element at i with element at j
            swap(data[i], data[j]);
        }
    }

    // swap pivot with the smaller element at i + 1
    swap(data[i + 1], data[high]);

    // return the partition point
    return (i + 1);
}

// Quick sort algorithm
void quickSortByOcurrences(vector<pair<int, pair<int,int>>>& data, int low, int high) {
    if (low < high) {
        // find the pivot element such that
        // elements greater than pivot are on left of pivot
        // elements smaller than pivot are on right of pivot
        int pi = partitionByOcurrences(data, low, high);

        // recursive call on the left of pivot
        quickSortByOcurrences(data, low, pi - 1);

        // recursive call on the right of pivot
        quickSortByOcurrences(data, pi + 1, high);
    }
}

// function to rearrange vector (find the partition point)
int partitionByIndex(vector<pair<int, pair<int,int>>> &data, int low, int high) {
    
  // select the rightmost element as pivot
  int pivot = data[high].second.second;

    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the vector
    // compare them with the pivot
    for (int j = low; j < high; j++) {
        if (data[j].second.second <= pivot) {
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(data[i], data[j]);
        }
    }

    // swap pivot with the smaller element at i + 1
    swap(data[i + 1], data[high]);

    // return the partition point
    return (i + 1);
}

vector<pair<int, pair<int,int>>> quickSortByIndex(vector<pair<int, pair<int,int>>> &data, int low, int high) {
  if (low < high) {
      
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partitionByIndex(data, low, high);

    // recursive call on the left of pivot
    quickSortByIndex(data, low, pi - 1);

    // recursive call on the right of pivot
    quickSortByIndex(data, pi + 1, high);
  }
  
  return data;
}

int findNumber(vector<pair<int, pair<int,int>>> data, int element){
    for (int i = 0; i < data.size(); i++)
    {
        if(data[i].first == element){
            return i;
        }
    }

    return -1;
}


int main()
{
    int n;
    int c;
    vector<int> message;
    // Format: (number, (times, firstIndex))
    vector<pair<int, pair<int, int>>> data;

    cin >> n >> c;
    
    int number;
    int numberIndex;
    
    //Get inputs and add data to data array
    for(int i = 0; i < n; i++){
        cin >> number;
        message.push_back(number);
        
        numberIndex = findNumber(data, number);
        if(numberIndex != -1){
            data[numberIndex].second.first +=1;
        }else{
            data.push_back(make_pair(number, make_pair(1, i)));
        }
    }

    //Sort by ocurrences of numbers in descending order
    quickSortByOcurrences(data, 0, data.size()-1);
    
    //Sort the subarrays, whose elements have the same ocurrences, by index in ascending order
    for (int i = 0; i < data.size(); i++)
    {
        int size = 0;
        for (int j = i+1; j < data.size(); j++)
        {
            if (data[i].second.first == data[j].second.first)
            {
                size++;
            }else{
                break;
            }
            
        }

        if(size > 0){
          
          quickSortByIndex(data, i, i+size);
        }
        i += size;
        
    }
    
    // Print sorted array
    for (int i = 0; i < data.size(); i++){
        for (int j = 0; j < data[i].second.first; j++){
            cout << data[i].first << " ";
        }
    }
    return 0;
}

