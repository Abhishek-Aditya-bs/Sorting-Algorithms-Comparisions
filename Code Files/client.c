#include <stdio.h>
#include <stdlib.h>
#include "server.h"
#include <time.h>
int main()
{   
    double *duration = (double *)malloc(4500000*sizeof (double));
    unsigned long long int *comparisions = (unsigned long long int *)malloc(4500000*sizeof (unsigned long long int));
    int count=0;

    int start_array_size = 100000;
    int size_increment = 50000;
    int end_array_size = 1000000;

    //Outer loop to increase the size of the array and then generate random numbers
    for(int size=start_array_size;size<=end_array_size;size+=size_increment)
    {
        int n = size; //Size of array for the current iteration
        //Printing the size of array
        printf("For Array Size = %d\n",n);
        int *bs = (int *)malloc(n*sizeof(int));
        int *ss = (int *)malloc(n*sizeof(int));
        int *ms = (int *)malloc(n*sizeof(int));
        int *qs = (int *)malloc(n*sizeof(int));
        srand(rand());
        for(int i=0;i<n;++i)
        {
            int no = rand();
            bs[i] = no;
            ss[i] = no;
            ms[i] = no;
            qs[i] = no;
        }

        clock_t start,end; //For timing the functions
        double time_taken = 0;
        comparision=0;
       //Running Bubble Sort
        start = clock();
        bubbleSort(bs,n);
        end = clock();
        time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

        //Storing time and no. of comp
        duration[count] = time_taken;
        comparisions[count] = comparision;
        ++count;

        printf("Bubble Sort\nTime Taken\t\tNo. of Comparisions\n");
        printf("%lf\t\t\t%llu\n",time_taken,comparision);
        comparision=0;
        //Running Selection Sort
         start = clock();
         selectionSort(ss,n);
         end = clock();
         time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

         //Storing time and no. of comp
         duration[count] = time_taken;
         comparisions[count] = comparision;
         ++count;

         printf("Selection Sort\nTime Taken\t\tNo. of Comparisions\n");
         printf("%lf\t\t\t%llu\n",time_taken,comparision);
         comparision=0;
         //Running Merge Sort
          start = clock();
          mergeSort(ms,0,n-1);
          end = clock();
          time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

          //Storing time and no. of comp
          duration[count] = time_taken;
          comparisions[count] = comparision;
          ++count;

          printf("Merge Sort\nTime Taken\t\tNo. of Comparisions\n");
          printf("%lf\t\t\t%llu\n",time_taken,comparision);
          comparision=0;

          //Running Quick Sort
           start = clock();
           quickSort(qs,0,n-1);
           end = clock();
           time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

           //Storing time and no. of comp
           duration[count] = time_taken;
           comparisions[count] = comparision;
           ++count;

           printf("Quick Sort\nTime Taken\t\tNo. of Comparisions\n");
           printf("%lf\t\t\t%llu\n",time_taken,comparision);
           printf("\n\n");
           comparision=0;
           
           free(bs);
           free(ss);
           free(ms);
           free(qs);
    }


    //Opening two files one for storing comparisions and one for time taken for execution
    FILE *comparision_file,*time_file;
    //Bubble Sort Files
    comparision_file = fopen("BubbleSort-Comparisions.txt","w");

    if(comparision_file)
        printf("File BubbleSort-Comparisions.txt opened successfully.\n");
    else
        printf("Cannot open file for storing comparisions.\n");

    time_file = fopen("BubbleSort-time.txt","w");
    if(time_file)
        printf("File BubbleSort-time.txt opened successfully.\n");
    else
        printf("Cannot open the file for storing comparisions.\n");


    //Storing the values for Bubble Sort
    fputs("-------------- BUBBLE SORT -----------------\n",time_file);
    fputs("Size of Array\t\t\tTime Taken\n",time_file);
    fputs("-------------- BUBBLE SORT -----------------\n",comparision_file);
    fputs("Size of Array\t\t\tNo. of Comparisions\n",comparision_file);
    int size_array = start_array_size;
    for(int i=0;i<count;i+=4)
    {
        fprintf(time_file,"%d\t\t\t\t%lf\n",size_array,duration[i]);
        fprintf(comparision_file,"%d\t\t\t\t\t%llu\n",size_array,comparisions[i]);
        size_array+=size_increment;
    }
        fprintf(time_file,"\n");
        fprintf(comparision_file,"\n");

        fclose(comparision_file);
        fclose(time_file);

    //Selection Sort Files
    comparision_file = fopen("SelectionSort-Comparisions.txt","w");

    if(comparision_file)
        printf("File SelectionSort-Comparisions.txt opened successfully.\n");
    else
        printf("Cannot open file for storing comparisions.\n");

    time_file = fopen("SelectionSort-time.txt","w");
    if(time_file)
        printf("File SelectionSort-time.txt opened successfully.\n");
    else
        printf("Cannot open the file for storing comparisions.\n");

    //Storing the values for selection sort
    fputs("-------------- SELECTION SORT -----------------\n",time_file);
    fputs("Size of Array\t\t\tTime Taken\n",time_file);
    fputs("-------------- SELECTION SORT -----------------\n",comparision_file);
    fputs("Size of Array\t\t\tNo. of Comparisions\n",comparision_file);
    size_array = start_array_size;
    for(int i=1;i<count;i+=4)
    {
        fprintf(time_file,"%d\t\t\t\t%lf\n",size_array,duration[i]);
        fprintf(comparision_file,"%d\t\t\t\t\t%llu\n",size_array,comparisions[i]);
        size_array+=size_increment;
    }
        fprintf(time_file,"\n");
        fprintf(comparision_file,"\n");

        fclose(comparision_file);
        fclose(time_file);
    
    //Merge Sort Files
    comparision_file = fopen("MergeSort-Comparisions.txt","w");

    if(comparision_file)
        printf("File MergeSort-Comparisions.txt opened successfully.\n");
    else
        printf("Cannot open file for storing comparisions.\n");

    time_file = fopen("MergeSort-time.txt","w");
    if(time_file)
        printf("File MergeSort-time.txt opened successfully.\n");
    else
        printf("Cannot open the file for storing comparisions.\n");


    //Storing the values for Merge sort
    fputs("-------------- MERGE SORT -----------------\n",time_file);
    fputs("Size of Array\t\t\tTime Taken\n",time_file);
    fputs("-------------- MERGE SORT -----------------\n",comparision_file);
    fputs("Size of Array\t\t\tNo. of Comparisions\n",comparision_file);
    size_array = start_array_size;
    for(int i=2;i<count;i+=4)
    {
        fprintf(time_file,"%d\t\t\t\t%lf\n",size_array,duration[i]);
        fprintf(comparision_file,"%d\t\t\t\t\t%llu\n",size_array,comparisions[i]);
        size_array+=size_increment;
    }
        fprintf(time_file,"\n");
        fprintf(comparision_file,"\n");

        fclose(comparision_file);
        fclose(time_file);

    
    //Quick Sort Files
    comparision_file = fopen("QuickSort-Comparisions.txt","w");

    if(comparision_file)
        printf("File QuickSort-Comparisions.txt opened successfully.\n");
    else
        printf("Cannot open file for storing comparisions.\n");

    time_file = fopen("QuickSort-time.txt","w");
    if(time_file)
        printf("File QuickSort-time.txt opened successfully.\n");
    else
        printf("Cannot open the file for storing comparisions.\n");

    //Storing the values for Quick sort
    fputs("-------------- QUICK SORT -----------------\n",time_file);
    fputs("Size of Array\t\t\tTime Taken\n",time_file);
    fputs("-------------- QUICK SORT -----------------\n",comparision_file);
    fputs("Size of Array\t\t\tNo. of Comparisions\n",comparision_file);
    size_array = start_array_size;
    for(int i=3;i<count;i+=4)
    {
        fprintf(time_file,"%d\t\t\t\t%lf\n",size_array,duration[i]);
        fprintf(comparision_file,"%d\t\t\t\t\t%llu\n",size_array,comparisions[i]);
        size_array+=size_increment;
    }
        fprintf(time_file,"\n\n");
        fprintf(comparision_file,"\n");

        //Closing the file pointers
        fclose(comparision_file);
        fclose(time_file);

    printf("Data written to the files.\n");
    //Freeing the memory
    free(duration);
    free(comparisions);
}
