#include <iostream>
using namespace std;

void radixSort(int arr[], int n)
{
    int maxVal = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    int* output = new int[n];

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
    {
        int count[10] = {0};

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

        cout << "After " << exp << "s digit pass: ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    delete[] output;
}

int main()
{
    int arr[] = {91, 8, 1024, 56, 305, 7, 120};
    int n = 7;

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    radixSort(arr, n);

    cout << "Final sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
