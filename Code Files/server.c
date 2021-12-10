#include <stdio.h>
#include <stdlib.h>
#include "server.h"

unsigned long long int comparision = 0; //Storing the number of comparisions

// A utility function to swap two elements 
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
   for (int i = 0; i < n-1; ++i)
   {
       
       // Last i elements are already in place
       for (int j = 0; j < n-i-1; ++j)
       {
           ++comparision;
           if (arr[j] > arr[j+1])
              swap(&arr[j],&arr[j+1]);
       }
       
   }
}

void selectionSort(int arr[], int n)
{
    int minimum_index;
    // One by one move boundary of unsorted subarray
    for (int i = 0; i < n-1; i++)
    {
        
        // Find the minimum element in unsorted array
        minimum_index = i;
        for (int j = i+1; j < n; j++)
        {
          ++comparision;
          if (arr[j] < arr[minimum_index])
            minimum_index = j;
        }
        
        // Swap the minimum element with the first element
        swap(&arr[minimum_index],&arr[i]);
    }
    
}

// Merges two subarrays of arr[].
// First subarray is arr[low..mid]
// Second subarray is arr[mid+1..high]
void merge(int arr[],int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=0;
    int *auxiliary_arr = (int *)malloc(1000500*sizeof(int));
    while(i<=mid && j<=high)
    {
        ++comparision;
        if(arr[i]<arr[j])
        {
            auxiliary_arr[k++]=arr[i];
            ++i;
        }
        else
        {
            auxiliary_arr[k++]=arr[j];
            ++j;
        }
    }
    
    while(i<=mid)
    {
        
        auxiliary_arr[k++]=arr[i];
        ++i;
    }
    
    while(j<=high)
    {
        
        auxiliary_arr[k++]=arr[j];
        ++j;
    }
    
    int l=low;

    for(i=0;i<k;i++)
    {
       
        arr[l++]=auxiliary_arr[i];
    }
    
    free(auxiliary_arr);
}

/* low is for left index and high is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[],int low,int high)
{
    
    if(low<high)
    {
        int mid=(low+high)/2;
        // Sort first and second halves
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    int temp;
    while(i<=j) //i & j don't cross over
    {
        ++comparision;
        while(i<=high && arr[i]<=pivot)
        {
            ++comparision;
            ++i;
        }
        ++comparision;
        while(j>low && arr[j]>=pivot)
        {
            ++comparision;
            --j;
        }
        
        if(i<j)
          swap(&arr[i],&arr[j]);
        
    }
    
    if(j!=low)
    {
        arr[low]=arr[j];
        arr[j]=pivot;
    }
    
    return j;
}

/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[],int low,int high)
{
    int pi;
    if(low<high)
    {   /* pi is partitioning index, arr[p] is now 
           at right place */
         pi=partition(arr,low,high);
         // Separately sort elements before 
        // partition and after partition
         quickSort(arr,low,pi-1);
         quickSort(arr,pi+1,high);
    }
}
