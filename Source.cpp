///////////////////////////////////////////////////////////////////////////
// CountingSort/Source.cpp                                                     //
// ver 1.0                                                               //
// Type:	source file                                                    //
// Language:    C++                                                      //
// Platform:    HP Pavillon dv7, Visual Studio, Ubuntu 14.04/Windows 8.1 //
//              Asus Transformer T100TA, CodeBlocks, Windows 8.1         //
// Author:      Fouad youri, Lobachevsky research university - Russia    //
//              fouad709@gmail.com                                       //
///////////////////////////////////////////////////////////////////////////

#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void countingSort(int *array, int size) {
  clock_t start = clock();            //Starting the calculating the approx. time of execution
  long double nmbrOperations = 0;     //Helps to determine the number of operations

  int min = array[0];
  int max = array[0];

  for(int i = 0; i < size; i++) {
    min = (array[i] < min) ? array[i] : min;        //Finding the minimum value
    max = (array[i] > max) ? array[i] : max;        //and the maximum value
  }
  
  cout << "min value: " << min << endl;
  cout << "max value: " << max << endl;
  cout << endl;
  
  int newSize = max - min + 1;        //Determinaition of the size of the counting array (newSize)
  int *counting = new int[newSize];

  int k = 0;

  for(int i = 0; i < newSize; i++)    //Filling the Counting array with 0's
    counting[i] = 0;

  for(int i = 0; i < size; i++) {       //Starting our counting
    counting[array[i]]++;               
    nmbrOperations++;                   //and calculating the number of operations
  }

  for(int i = 0; i < newSize; i++) {
    int count = counting[i];
    for(int j = 0; j < count; j++) {
      array[k] = i;
      k++;
    }
  }
  
  cout << "Number of operations: " << nmbrOperations << endl;
  
  clock_t finish = clock();			//finishing the execution time calculation
  double time = double(finish - start) / CLOCKS_PER_SEC;	//calculating the execution time
  cout << "Execution time: " << time << endl;			//and printing it

  delete[] counting;          //free memory
}


int main() {
  int size;
  
  cout << "====== CountingSort =====" << endl;
  cout << "Please input the size of your array: " << endl;
  cin >> size;

  int *array = new int[size];         //creating the main array
  for (int i = 0; i < size; i++) {    //filling it with random integer numbers
    array[i] = rand() % 100;          //
  }                                   

  cout << "Original Array: "<< endl;

  for(int i = 0; i < size; i++)
    cout << array[i] << " ";              //printing the main array before sorting

  cout << endl << endl;

  countingSort(array, size);          //calling our function to sort the array

  cout << endl << "CountingSort: "<< endl;

  for(int i = 0; i < size; i++)
    cout << array[i] << " ";              //printing the main array after sorting

  cout << endl;
  delete [] array;        //free memory
  return 0;
}
