#include <iostream>
using namespace std;

int partitionCount = 0;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    partitionCount++;

    cout << "\nPartition " << partitionCount
         << ": low = " << low
         << ", high = " << high
         << ", pivot = " << pivot << endl;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    cout << "Array after partition: ";
    display(arr, 7);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int arr[] = {40, 20, 70, 10, 60, 30, 50};
    int n = 7;

    cout << "Original array: ";
    display(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    display(arr, n);

    cout << "Total partition operations: "
         << partitionCount << endl;

    return 0;
}
