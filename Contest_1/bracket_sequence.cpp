/*
Alumno: Mauricio Fragachan
Carnet: 2010265

El razonamiento que utilice para resolver este ejercicio es el siguiente:

Primero, se debe leer la secuencia de brackets dada. Luego, se crea un vector que almacene los brackets de apertura
que se vayan encontrando en la secuencia. Adicionalmente, se debe llevar un contador de la cantidad de reemplazos que 
se deben hacer para que la secuencia sea valida. Luego, se recorre la secuencia de brackets y se hace lo siguiente:

1) Si el bracket es de apertura, se agrega al vector de brackets de apertura.

2) Si el bracket es de cierre, se verifica si el vector de brackets de apertura no esta vacio. Si no esta vacio, se verifica
si el bracket de cierre corresponde al bracket de apertura que esta en la ultima posicion del vector. Si no corresponde, se incrementa
el contador de reemplazos. Luego, se elimina el bracket de apertura que esta en la ultima posicion del vector. Ahora, si el vector
de brackets de apertura hubiera estado vacio, se imprime "Impossible", ya que en este caso tendriamos que hay un bracket de cierre 
que no cuenta con un correspondiente bracket de apertura.

3) Si al final del recorrido del vector de brackets, el vector de brackets de apertura no esta vacio, se imprime "Impossible",
ya que esto significa que hay brackets de apertura que no cuentan con un correspondiente bracket de cierre. Pero, en caso contrario,
si el vector de brackets de apertura esta vacio, se imprime la cantidad de reemplazos que se deben hacer para que la secuencia
sea valida.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string bracketSequence = "";
    vector<char> openingBrackets;
    int numberOfReplaces = 0;

    cin >> bracketSequence;

    for (int i = 0; i < bracketSequence.size(); i++) {
        
        if(bracketSequence[i] == '(' || bracketSequence[i] == '[' || bracketSequence[i] == '{' || bracketSequence[i] == '<'){
            openingBrackets.push_back(bracketSequence[i]);
        }

        if(bracketSequence[i] == ')' || bracketSequence[i] == ']' || bracketSequence[i] == '}' || bracketSequence[i] == '>'){
            if (openingBrackets.size() > 0)
            {   
                if ((openingBrackets[openingBrackets.size()-1] == '(' && bracketSequence[i] != ')') ||
                (openingBrackets[openingBrackets.size()-1] == '{' && bracketSequence[i] != '}') ||
                (openingBrackets[openingBrackets.size()-1] == '[' && bracketSequence[i] != ']') ||
                (openingBrackets[openingBrackets.size()-1] == '<' && bracketSequence[i] != '>')){
                    
                    numberOfReplaces++;
                }
                openingBrackets.pop_back();
                
            }else{
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    if (openingBrackets.size() == 0)
    {
        cout << numberOfReplaces << endl;
        return 0;
    }else{
        cout << "Impossible" << endl;
    }
    

    return 0;
}