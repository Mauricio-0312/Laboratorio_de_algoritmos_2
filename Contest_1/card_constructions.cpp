/*
Alumno: Mauricio Fragachan
Carnet: 2010265

Para resolver este ejercicio, utilice el siguiente razonamiento:

Primero, desarrolle una formula cerrada para obtener el numero de cartas que se necesitan para crear una piramide de altura h,
la cual se deduce del hecho que hay que hallar el numero de cartas de la base y luego sumarle el numero de cartas de la subpiramide 
de arriba que es de altura h-1. Luego, se sabe que la base esta compuesta por 2*h cartas. Pero, para la subpiramide, la base
correspondiente viene dada por 3*h, ya que cada arreglo de dos cartas cuenta con una carta en su base que las conecta. De esta 
manera, habria que sumar las bases de las subsecuentes subpiramides. Es decir, obtendriamos la siguiente formula

cards = 2h + Sumatoria de 3*i desde i=1 hasta i=h-1

Dicha sumatoria se puede escribir con una formula cerrada dada por (h-1)(h)/2. Luego, sustituyendo dicha formula cerrada y 
haciendo aritmetica, tenemos:

cards = (3h*h +h)/2

Ahora, con el uso de esta formula cerrada, creamos funciones para computar la cantidad de cartas para una piramide de altura h
y para computar la altura dada la cantidad de cartas. Luego,el procedimiento para resolver el ejercicio lo descomponemos de la 
siguiente manera:

1) Computar la altura de la piramide mas grande que se puede computar con n cartas dadas
2) Encontrar la cantidad de cartas que en realidad se necesitan para construir dicha piramide
3) Establecer la cantidad de cartas disponibles igual a las cartas restantes que no se usaron para la piramide actual
4) Luego, incrementar el contador de piramides posibles
5) Volver a repetir el mismo procedimiento siempre y cuando tengamos al menos 2 cartas disponibles, ya que la minima piramide que 
se puede obtener esta compuesta por dos cartas.
6) Retornar el valor de la variable que tuvo el rol de contador de piramides.

*/

#include <iostream>
#include <cmath>
using namespace std;

long long heightOfPyramid(long long cards) {
    return (-1 + sqrt(1 + 24 * cards)) / 6;;
}

long long cardsForPyramid(long long height) {
    return (3 * height * height + height) / 2;
}

int main() {
    
    int t;
    long long cards;

    cin >> t;

    while (t != 0) {
        cin >> cards;
        int numberOfPyramids = 0;
        long long height = heightOfPyramid(cards);

        
        while (cards >= 2) {
            cards -= cardsForPyramid(height);
            height = heightOfPyramid(cards);
            numberOfPyramids++;
        }

        t--;
        cout << numberOfPyramids << endl;
    }    

    return 0;
}