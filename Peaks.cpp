// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    unsigned int listSize = A.size();
    unsigned int peaks[listSize];
    unsigned int result = 0;
    unsigned int totalpeaks = 0;

    fill(peaks,peaks + listSize,0);

    for (unsigned int i = 1; i < listSize; i++) {
    
        if ((i < listSize - 1) && (A[i - 1] < A[i]) && (A[i] > A[i + 1])) totalpeaks++;
        peaks[i+1] = totalpeaks;
    }    

    if (totalpeaks == 0) return 0;
    
    for (unsigned int i = 3; i <= listSize; i++) {

       if ((listSize % i) != 0) continue;
        for (int j = 0; j + i <= listSize; j+=i) {
             if ((peaks[j+i] - peaks[j]) == 0) break;
             else if ((j + i) == listSize) result = (result > listSize / i) ? result : listSize / i;     
        }
   }
    
   return result; 
}