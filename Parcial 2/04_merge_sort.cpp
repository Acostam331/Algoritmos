#include <iostream>
#include <climits>
#include <math.h>

using namespace std;

// Simple show array function, receiving an array and an array length
void show_array(int *A, int n)
{
    cout << "[ " << A[0];
    for (int i = 1; i < n; i++)
        cout << ", " << A[i];
    cout << " ]\n";
}

// Merge algorithm, receiving a full array(A), first index(p), half index(q) and last index(r) of each subsection
void merge(int *A, int p, int q, int r)
{
    // Declaring i and auxiliar indexes
    int i, j;
    // Declaring n1, known as the length of the left most part of the subsection
    int n1 = q - p + 1;
    // Declaring n2, known as the lenth of the right most part of the subsection
    int n2 = r - q;
    // Declaring L and R, subarrays that will store the data of the subsections, +1 extra element
    int L[n1 + 1], R[n2 + 1];

    // Filling Left subarray with the data of A argument, form 0 to n1, left most part
    for (i = 0; i < n1; i++)
        // Using data from array starting from p+i index, with p being first index
        L[i] = A[p + i];
    // Filling right subarray with the data of A argument, form 0 to n2, right most part
    for (j = 0; j < n2; j++)
        // Using data from array starting from q+1+j index, with q+1 being the half index
        R[j] = A[q + 1 + j];

    // Assigning the max capable number of the computer to last index of L and R subarrays
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    // Reusing i and j indexes, assigning values back to 0
    i = j = 0;

    // For loop starting in p, ending in r, used for comparing both sides of the subarrays L and R
    for (int k = p; k <= r; k++)
        // if left subarray is bigger than right, the original array changes its k element for the L elements, stopping in last element of subarray
        if (L[i] < R[j])
        {
            A[k] = L[i];
            i++;
        }
        // if right subarray is bigger than left, the original array changes its k element for the R elements, stopping in last element of subarray
        else
        {
            A[k] = R[j];
            j++;
        }
}

// With A as the full array as reference, p as first index and r as last index
void merge_sort(int *A, int p, int r)
{
    // As long as p is lower than r, a double recursive call will be made
    if (p < r)
    {
        // With q as the half way index of the array, cutting it in half
        int q = floor((p + r) / 2);

        // Double recursive call

        // Using q instead of r to cut the first half
        merge_sort(A, p, q);
        // using q+1 instead of p to cut the second half
        merge_sort(A, q + 1, r);
        // Merge alhoritm callback, sending an array(A), first index(p), half index(q) and last index(r) of subsection
        merge(A, p, q, r);
    }
}

int main()
{
    // Array size
    int n = 8;
    // Data array
    int A[n] = {5, 2, 4, 7, 1, 3, 2, 6};

    // First merge sort algorithm callback, with p=0, r=n-1
    merge_sort(A, 0, n - 1);

    show_array(A, n);

    return 0;
}
