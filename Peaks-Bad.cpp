// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    vector<unsigned int> peaks;
    unsigned int result = 0;
    unsigned int searchIndex = 0;
    unsigned int skip = 0;
    
    
    for (unsigned int i = 1; i < A.size() - 1; i++) {
    
        if ((A[i - 1] < A[i]) && (A[i] > A[i + 1])) peaks.push_back(i);
       
    }
    
    if (peaks.size() == 0) return 0;
    
    for (unsigned int i = 3; i <= A.size(); i++) {

       if ((A.size() % i) != 0) continue;
       
       while (searchIndex < A.size()) {
           
           if (!((peaks[searchIndex + skip] >= (searchIndex * i)) && (peaks[searchIndex + skip] <= ((searchIndex * i) + i)))) {
               if ((skip + searchIndex) < peaks.size() - 1) {
                   skip++; 
                   continue;
               } else break;     
            }
            else {         
               searchIndex ++;
           }
       }
       
       if (searchIndex == (A.size() / i)) {
            result = (result < searchIndex) ? searchIndex : result;
            break;
        }
          
       searchIndex = 0;
       skip = 0;
   }
    
    return result; 
}