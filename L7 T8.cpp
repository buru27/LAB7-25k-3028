#include <iostream>
using namespace std;

int radixSort(int arr[], int n)
{
    int maxVal = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    int* output = new int[n];
    int passes = 0;

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

        passes++;

        cout << "Pass " << passes << ": ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    delete[] output;
    return passes;
}

int main()
{
    int arr[] = {94, 802, 7, 1234, 56, 321, 405, 18};
    int n = 8;

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int passes = radixSort(arr, n);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nTotal passes: " << passes << endl;

    return 0;
}
