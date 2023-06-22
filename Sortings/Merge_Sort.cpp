void merge(int arr[], int l, int m, int r)
{
     int i,j,k;
     int n1=m-l+1;
     int n2=r-m;
     int lm[n1], mr[n2];
     
     for(int i=0;i<n1;i++){
         lm[i]= arr[i+l];
     }
     
     for(int i=0;i<n2;i++){
         mr[i]= arr[i+m+1];
     }
     
     i=0;
     j=0;
     k=l;
     while(i<n1 && j<n2){
         if(lm[i]<=mr[j])
         {
             arr[k]=lm[i];
             i++;
         }
         else
         {
             arr[k]=mr[j];
             j++;
         }
         k++;
     }
     
     while(i<n1){
          arr[k]=lm[i];
          i++;
          k++;
     }
     
     while(j<n2){
         arr[k]=mr[j];
         j++;
         k++;
     }
     
}
void mergeSort(int arr[], int l, int r)
{
    if(l<r){                                  // REMEMBER here to use IF and not WHILE, I was getting runtime error for 15mins lol!!
        int mid=l+(r-l)/2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        merge(arr,l, mid, r);
    }
}

//Time Complexity: O(n*log(n))
//Space Complexity: O(n)

/*
Logic:
    Merge sort is a recursive algorithm that continuously splits the array in half
    until it cannot be further divided i.e., the array has only one element left
    (an array with one element is always sorted). Then the sorted subarrays are merged into one sorted array.
*/

/*
Complexity Analysis of Merge Sort:
Time Complexity: O(N log(N)),  Merge Sort is a recursive algorithm and time complexity can be expressed as following recurrence relation. 
    T(n) = 2T(n/2) + θ(n)
    The above recurrence can be solved either using the Recurrence Tree method or the Master method.
    It falls in case II of the Master Method and the solution of the recurrence is θ(Nlog(N)). 
    The time complexity of Merge Sort isθ(Nlog(N)) in all 3 cases (worst, average, and best) as merge sort always divides the array into two halves and takes linear time to merge two halves.

Auxiliary Space: O(N), 
    In merge sort all elements are copied into an auxiliary array. So N auxiliary space is required for merge sort.


Applications of Merge Sort:
    Sorting large datasets: Merge sort is particularly well-suited for sorting large datasets due to its guaranteed worst-case time complexity of O(n log n).
    External sorting: Merge sort is commonly used in external sorting, where the data to be sorted is too large to fit into memory.
    Custom sorting: Merge sort can be adapted to handle different input distributions, such as partially sorted, nearly sorted, or completely unsorted data.
    Inversion Count Problem
    
Advantages of Merge Sort:
    Stability: Merge sort is a stable sorting algorithm, which means it maintains the relative order of equal elements in the input array.
    Guaranteed worst-case performance: Merge sort has a worst-case time complexity of O(N logN), which means it performs well even on large datasets.
    Parallelizable: Merge sort is a naturally parallelizable algorithm, which means it can be easily parallelized to take advantage of multiple processors or threads.
    
Drawbacks of Merge Sort:
    Space complexity: Merge sort requires additional memory to store the merged sub-arrays during the sorting process. 
    Not in-place: Merge sort is not an in-place sorting algorithm, which means it requires additional memory to store the sorted data. This can be a disadvantage in applications where memory usage is a concern.
    Not always optimal for small datasets: For small datasets, Merge sort has a higher time complexity than some other sorting algorithms, such as insertion sort. This can result in slower performance for very small datasets.
*/
