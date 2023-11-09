#include <iostream>
#include "Binary Tree Sort.h"
#include "Merge Sort.h"
#include "QuickSort.h"
#include "Smooth Sort.h"

using namespace std;

void bubbleSort()
{//сортирование пузырьком
    cout << "\nBubble Select: ";
    const int LENGTH = 5;
    int arr[LENGTH] = {5, 2, 4, 6, 1};
    for(int i = 0; i < LENGTH-1; i++)
    {
        for(int j = 0; j < LENGTH-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i = 0; i < LENGTH; i++)
        cout << arr[i] << " ";
}
void selectionSort()
{//сортированием выбором
    cout << "\nSorter Select: ";
    const int LENGTH = 5;
    int arr[LENGTH] = {5, 2, 4, 6, 1};
    for(int i = 0; i < LENGTH; i++)
    {
        int min_index = i;
        for(int j = i+1; j < LENGTH; j++)
        {
            if(arr[min_index] > arr[j])
            {
                int temp = arr[min_index];
                arr[min_index] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 0; i < LENGTH; i++)
        cout << arr[i] << " ";
}
void insertionSort()
{//сортирование вставки
    const int LENGTH = 5;
    int arr[LENGTH] = {5, 2, 4, 6, 1};
    cout << "\nSorter Insert: ";
    for(int i = 1; i < LENGTH; i++)
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
    for(int i = 0; i < LENGTH; i++)
        cout << arr[i] << " ";
}
void Smooth_Start() {
    const int LENGTH = 5;
    int arr[LENGTH] = {5, 2, 4, 6, 1};
    cout  << "\nSmooth Sorter: ";
    smoothSort(arr, 0, LENGTH - 1);
    for (int i = 0; i < LENGTH; i++)
        cout << arr[i] << " ";
}
void Quick_Start()
{
    const int LENGTH = 5;
    int arr[LENGTH] = {5, 2, 4, 6, 1};
    cout  << "\nQuick Sorter: ";
    quickSort(arr,0,LENGTH);
    for (int i = 0; i < LENGTH; i++)
        cout << arr[i] << " ";
}
void Binary_Tree_Start()
{
    const int LENGTH = 5;
    int arr[LENGTH] = {5, 2, 4, 6, 1};
    cout << "\nBinary Tree Sorter: ";
    Binary_Tree_Sort tree;
    tree.add(5);
    tree.add(3);
    tree.add(8);
    tree.add(2);
    tree.add(4);
    tree.add(19);

    tree.print();
}
void Merge_Start()
{
    const int LENGTH = 5;
    int arr[LENGTH] = {5, 2, 4, 6, 1};
    cout  << "\nMerge Sorter: ";
    Sort(arr, 0, LENGTH-1);
    for (int i = 0; i < LENGTH; i++)
        cout << arr[i] << " ";
}

int main()
{
    bubbleSort();
    selectionSort();
    insertionSort();
    Smooth_Start();
    Quick_Start();
    Merge_Start();
    Binary_Tree_Start();

}