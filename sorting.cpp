#include "sorting.h"

void selectionSort(int *array, int size) {
	//Initializing temporary variables
    int i, j, imin, temp;
	//Iterating for each items before last element
    for(i = 0; i < size-1; i++) {
        
        imin = i;//Taking min position as current
        //Iterate through all numbers inorder to choose min position
        for(j = i+1; j<size; j++)
        {
			//If the element is smaller than the min position
			//Then picking that as min position
            if(array[j] < array[imin])
                imin = j;
        }
        //Swapping the min position with the currect position
        temp = array[i];
        array[i] = array[imin];
        array[imin] = temp;
    }
}

void insertionSort(int *array, int size)  
{  
	//Initializing temporary variables
    int i, key, j;  
	//Iterating through all the elements
    for (i = 1; i < size; i++) 
    {  
        key = array[i];  
        j = i - 1;  
		//Looping until some element is greater than the key value
        while (j >= 0 && array[j] > key) 
        {  
            array[j + 1] = array[j];  
            j = j - 1;  
        }  
        array[j + 1] = key;  
    }  
}  


void shellSort(int *array, int size) 
{ 
	//Binning size from half the total size to 1
    for (int bin = size / 2; bin > 0; bin /= 2) 
    { 
        for (int i = bin; i < size; i += 1) 
        { 
            int temp = array[i]; 
			//Based on the bin size, the element will be moved to its approp. position
            int j;             
            for (j = i; j >= bin && array[j - bin] > temp; j -= bin) 
                array[j] = array[j - bin]; 
              
            array[j] = temp; 
        } 
    } 
} 

//Utility method to swap two mumbers
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int partition (int *array, int low, int high)  
{  
    int pivot = array[high]; // pivot  element
    int i = (low - 1); 
	//Iterating through elements from low to high index
    for (int j = low; j <= high - 1; j++)  
    {  
        if (array[j] < pivot)  //If the element in smaller than pivot, then move 
        {  
            i++; 
            swap(&array[i], &array[j]);  
        }  
    }  
    swap(&array[i + 1], &array[high]);  
    return (i + 1);  
}  

void quickSort(int *array, int low, int high)  
{  
    if (low < high)  
    {  
        int pivot = partition(array, low, high);  
		//dividing the array into 2 smaller parts until its one element smaller
        quickSort(array, low, pivot - 1);  
        quickSort(array, pivot + 1, high);  
    }  
}  

void merge(int *array, int left, int middle, int right)
{
	//Declaring two individual parts as two arrays
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int leftArray[n1], rightArray[n2];
 
	//Copying the array elements into the temporary array parts
    for (int i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = array[middle + 1 + j];
 
    int i = 0, j = 0, k = left;
 
	//Merging the left and right array
    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        }
        else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }
	
	//Assigning the left over in any of the part arrays
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int *array, int left,int right){
	//Stopping point for the recursive call
    if(left >= right){
        return;
    }
	
	//Picking the middle point and divide the array into two parts
    int middle = (left + right - 1) / 2;
    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);
	//Merging the individual sorted parts into single array
    merge(array, left, middle, right);
}