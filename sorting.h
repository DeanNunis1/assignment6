#include <iostream>

using namespace std;

#ifndef SORTING_H
#define SORTING_H
 
void selectionSort(int *array, int size);

void insertionSort(int *array, int size);

void shellSort(int *array, int size);

void swap(int* a, int* b);

int partition (int *array, int low, int high);

void quickSort(int *array, int low, int high);

void merge(int *array, int left, int middle, int right);
 
void mergeSort(int *array, int left,int right);

#endif