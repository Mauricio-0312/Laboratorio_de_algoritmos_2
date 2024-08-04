/*
Alumno: Mauricio Fragachan
Carnet: 2010265

Explicacion de la solucion del problema:
Primero, se guarda en un arreglo el minimo caracter de los sufijos de la cadena s. Luego, se recorre la cadena s y se verifica si
el string t esta vacio y si el minimo caracter del sufijo de s es mayor o igual al ultimo caracter de t. Si se cumple la condicion,
se agrega el ultimo caracter de t al string u y se elimina el ultimo caracter de t. Sino, si el minimo caracter del sufijo de s es igual
al caracter actual de s, se agrega el caracter actual de s al string u. Sino, se agrega el caracter actual de s al string t. Al final,
se agregan los caracteres restantes de t al string u.

*/

#include <iostream>
using namespace std;

int main() {
    string s, t, u;
    cin >> s;

    int N = s.size();
 
    // minimumCharOfSuffix Array
    int minimumCharOfSuffix[N + 1];
 
    minimumCharOfSuffix[N] = 1000000000;
 
    // Loop to calculate the minimum character of the suffix that goes from the ith element to the last element of the string. The
    // corresponding minimun element is stored at minimumCharOfSuffix[i].
    for (int i = N - 1; i >= 0; i--) {
        minimumCharOfSuffix[i] = min(minimumCharOfSuffix[i + 1], (int)s[i]);
    }
 
    // Loop to traverse string
    for (int i = 0; i < N; i++) {
        // If t is not empty and minimumCharOfSuffix[i]
        // is greater than or equal to the last character of t
        if (t.size() > 0 && minimumCharOfSuffix[i] >= t[t.size() - 1]) {
            u += t[t.size() - 1];
            t = t.substr(0, t.size() - 1);
            i--;
        }
 
        // If minimumCharOfSuffix[i] is equal to s[i]
        else if (minimumCharOfSuffix[i] == s[i]) {
            u += s[i];
        }
 
        // Otherwise push character
        // s[i] into the string t
        else {
            t += s[i];
        }
    }
 
    // Append all remaining characters
    // of t into string u
    while (t.size() > 0) {
        u += t[t.size() - 1];
        t = t.substr(0, t.size() - 1);
    }
 
    cout << u << endl;

    return 0;
}