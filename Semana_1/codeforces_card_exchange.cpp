/*
Alumno: Mauricio Fragachan
Carnet: 2010265
Para resolver el problema de las cartas, utilice el siguiente razonamiento:

Caso I
Si al contar las ocurrencias de cada numero dado en el arreglo de entrada llega a haber un numero que aparece k veces como minimo, 
entonces luego k-1 cartas con ese numero las puedo sustituir con otro numero cualquiera que aprezca en el arreglo, luego tendria a lo minimo
k cartas con ese nuevo numero, por ende, el mismo procedimiento se podria ejecutar con dichas k cartas. Luego, tendriamos que
cuando nuestro arreglo llegue a tener k-1, no podriamos seguir implementando la logica anterior. Por lo tanto, para este primer 
caso, el algoritmo siempre va a retornar k-1 como la cantidad de cartas finales despues de ejecutar la logica varias veces.

Caso II
Si al contar las ocurrencias de cada numero dado en el arreglo de entrada NO llega a haber un numero que aparece k veces como
minimo, entonces no se puede aplicar la logica de remover 1 de esas cartas y sustituir k-1 de ellas. Por ende, en este caso, el
algoritmo retorna n, es decir, el numero de cartas dadas al inicio.

Caso III
Si k > n, entonces no hay ningún número que aparezca k en el arreglo, por ende, tambien se retorna n como en el Caso II.

Es importante notar que el algoritmo chequea primero el caso I y si no se cumple, entonces retorna n, el cual es el output
de tanto el caso II como el caso III.
*/ 


#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t = 0;
    int n = 0;
    int k = 0;

    cin >> t;

    int number = 0;
    
    vector<int> ocurrences;

    while(t > 0){
        ocurrences.clear();
        ocurrences.resize(101);
        cin >> n >> k;
        
        //Format (number, ocurrences)
        pair<int,int> maximumOcurrence = make_pair(0,0);
        
        for (int i = 0; i < n; i++){
            cin >> number;

            ocurrences[number] += 1;
            
            if(maximumOcurrence.second < ocurrences[number]){
                maximumOcurrence = make_pair(number, ocurrences[number]);
            }
        }
        

        if (maximumOcurrence.second >= k){
            cout << k-1 << endl;
        }else{
            cout << n << endl;
        }

        t--;
    }
    
    return 0;
}



