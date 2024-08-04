/*
Alumno: Mauricio Fragachan
Carnet: 2010265

Para resolver este ejercicio utilice el siguiente razonamiento:

A medida que se van pidiendo los inputs (sushis), se van añadiendo correspondientemente a un arreglo de la siguiente manera:

Si el sushi nuevo ingresado es igual al anterior, se incrementan las ocurrencias del sushi anterior. Se estan almacenando en un
vector, cuyos elementos son pares cuya primera coordenada es el tipo de sushi y la segunda coordenada es la cantidad de ocurrencias
seguidas de dicho sushi.

En caso de que el nuevo sushi no sea igual al anterior, se crea un nuevo par con una ocurrencia a dicho vector de pares. Además,
aca se chequea el tamaño del posible segmento entre los dos pares anteriores de sushis. Se escoge como tamaño la cantidad
de ocurrencias minima entre ambos sushis y la multiplicamos por dos, ya que dicho segmento tendría una mitad conformada por un tipo
de sushi y la otra mitad conformada por otro tipo de sushi. Luego, se calcula el maximo entre el tamaño del segmento maximo
previo junto al nuevo tamaño calculado.

Despues de agregar el ultimo sushi, se procede a chequear el tamaño del segmento entre los dos ultimos pares de sushis del vector
y se calcula el maximo junto con el maximo tamaño previo.

Para finalizar, se imprime el tamaño del segmento mas grande que cumple la propiedad de tener una mitad conformada por sushis de 
un tipo y otra mitad conformada por sushis de otro tipo.

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n;
    // Format: (sushiNumber, ocurrences)
    vector<pair<int, int>> data;
    
    int maximumSegment = 2;
    cin >> n;
    
    int number;
    int numberIndex;
    
    //Get inputs and add data to data array
    for(int i = 0; i < n; i++){
        int sushi;
        cin >> sushi;
        
        if(data.size() > 0 && data[data.size()-1].first == sushi){
            data[data.size()-1].second +=1;
        }else{

            if (data.size() >= 2){
                maximumSegment = max(maximumSegment, 2*min(data[data.size()-1].second, data[data.size()-2].second));
            }
            
            //Add the new sushi to the data array along with the first ocurrence
            data.push_back(make_pair(sushi, 1));
        }
    }
    
    if (data.size() >= 2){
        maximumSegment = max(maximumSegment, 2*min(data[data.size()-1].second, data[data.size()-2].second));
    }

    cout << maximumSegment << endl;

    return 0;
}