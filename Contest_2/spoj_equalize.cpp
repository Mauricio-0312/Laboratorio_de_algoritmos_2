/*
Alumno: Mauricio Fragachan
Carnet: 2010265

Explicacion de la solucion del problema:
Se utilizo la siguiente logica. Como se quiere hallar el numero maximo de elementos tal que al sumar una permutacion, 
se obtiene el mismo elemento. Entonces, primero se crea un vector que no contenga elementos repetidos y ademas se ordenan los
elementos de manera ascendente. Luego, como la permutacion esta compuesta por numeros entre 1 y n, entonces se va a proceder
de la siguiente manera:

Se computa cuanto es el primer elemento mas n, luego como el arreglo esta ordenado de manera ascendente, tenemos que para cada
proximo elemento que sea menor que el valor computado, existira algun numero entre 1 y n tal que al sumar dicho numero con 
dicho elemento se obtendra el valor computado. Luego, para hallar cual es la cantidad de elementos que cumplen dicha propiedad,
se encuentra cual es la cota inferior del valor computado.

Luego, este proceso se ejecuta con cada elemento del vector. Se procede a computar la suma del elemento con n y luego a hallar la 
correspondiente cota inferior y luego la cantidad de elementos que cumplen la propiedad de que al sumarle la permutacion produzcan 
el mismo numero computado.

A medida que se recorren los elementos, se va comparando la cantidad de elementos que producen cierto valor con la nueva cantidad 
de elementos que producen el nuevo valor al sumarle la permutacion. De manera tal que se halle cual es el maximo.

Para finalizar, se imprime por consola el numero maximo de elementos que cumplen la propiedad despues de sumar una cierta
permutacion de los elementos que van de 1 a n.
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;


        int element;
        set<int> uniqueElements;
        
        for (int i = 0; i < n; i++){
            cin >> element;
            uniqueElements.insert(element);
        }

        vector<int> elements(uniqueElements.begin(), uniqueElements.end());
        sort(elements.begin(), elements.end());
        
        
        int maxNumberofElements = 0;
        for (int i = 0; i < elements.size(); i++)
        {   
            int j = i;
            auto lowerBound = lower_bound(elements.begin(), elements.end(), elements[i] + n);
           
            int possibleMax = lowerBound - elements.begin() - i;
            maxNumberofElements = max(maxNumberofElements, possibleMax);
        }
 

        cout << maxNumberofElements << "\n";

    }


    return 0;
}