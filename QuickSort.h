#ifndef WORK_QUICKSORT_H
#define WORK_QUICKSORT_H

void swap (int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high-1];
    int i = (low-1);

    for(int j = low; j < high; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1],&arr[high-1]);
    return (i+1);
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi);
        quickSort(arr,pi+1,high);
    }
}
#endif //WORK_QUICKSORT_H
