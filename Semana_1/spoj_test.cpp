/*
Alumno: Mauricio Fragachan
Carnet: 2010265

A medida que se van introduciendo los inputs en el programa, se imprimen por pantalla y se va comparando uno por uno si es igual 
a 42. En caso afirmativo, se detiene el programa. En caso contrario, el programa se sigue ejecutando.
*/

#include <iostream>
using namespace std;

int main()
{
    
    int x;
    while (true){
        cin >> x;
        if(x == 42){
            break;
        }
        cout << x << endl;
    }
    
    return 0;
}
