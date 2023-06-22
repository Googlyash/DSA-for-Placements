void insertionSort(int arr[], int n)
{
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                swap(arr[j],arr[i]);
            }
        }
    }
}

//Time Complexity: O(n^2)
//Space Complexity: O(1)

/*
Logic: 
    To sort an array of size N in ascending order iterate over the array and compare the current element (key)
    to its predecessor, if the key element is smaller than its predecessor, compare it to the elements before.
    Move the greater elements one position up to make space for the swapped element.
*/


/*
Time Complexity of Insertion Sort:
  The worst-case time complexity of the Insertion sort is O(N^2)
  The average case time complexity of the Insertion sort is O(N^2)
  The time complexity of the best case is O(N).
Space Complexity of Insertion Sort:
  The auxiliary space complexity of Insertion Sort is O(1)

Characteristics of Insertion Sort:
  ->This algorithm is one of the simplest algorithms with a simple implementation.
  ->Basically, Insertion sort is efficient for small data values.
  ->Insertion sort is adaptive in nature, i.e. it is appropriate for data sets that are already partially sorted.
  
Frequently Asked Questions on Insertion Sort:
  Q1. What are the Boundary Cases of the Insertion Sort algorithm?
    ->Insertion sort takes the maximum time to sort if elements are sorted in reverse order.
    -> It takes minimum time (Order of n) when elements are already sorted. 
  
  Q2. What is the Algorithmic Paradigm of the Insertion Sort algorithm?
    ->The Insertion Sort algorithm follows an incremental approach.
  
  Q3. Is Insertion Sort an in-place sorting algorithm?
    ->Yes, insertion sort is an in-place sorting algorithm.
  
  Q4. Is Insertion Sort a stable algorithm?
    ->Yes, insertion sort is a stable sorting algorithm.
  
  Q5. When is the Insertion Sort algorithm used?
    ->Insertion sort is used when number of elements is small.
    ->It can also be useful when the input array is almost sorted, and only a few elements are misplaced in a complete big array.
*/

//https://www.geeksforgeeks.org/insertion-sort/
