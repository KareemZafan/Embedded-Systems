#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#define SIZE 10
typedef unsigned short int u16 ;
typedef enum
{
    FALSE,
    TRUE
} boolean;

int  binarySearch(int *arr, int siz, int searchKey) ;
boolean checkSorted(int *arr, int siz) ;
void insertSort(int *arr, int _size);
void printArray(int *arr, int siz) ;

int main()
{
    int arr[] = {10, 20,60, 2, 4, 8, 5, 6, 3, 0} ;
    int key = 0  ;
    printArray(arr,SIZE) ;
    printf("Enter a value to search for: ") ;
    scanf("%d",&key) ;
    int keyIndex = binarySearch(arr,SIZE,key) ;
    printArray(arr,SIZE) ;
    if(keyIndex != -1)
    {
        printf("%d is found in index %d \n",key,keyIndex ) ;
    }
    else
    {
        printf("%d is not found\n ",key ) ;
    }


return 0;
}


int binarySearch(int *arr, int siz, int searchKey)
{

    assert(siz > 0) ;
    /* If array is not sorted you have to sort the array first */
    if(checkSorted(arr,siz) != TRUE)
    {

        insertSort(arr, siz) ;
    }

    int lowIndex = 0 ;
    int highIndex = siz - 1  ;
    int midIndex = (lowIndex + highIndex) / 2  ;

    while(lowIndex <= highIndex )
    {
        midIndex = (lowIndex + highIndex) / 2  ;
        if(searchKey > arr[midIndex])
            lowIndex = midIndex + 1 ;
        else if(searchKey < arr[midIndex])
            highIndex = midIndex - 1 ;
        else return midIndex ;
    }

    return -1 ; /* Key Not Found */
}


boolean checkSorted(int *arr, int siz)
{
    assert(siz > 0 ) ;
    for (int i = 0 ; i < siz ; i++)
    {
        if(arr[i] > arr[i+1]) return FALSE ;
    }
    return TRUE;
}


void insertSort(int *arr, int _size)
{
    int i, key, j;
    for (i = 1; i < _size ; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return ;
}

void printArray(int *arr, int siz)
{

    for (int i = 0 ; i < siz ; i++)
        printf("%d\t",arr[i]) ;
    printf("\n") ;
    return ;
}





