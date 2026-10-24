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

    cout << "\nOriginal array: ";
    display(arr, n);

    // Count digit frequencies
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    cout << "Frequency count: ";
    display(count, 10);

    // Calculate cumulative counts
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    cout << "Cumulative count: ";
    display(count, 10);

    // Build output from right to left for stability
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[--count[digit]] = arr[i];
    }

    cout << "Output array: ";
    display(output, n);

    // Copy output back into original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    cout << "Copied back: ";
    display(arr, n);

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
        cout << "\n========== PASS "
             << pass++ << " ==========\n";

        countingSort(arr, n, exp);
    }
}

int main()
{
    int trackingIDs[] = {
        4721, 305, 472, 89, 3005, 721,
        1000, 305, 9999, 42, 870, 100
    };

    int n = sizeof(trackingIDs) / sizeof(trackingIDs[0]);

    cout << "Original tracking IDs: ";
    display(trackingIDs, n);

    radixSort(trackingIDs, n);

    cout << "\nFinal sorted tracking IDs: ";
    display(trackingIDs, n);

    return 0;
}
