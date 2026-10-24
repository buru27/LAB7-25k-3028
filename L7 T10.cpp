#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void countingSort(int arr[], int n, int exp)
{
    int count[10] = {0};
    int* output = new int[n];

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[--count[digit]] = arr[i];
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

void radixSort(int arr[], int n)
{
    int maxVal = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    int pass = 1;

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp);

        cout << "After pass " << pass++ << ": ";
        display(arr, n);
    }
}

int main()
{
    int arr[] = {
        7314, 314, 731, 34, 3147,
        147, 47, 7314, 4, 314
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    display(arr, n);

    radixSort(arr, n);

    cout << "\nFinal sorted array: ";
    display(arr, n);

    return 0;
}
