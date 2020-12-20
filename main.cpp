#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono> 
#include <ctime> 

#include "sorting.h"

using namespace std;

int main(int argc, char **argv) 
{
    
    if(argc != 2)   //Validating Input file name given in cmd arg
    {
        cout << "Please provide an input file as argument." << endl;
        return 0;
    }
    
    //Initializing five pointers to hold 5 copies of input values.
    int *A, *B, *C, *D, *E;
    
    //Initializing input file stream pointer
    ifstream inputFile;
    inputFile.open(argv[1]);
    
    //Initializing all temporary variables
    string line;
    int i = -1, value, size = 0;
    
    while (!inputFile.eof()) { 
  
    
        getline(inputFile, line); 
  
        stringstream ss1(line); 
        ss1 >> value;
        
        if(i == -1)
        {
            size = value;
            //Allocating memory for the size
            A = (int*)malloc(value * sizeof(int));
            B = (int*)malloc(value * sizeof(int));
            C = (int*)malloc(value * sizeof(int));
            D = (int*)malloc(value * sizeof(int));
            E = (int*)malloc(value * sizeof(int));
        }
        else
        {
            //Assigning values into the array
            A[i] = value;
            B[i] = value;
            C[i] = value;
            D[i] = value;
            E[i] = value;
        }
        
        i++;
    }
    
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::time_t start_time, end_time;
    
    //Selection Sort
    
    start = std::chrono::system_clock::now();
    start_time = std::chrono::system_clock::to_time_t(start);
    
    cout << "Selection sort:\nStart Time : " << std::ctime(&start_time) ;
    
    selectionSort(A, size);

    end = std::chrono::system_clock::now(); 
    end_time = std::chrono::system_clock::to_time_t(end);
    
    cout << "End Time : " <<  std::ctime(&end_time) ;
    
    std::chrono::duration<double> elapsed_seconds = end - start; 
    
    
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s"  << endl  << endl; 
    
    
    //Insertion Sort
    
    start = std::chrono::system_clock::now();
    start_time = std::chrono::system_clock::to_time_t(start);
    
    cout << "Insertion sort:\nStart Time : " << std::ctime(&start_time) ;
    
    insertionSort(B, size);

    end = std::chrono::system_clock::now(); 
    end_time = std::chrono::system_clock::to_time_t(end);
    
    cout << "End Time : " <<  std::ctime(&end_time) ;
    
    elapsed_seconds = end - start; 
    
    
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s"  << endl  << endl; 
    
    
    //Shell Sort
    
    start = std::chrono::system_clock::now();
    start_time = std::chrono::system_clock::to_time_t(start);
    
    cout << "Shell sort:\nStart Time : " << std::ctime(&start_time) ;
    
    shellSort(C, size);

    end = std::chrono::system_clock::now(); 
    end_time = std::chrono::system_clock::to_time_t(end);
    
    cout << "End Time : " <<  std::ctime(&end_time) ;
    
    elapsed_seconds = end - start; 
    
    
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s"  << endl  << endl; 
    
    
    //Quick Sort
    
    start = std::chrono::system_clock::now();
    start_time = std::chrono::system_clock::to_time_t(start);
    
    cout << "Quick sort:\nStart Time : " << std::ctime(&start_time) ;
    
    quickSort(D, 0, size);

    end = std::chrono::system_clock::now(); 
    end_time = std::chrono::system_clock::to_time_t(end);
    
    cout << "End Time : " <<  std::ctime(&end_time) ;
    
    elapsed_seconds = end - start; 
    
    
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s"  << endl  << endl; 
    
    //Merge Sort
    
    start = std::chrono::system_clock::now();
    start_time = std::chrono::system_clock::to_time_t(start);
    
    cout << "Merge sort:\nStart Time : " << std::ctime(&start_time) ;
    
    mergeSort(E, 0, size);

    end = std::chrono::system_clock::now(); 
    end_time = std::chrono::system_clock::to_time_t(end);
    
    cout << "End Time : " <<  std::ctime(&end_time) ;
    
    elapsed_seconds = end - start; 
    
    
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s"  << endl  << endl; 
              
    return 0;
}
