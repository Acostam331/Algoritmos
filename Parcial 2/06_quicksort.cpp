#include <iostream>

using namespace std;

void show_array(int *A, int n)
{
    cout << "[ " << A[0];
    for (int i = 1; i < n; i++)
        cout << ", " << A[i];
    cout << " ]\n";
}

// Swap function, receives an array and two indexes to swap using a temp variable(a, b)
void swap(int *A, int a, int b)
{
    if (a != b)
    {
        int temp = A[a];
        A[a] = A[b];
        A[b] = temp;
    }
}

// Main quicksort algorithm, receives an array(A), the first index(p) and the last index(r) of that iteration
int partition(int *A, int p, int r)
{
    // Declare and define the pivot, it has to be the last element of the iteration(r)
    int pivot = A[r];
    // Declare and define the tracker, it is based on the first index of the callback
    int tracker = p - 1;

    // For loop that goes through the array from p to r
    for (int j = p; j < r; j++)
        // If the element in the for index is smaller than the pivot, the tracker increases in 1 and the element in the j index and the tracker index swap
        if (A[j] <= pivot)
        {
            tracker++;
            swap(A, j, tracker);
        }

    // The tracker gets increased by 1 and gets swapped with the last element of the iteration
    tracker++;
    swap(A, r, tracker);

    // Function returns the tracker for a recursive call
    return tracker;
}

// Main function for quicksort, receives an array(A), the first index(p) and last index(r) of that iteration
void quicksort(int *A, int p, int r)
{
    // if the first index is smaller than the last index
    if (p < r)
    {

        int q = partition(A, p, r);
        // Recursive call for left most section of the array based on q as the last index
        quicksort(A, p, q - 1);
        // Recursive call for right most section of the array based on q as the fisrt index
        quicksort(A, q + 1, r);
    }
}

int main()
{
    int n = 8;
    int A[n] = {2, 8, 7, 1, 3, 5, 6, 4};

    quicksort(A, 0, n - 1);

    show_array(A, n);

    return 0;
}
