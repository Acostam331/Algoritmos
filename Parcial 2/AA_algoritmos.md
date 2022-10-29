# Algoritmos repaso parcial 2

# Heap sort

## Max heap sort
Max heap sort trabaja con un arreglo de datos, comparando un elemento $i = {n\over2}-1$ elemento con los elementos $2*i+1$ como nodo izquierdo y $2*i+2$ como nodo derecho, realizando comparaciones para encontrar el mayor de los 3 y desplazandolo mas cerca del inicio del arbol, una vez encontrado el mayor elemento de esa iteracion, se intercambia por el ultimo elemento del arreglo, se reserva, y se ejecuta de nuevo con un indice reducido en 1 hasta terminar las iteraciones.

#

## Deconstruyendo cada funcion

### Main()
En la funcion main() se declarara un arreglo de datos dependiente de n, pasandose como argumento a la funcion heapsort()
```c++
int main()
{
    // Array size
    int n = 9;
    // Data array
    int A[n] = {5, 13, 2, 25, 7, 17, 20, 8, 4};

    // Heapsort root function call
    heapsort(A, n);

    show_array(A, n);

    return 0;
}
```

### heapsort(int *A, int n)
En la funcion heapsort() es donde se ejecutaran los algoritmos, orden y reordenamiento del arreglo por medio de llamadas a funciones, se redeclarara el tamaño del arreglo para su uso posterior en la llamada de max_heapify() al momento de ordenar el arreglo, se podria definir como la funcion principal de heap sort.
```c++
// Root heapsort function, receiving an array and array size
void heapsort(int *A, int n)
{
    // Declaring heapsize from n
    int heap_size = n;

    // BuildMaxHeap function callback
    build_max_heap(A, heap_size);

    // For loop that starts from the last index to 1
    for (int i = n - 1; i > 0; i--)
    {
        // Swapping 0 and each of the elements of the array
        swap(A, 0, i);
        // Reducing the heap size, so maxHeapify can work with smaller data until it runs out, checking each element
        heap_size--;
        max_heapify(A, 0, heap_size);
    }
}
```

### build_max_heap(int *A, int heap_size)
En la funcion build_max_heap() se genera un bucle el cual dependera de $floor(heap_size / 2) - 1$, esto encontrara el indice del ultimo nodo con hojas, y a partir de el ira subiendo en el arreglo hasta llegar al indice 0, llamando a la funcion max_heapify(), enviando un indice menor cada vez.
```c++
// BuildMaxHeap function, receiving an array and size
void build_max_heap(int *A, int heap_size)
{
    // int heap_size = n;

    // For loop from the floor of size/2 - 1
    for (int i = floor(heap_size / 2) - 1; i >= 0; i--)
        // Executing max heap sort from the floor of size/2 -1 to 0, going backwards in the array, passing Array(A), an index(i) and the size of the array(heap-size)
        max_heapify(A, i, heap_size);
}
```

### max_heapify(int *A, int i, int heap_size)
En la funcion max_heapify() es donde el algoritmo en si es implementado, la forma en que max_heapify() funciona es que dado un indice que representa una rama de un arbol, evalua a la rama con respecto a las hojas del mismo, buscando al mayor de los 3 e intercambiandolo por la rama de ser necesario, en caso de que exista un intercambio de nodos, es necesario hacer una llamada recursiva al nodo cambiado, tomando a ese mismo como padre y ejecutando los mismos cambios en caso de ser necesario, si no es necesario, el ultimo elemento del arbol se intercambiaria con el primero, dejando al elemento mayor al final del arreglo reservado, disminuyendo en 1 el tamaño del arreglo a iterar y volviendose a ejecutar, asi sucesivamente hasta terminar las iteraciones posibles.
```c++
// Max heapify algoritm, receives an array(A), an index(i) and the size of the array(heap_size)
void max_heapify(int *A, int i, int heap_size)
{
    // Declaring the largest variable
    int largest;
    // Declaring and assigning l and r from left and right functions, using the index as a parameter
    int l = left(i);
    int r = right(i);

    // As long as the left index is smaller than the array size and if the l index of the array is bigger than i index of the array
    if (l < heap_size && A[l] > A[i])
        // Define the left node as the largest
        largest = l;
    else
        // Keep the parent node as the largest
        largest = i;

    // As long as the right index is smaller than the array size and if the r index of the array is bigger than the "largest" variable index of the array
    if (r < heap_size && A[r] > A[largest])
        // Define the right node as the largest
        largest = r;

    // If the largest element is different than the original parent node, call swap function and do a recursive call on the swapped node
    if (largest != i)
    {
        swap(A, i, largest);
        max_heapify(A, largest, heap_size);
    }
}
```

### left(int i)
la funcion left() encontrara el nodo hijo izquierdo del elemento padre que se esta evaluando en max_heapify(), utilizando la formula $2*i+1$, avanzando en los indices hasta llegar al indice del hijo izquierdo.
```c++
// Left function, receives an index
int left(int i)
{
    // Returns the left child of current node, based on the position from the array
    return 2 * i + 1;
}
```

### right(int i)
la funcion right() encontrara el nodo hijo derecho del elemento padre que se esta evaluando en max_heapify(), utilizando la formula $2*i+2$, avanzando en los indices hasta llegar al indice del hijo derecho.
```c++
// Right function, receives an index
int right(int i)
{
    // Returns the right child of current node, based on the position from the array
    return 2 * i + 2;
}
```

### swap(int *A, int i, int j)
La funcion swap() se encarga de intercambiar los elementos dados dos indices de un arreglo.
```c++
// Swap function, receives an array and two indexes to swap using a temp variable(i, j)
void swap(int *A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}
```

### Ejemplo de resultado
![](Heap.png)

#

## Min heap sort
La funcion Min heap sort funciona de una forma igual que max, con la diferencia que intenta ordenar un arreglo de manera descendente en lugar de ascendente, para ello es necesaria una pequeña modificacion en la funcion max_heapify(), convirtiendola a min_heapify() de la siguiente manera.
```c++
// Min heapify algoritm, receives an array(A), an index(i) and the size of the array(heap_size)
void min_heapify(int *A, int i, int heap_size)
{
    // Declaring the smallest variable
    int smallest;
    // Declaring and assigning l and r from left and right functions, using the index as a parameter
    int l = left(i);
    int r = right(i);

    // As long as the left index is smaller than the array size and if the l index of the array is smaller than i index of the array
    if (l < heap_size && A[l] < A[i])
        // Define the left node as the smallest
        smallest = l;
    else
        // Keep the parent node as the smallest
        smallest = i;

    // As long as the right index is smaller than the array size and if the r index of the array is smaller than the "smallest" variable index of the array
    if (r < heap_size && A[r] < A[largest])
        // Define the right node as the largest
        smallest = r;

    // If the smallest element is different than the original parent node, call swap function and do a recursive call on the swapped node
    if (smallest != i)
    {
        swap(A, i, smallest);
        max_heapify(A, smallest, heap_size);
    }
}
```