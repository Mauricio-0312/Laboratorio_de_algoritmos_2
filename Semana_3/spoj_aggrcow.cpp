/*
Alumno: Mauricio Fragachan
Carnet: 2010265

Explicación de merge sort:

Creamos una funcion recursiva (mergeSort) que se va a llamar asi misma dos veces, una vez para el subarray izquierdo y una segunda vez
para el subarray derecho y asi sucesivamente, hasta que lleguemos a subarrays de tamaño 1 (Ese es nuestro caso base). Luego, se ejecuta
la funcion merge, la cual compara los elementos de dos subarrays ordenados para devolver un arreglo con todos los elementos
ordenados. Por ende, esta funcion merge se va ejecutando desde los subarrays de tamaño mas pequeño hasta llegar al arreglo de
tamaño inicial, pero ordenado.

La funcion merge funciona con tres pointers, dos para la posicion actual de cada uno de los dos subarrays a comparar y uno
para la posicion actual del array resultante. Los tres se inicializan a 0 y se empiezan a comparar los elementos y a medida
que se van añadiendo elementos al array resultante ordenado, se van actualizando los palores de los punteros para seguir
comparando los elementos. 

En el caso que al comparar dos subarrays ya no haya mas elementos de un subarray con que comparar, entonces la funcion merge toma
los elementos restantes del otro subarray (el cual ya esta ordenado) y los coloca en el array resultante.

Para resolver este problema, utilice el siguiente razonamiento.

Primero, ordenamos el arreglo con las locaciones de los establos usando merge sort.

Como tenemos que la maxima locación de un establo es 1000000000 y la minima locacion es 0 y a lo minimo tenemos 2 vacas, entonces 
en dicho caso, una posibilidad para la maxima minima distancia entre las vacas seria el punto medio entre ambas de esas locaciones, 
es decir, (1000000000 + 0)/2 (Lo vamos a llamar, nuestro guess), esto es para cuando tuvieramos un establo localizado en 0 y algun
otro establo localizado en 1000000000. Pero, luego en el caso que el establo mas lejano este en una locacion mas pequeña o que en
vez de 2 vacas, tuvieramos una cantidad mas grande, entonces habria que probar luego con otro guess. Por ende, vamos a aplicar el
algoritmo de binary search para encontrar el guess correcto.

Implementamos el algoritmo de binary search de la siguiente manera:

Empezamos con dos variables, start y end, la minima y maxima locacion correspondientemente. Encontramos su punto medio (Nuestro
guess, la variable que lo almacenara sera mid), probamos de que podamos colocar la cantidad de vacas que nos piden. 
En caso negativo, establecemos end = mid-1 y calculamos el punto medio nuevamente. En caso afirmativo, establecemos mid como
una posible respuesta, pero tambien incrementamos start por una unidad para ver si existe un valor mayor que nos deje colacar las
c vacas en los establos. De esta manera, logramos encontrar nuestra maxima minima distancia entre cualquier par de vacas
eficientemente.

Nota:
Para chequear si para el guess actual podemos colocar c vacas en los establos, seguimos este procedimiento:
1) Colocamos una vaca en el primer establo
2) Luego comparamos la distancia entre el primer estblo y el segundo establo con nuestra maxima minima distancia,
si la distancia entre los establos es mayor o igual que nuestro guess para la maxima minima distancia, entonces colocamos una
vaca en el segundo establo. Sino, comparamos con el siguiente establo y chequeamos la condicion nuevamente. Luego, una vez
asignamos un establo a la 2da vaca, ejecutar la logica anterior, pero usando en vez del primer establo, el establo que le fue
asignado a la 2da vaca. Es decir vamos a ejecutar dicha logica recorriendo todo el array de establos.
3) Si al finalizar del paso 2, la cantidad de vacas que podemos colocar en los establos cumpliendo la correspondiente
maxima minima distancia es menor que la cantidad de vacas c que nos dan inicialmente, entonces dicha maxima minima distancia
no funciona.
*/

#include <iostream>
#include <vector>
using namespace std;

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

// Print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int t, n, c;
    cin >> t;

    while (t > 0)
    {
        cin >> n;
        cin >> c;

        int locations[n];

        int number;


        for (int i = 0; i < n; i++){
            cin >> number;
            locations[i] = number;
        }

        mergeSort(locations, 0, n - 1);
        
        int start = 0;
        int end = 1000000000;
        int ans = 0;
        while (start <= end){

            int mid = (end + start) / 2;

            int possibleNumberOfCows = 1;
            int prev = locations[0];

            for (int i = 1; i < n; i++){
                if (mid <= locations[i] - prev){
                    possibleNumberOfCows++;
                    prev = locations[i];
                }
            }

            if (possibleNumberOfCows < c){
                end = mid - 1;
            }else{
                ans = mid;
                start = mid + 1;
            }
            
        }
        cout << ans << endl;
        
        t--;
    }

    return 0;
}

