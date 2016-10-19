// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    int left = 0;
    int right = A.size() - 1;
    int minimum = abs(A[0] * 2);
    int temp;
    
    sort(A.begin(), A.end());
    
    while (left <= right) {
        
        temp = min({abs(A[left]*2), abs(A[right]*2), abs(A[left] + A[right])});       
        minimum = (minimum > temp) ? temp : minimum;
        
        if (abs(A[left]) > abs(A[right])) left++;
        else if (abs(A[right]) > abs(A[left])) right--;
        else {
            left++;
            right--;
        }
    }
    
    return minimum;
    
}