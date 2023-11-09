#ifndef WORK_SMOOTH_SORT_H
#define WORK_SMOOTH_SORT_H

int SmoothSort(int arr[], int left, int right)
{
    int pilot = arr[(left+right)/2];
    while(left <= right)
    {
        while(arr[left] < pilot) left++;
        while(arr[right] > pilot) right--;
        if(left <= right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
        left++;
        right--;
    }
    return left;
}

void smoothSort(int arr[], int start, int end)
{
    if(start >= end) return;
    int pi = SmoothSort(arr,start,end);
    smoothSort(arr,start,pi-1);
    smoothSort(arr,pi,end);
}




#endif //WORK_SMOOTH_SORT_H
