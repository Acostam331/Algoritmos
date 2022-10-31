#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

void show_array(int *A, int n)
{
    cout << "[ " << A[0];
    for (int i = 1; i < n; i++)
        cout << ", " << A[i];
    cout << " ]\n";
}

// Merge Sort
void merge(int *A, int p, int q, int r)
{
    int i, j;
    int n1 = q - p;
    int n2 = r - q + 1;
    int L[n1 + 1], R[n2 + 1];
    for (i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (j = 0; i < n2; i++)
        R[i] = A[q + 1 + i];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    i = j = 0;
    for (int k = p; i <= r; k++)
    {
        if (L[i] < R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = floor((p + r) / 2);
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

// Heap sort
int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

void swap(int *A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void max_heapify(int *A, int i, int heap_size)
{
    int largest;
    int l = left(i);
    int r = right(i);
    if (l < heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if (r < heap_size && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        swap(A, i, largest);
        max_heapify(A, largest, heap_size);
    }
}

void build_max_heap(int *A, int heap_size)
{
    for (int i = floor(heap_size / 2) - 1; i >= 0; i--)
        max_heapify(A, i, heap_size);
}

void heapsort(int *A, int n)
{
    int heap_size = n;
    build_max_heap(A, heap_size);
    for (int i = n - 1; i > 0; i--)
    {
        swap(A, 0, i);
        heap_size--;
        max_heapify(A, 0, heap_size);
    }
}

// Quick sort
int partition(int *A, int p, int r)
{
    int pivot = A[r];
    int tracker = p - 1;
    for (int j = p; j < r; j++)
        if (A[j] <= pivot)
        {
            tracker++;
            swap(A, j, tracker);
        }
    tracker++;
    swap(A, r, tracker);
    return tracker;
}

void quicksort(int *A, int p, int r)
{
    if (p < r)
    {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}

int main()
{
    int n = 8;

    int A[n] = {5, 8, 9, 1, 4, 6, 8, 0};
    int B[n] = {5, 8, 9, 1, 4, 6, 8, 0};
    int C[n] = {5, 8, 9, 1, 4, 6, 8, 0};

    merge_sort(A, 0, n - 1);
    heapsort(B, n);
    quicksort(C, 0, n - 1);

    show_array(A, n);
    show_array(B, n);
    show_array(C, n);

    return 0;
}