#include <iostream>

using namespace std;

int fibonacci_recursive(int n)
{
    if (n < 2)
        return 1;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int fibonacci(int n)
{
    int A[n + 1];
    A[0] = 1;
    A[1] = 1;
    for (int i = 2; i <= n; i++)
        A[i] = A[i - 1] + A[i - 2];
    return A[n];
}

int main()
{
    int n = 7;
    fibonacci_recursive(n);
    fibonacci(n);
}