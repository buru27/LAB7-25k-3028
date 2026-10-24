#include <iostream>
using namespace std;

int comparisons = 0;
int partitionCount = 0;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true)
    {
        while (i <= high)
        {
            comparisons++;
            if (arr[i] > pivot)
                break;
            i++;
        }

        while (j > low)
        {
            comparisons++;
            if (arr[j] <= pivot)
                break;
            j--;
        }

        if (i >= j)
            break;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    partitionCount++;

    cout << "\nPivot: " << pivot << endl;
    cout << "Array after partition: ";
    display(arr, 7);

    return j;
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
    int arr[] = {55, 25, 75, 15, 65, 35, 45};
    int n = 7;

    cout << "Original array: ";
    display(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "\nSorted array: ";
    display(arr, n);

    cout << "Partition operations: "
         << partitionCount << endl;

    cout << "Element comparisons: "
         << comparisons << endl;

    return 0;
}
