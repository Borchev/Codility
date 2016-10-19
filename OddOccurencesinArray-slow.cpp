// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int i,j; 
    for (i = 0; i < A.size() - 1; i++) {
         for (j = i + 1; j < A.size(); j++) {
             if (A[i] == A[j]) {
                 A.erase(A.begin()+i);
                 A.erase(A.begin()+j-1);
                 i--;
                 break;
             }   
         } 
    }
    return A[0];    
}