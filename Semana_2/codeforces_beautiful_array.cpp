/*
Alumno: Mauricio Fragachan
Carnet: 2010265

Para resolver este problema, utilice el siguiente razonamiento:

Queremos computar la belleza del array, la cual viene dada por la sum de los terminos (ai−ai−1) para 1<=i<n, donde 
cada ai representa un elemento del array. Ahora, estudiando dicha sumatoria, obtenemos que es una serie telescopica que se reduce
a la siguiente expresion:

(a1−a0)+ (a2−a1)+(a3−a2)+(a4−a3)+...+(an-2−an-3)+(an-1−an-2) = (an-1-a0)

donde an-1 es el maximo del array y a0 es el minimo del array.

Por ende, para computar la belleza del array basta con encontrar el maximo y el minimo del array y luego ejecutar su diferencia.
No es necesario ordenar el array, solo encontrar el maximo y el minimo.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
    int n, t;
    cin >> t;
    int number;
    int maximum, minimum;

    while (t > 0)
    {
      cin >> n;
      int array[n];
      for (int i = 0; i < n; i++){
          cin >> number;
          array[i] = number;
      }

      maximum = array[0];
      minimum = array[0];

      for (int j = 1; j < n; j++)
      {
        if (maximum < array[j]){
          maximum = array[j];
        }
        
        if (minimum > array[j]){
          minimum = array[j];
        }


      }
      
      t--;
      cout << maximum - minimum << endl;
    }
    
    return 0;
}

