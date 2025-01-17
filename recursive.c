int recusive(int A[], int left, int right, int val) {
    int middle = left + (right - left) / 2;
    if (A[middle] == val) {
        return middle;
    }
    else if (A[middle] < val) // val will be on right size, search: middle+1 to right
        return recursion(A, middle+1, right, val);
    else 
        return recursion(A, left, middle-1, val); 
}