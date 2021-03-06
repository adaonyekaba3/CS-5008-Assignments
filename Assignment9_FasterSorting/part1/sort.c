// Task: Implement the 'sortIntegers' function below

// =================== Libraries ==================
#include <stdio.h> // Include file for standart input/output

// =============== Helper Functions ===============

// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) {
	//TODO: implement merge.
	// Create L <- arr[l..m] and M <- arr[q+1..r]
	int n1 = m-l+1;
	int n2 = r-m;

	int L[n1], M[n2];

	for(int i=0; i < n1; i++){
		L[i] = arr[l+1];
		
		for(int j=0; j < n2; j++){
			M[j] = arr[m+1+j];
		}
	}
	// Maintain current index of sub-arrays and main array
	int i,j,k;
	i=0;
	j=0;
	k=l;
	
	// Until we reach either end of either L or M, pick larger 
	// among elements L and M and place them in the correct pos at A[l..r].
	while(i < n1 && j < n2){
		if(L[i] <= M[j]){
			arr[k] = L[i];
			i++;
		}else{
			arr[k] = M[j];
			j++;
		}k++;
	}
	// When we run out of elements in either L or M, 
	// pick up the remaining elements and put A[l..m]
	while(i < n1){
		arr[k] = L[i];
		i++;
		k++;

	}while(j < n2){
		arr[k] = M[j];
		j++;
		k++;	
	}
}
// Implement your mergeSort function here
// TODO:
void mergeSort(int arr[], int l, int r){
	
	if(l < r){
		// 1. m is the point where the array is divided into 2 subarrays 
		int m = 1+(r-1) / 2;
		
		// 2.  call mergeSort for first half:
		mergeSort(arr, l, m);

		// 3. call mergeSort for second half:
		mergeSort(arr, m+1, r);
		
		// 4. merge the two halves sorted in 2 & 3:
		merge(arr, l, m, r); // call merge function
	}
}

// Declare swap function
void swap(int* a, int* b){
	
	// TODO: SWAP two integers in an array. 
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Provided below is a sort function. We have also
// provided a template for how to document functions
// to help organize your code.
// Name: sortIntegers
// Input(s):
//          (1) 'array' is a pointer to an integer address. 
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'size' tells us how big the array of data is we are sorting.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void sortIntegers(int* array, unsigned int size){
	// TODO: make a call to your mergeSort function here
	int i, j;
	
	// first loop -  iterate over each element in array
	for(i=1; i < size; i++){
		j= i-1;
		// second loop - use a while loop to search
		// for ith element towards first element in array
		while(j>=0 && array[j] > array[j+1]){
			/* loop stops at 1 of 2 conditions:
 * 			   1. if we reach the first element of the array or 
 * 			   2. if we get two sorted element in ascending order */
			swap(array+j+1, array+j); 	// swapping the unsorted elements
			j = j-1;
		}
	}	
}


// Input: A pointer to an array (i.e. the array itself points to the first index)
//        The size of the array (Because we do not know how big the array is automatically)
void printIntArray(int* array, unsigned int size){
  unsigned int i; // Note: 'unsigned int' is a datatype for storing positive integers.
  for(i = 0; i < size; i=i+1){
    printf("%d ",array[i]);
  }
  printf("\n");
}

int main(){
  
  // Some test data sets.
  int dataset1[] = {0,1,2,3,4,5,6,7,8,9,10};
  int dataset2[] = {10,9,8,7,6,5,4,3,2,1,0};
  int dataset3[] = {0,3,2,1,4,7,6,5,8,9,10};
  int dataset4[] = {2,1,1,1,1,1,1,1,1,1,1};
  int dataset5[] = {100,201,52,3223,24,55,623,75,8523,-9,150};
  int dataset6[] = {-1,1,2,-3,4,5,-6,7,8,-9,10};
  
  // Sort our integer array
  sortIntegers(dataset1, 11);
  sortIntegers(dataset2, 11);
  sortIntegers(dataset3, 11);
  sortIntegers(dataset4, 11);
  sortIntegers(dataset5, 11);
  sortIntegers(dataset6, 11);
  
  // Print out an array
  printIntArray(dataset1, 11);
  printIntArray(dataset2, 11);
  printIntArray(dataset3, 11);
  printIntArray(dataset4, 11);
  printIntArray(dataset5, 11);
  printIntArray(dataset6, 11);
  
  return 0;
}
