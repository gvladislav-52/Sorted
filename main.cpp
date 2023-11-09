#include <iostream>
using namespace std;

void bubbleSort(int arr[], int length)
{//сортирование пузырьком
    for(int i = 0; i < length-1; i++)
    {
        for(int j = 0; j < length-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i = 0; i < length; i++)
        cout << arr[i] << " ";
}
void selectionSort(int arr[] , int length)
{//сортированием выбором
    for(int i = 0; i < length; i++)
    {
        int min_index = i;
        for(int j = i+1; j < length; j++)
        {
            if(arr[min_index] > arr[j])
            {
                int temp = arr[min_index];
                arr[min_index] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0; i < length; i++)
        cout << arr[i] << " ";
}
void insertionSort(int arr[], int length)
{//сортирование вставки
    for(int i = 1; i < length; i++)
    {
        int sorted = i-1;
        while(sorted > -1 && arr[sorted] > arr[sorted+1])
        {
            int temp = arr[sorted];
            arr[sorted] = arr[sorted+1];
            arr[sorted+1] = temp;
            sorted--;
        }
    }
    for(int i = 0; i < length; i++)
        cout << arr[i] << " ";
}
namespace smooth {
int smoothSortFucntion(int arr[], int left, int right) {
    int pilot = arr[(left + right) / 2];    //находим опорный элемент
    while (left <= right) {
        while (arr[left] < pilot) left++;
        while (arr[right] > pilot) right--;
        if (left <= right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
        left++;
        right--;
    }
    return left;
}

void smoothSort(int arr[], int start, int end) {
    if (start >= end) return;
    int rightStart = smoothSortFucntion(arr, start, end);
    smoothSort(arr, start, rightStart - 1);
    smoothSort(arr, rightStart, end);
}

void smoothSort(int arr[], int length) {
    smoothSort(arr, 0, length - 1);
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
}
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high - 1];  // выбираем последний элемент в качестве опорного
    int i = (low - 1);  // индекс меньшего элемента

    for (int j = low; j < high - 1; j++) {
        // если текущий элемент меньше опорного
        if (arr[j] < pivot) {
            i++;    // увеличиваем индекс меньшего элемента
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high - 1]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

void start_and_show_quickSort(int arr[], int low, int high)
{
    quickSort(arr, low, high);
    for (int i = 0; i < high; i++)
        cout << arr[i] << " ";
}


int main()
{
    const int LENGTH = 5;
    int arr[LENGTH] = {5,3,8,4,1};
    cout << "Sorter Buble: ";
    //bubbleSort(arr, LENGTH);
    cout << "\nSorter Select: ";
    //selectionSort(arr, LENGTH);
    cout << "\nSorter Insert: ";
    //insertionSort(arr, LENGTH);
    cout << "\nSorter Smooth: ";
    //smooth::smoothSort(arr,LENGTH);
    cout << "\nQuick Smooth: ";
    start_and_show_quickSort(arr,0,LENGTH);
}