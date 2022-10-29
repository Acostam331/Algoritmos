#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

// Show array function, receives the array and array size
void show_array(int *A, int n)
{
    cout << "[ " << A[0];
    for (int i = 1; i < n; i++)
        cout << ", " << A[i];
    cout << " ]\n";
}

// Swap function, receives an array and two indexes to swap using a temp variable(i, j)
void swap(int *A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// Left function, receives an index
int left(int i)
{
    // Returns the left child of current node, based on the position from the array
    return 2 * i + 1;
}

// Right function, receives an index
int right(int i)
{
    // Returns the right child of current node, based on the position from the array
    return 2 * i + 2;
}

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

// BuildMaxHeap function, receiving an array and size
void build_max_heap(int *A, int heap_size)
{
    // int heap_size = n;

    // For loop from the floor of size/2 - 1
    for (int i = floor(heap_size / 2) - 1; i >= 0; i--)
        // Executing max heap sort from the floor of size/2 -1 to 0, going backwards in the array, passing Array(A), an index(i) and the size of the array(heap-size)
        max_heapify(A, i, heap_size);
}

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
