/*
Alumno: Mauricio Fragachan
Carnet: 2010265

Explicación de la implementación de bubble sort:

Si el arreglo tiene n elementos, recorremos el arreglo n-1 veces. Luego, dentro de cada iteración vamos comparando
todos los elementos adyacentes y si no cumplen la condicion de ordenamiento (ya sea ascendente o descendente), entonces se
intercambian los elementos.

En el caso que ordenemos de manera ascendente, tenemos que al final de la primera iteración por el arreglo, el ultimo elemento
representara el maximo del arreglo, es decir, ya ese ultimo elemento lo podemos considerar ordenado y por ende ya no lo 
compararemos con otros elementos en las siguientes iteraciones (Si hubieramos ordenado de manera descendente, dicho elemento
representaria el minimo del array). Extendiendo la idea, despues al final de la segunda iteracion,
tendremos que el penultimo elemento ya lo podremos considerar como ordenado. Por ende, en las siguientes iteraciones, tampoco
lo compararemos con otros elementos. De esta manera, en cada iteracion a lo largo del arreglo, vamos a asumir los i elementos
del final del array como ya ordenados, donde i representa el numero de iteracion (0<=i<n-1)

Razonamiento para resolver el problema:

Primero, contaremos las ocurrencias de cada número en el arreglo y además, almacenaremos el indice de la primera ocurrencia de
cada número en el arreglo. Almacenaremos los datos en pares con formato (number, (times, firstIndex)).

Ahora, utilizaremos el algoritmo de bubble sort para ordenar dichos pares de manera descendente en base a las ocurrencias
de cada numero. Luego, ordenaremos nuevamente los pares usando bubble sort, pero de manera ascendente en base al indice de la 
primera ocurrencia. De esta manera, tendremos nuestro vector de pares ordenado de la manera en que se espera. Por ultimo, 
se recorre dicho vector de pares y se imprime el numero de cada par tantas veces como ocurrencias tengamos almacenadas en el par.


*/

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void bubbleSortByTimes(vector<pair<int, pair<int,int>>> &data) 
{ 
    int i, j;
    int n = data.size();

    for (i = 0; i < n - 1; i++) 
  
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) 
            if (data[j].second.first < data[j + 1].second.first) 
                swap(data[j], data[j + 1]); 
} 

void bubbleSortByIndex(vector<pair<int, pair<int,int>>> &data) 
{ 
    int i, j;
    int n = data.size();

    for (i = 0; i < n - 1; i++) 
  
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++) 
            if (data[j].second.first == data[j + 1].second.first && data[j].second.second > data[j + 1].second.second) 
                swap(data[j], data[j + 1]); 
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

    bubbleSortByTimes(data);
    
    bubbleSortByIndex(data);
    
    for (int i = 0; i < data.size(); i++){
        for (int j = 0; j < data[i].second.first; j++){
            cout << data[i].first << " ";
        }
    }
    return 0;
}

