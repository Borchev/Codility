// you can use includes, for example:
// #include <algorithm>
#include <cstring>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int numbers[A.size()];
    memset(numbers,0,sizeof(numbers));
    
    for (int i = 0; i < A.size(); i++) {
        
        if ((A[i] > 0) && (A[i] <= A.size() )) numbers[A[i] - 1] = 1;
        
    }
    
    for (int i = 1; i <= A.size(); i++) {
        if (!numbers[i - 1]) return i;       
    }
      
}