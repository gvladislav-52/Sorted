#ifndef WORK_MERGE_SORT_H
#define WORK_MERGE_SORT_H

void Merge(int arr[], int p, int q, int length)
{
    int ascL = q-p+1;
    int ascR = length-q;

    int * left_arr = new int [ascL];
    int * right_arr = new int [ascR];

    for(int i = 0; i <ascL; i++)
        left_arr[i] = arr[p+i];
    for(int i = 0; i < ascR; i++)
        right_arr[i] = arr[q+i+1];

    int count = p;
    int left_index = 0;
    int right_index = 0;

    while((left_index < ascL)&& (right_index < ascR))
    {
        if(left_arr[left_index] <= right_arr[right_index])
            arr[count++] = left_arr[left_index++];
        else
            arr[count++] = right_arr[right_index++];
    }

    while(left_index < ascL)
        arr[count++] = left_arr[left_index++];

    while(right_index < ascR)
        arr[count++] = right_arr[right_index++];

    delete [] left_arr;
    delete [] right_arr;
}

void Sort(int arr[], int p, int length)
{
    if (p < length)
    {
        int q = (p+length)/2;
        Sort(arr,p,q);
        Sort(arr,q+1,length);
        Merge(arr,p,q,length);
    }
}


#endif //WORK_MERGE_SORT_H
