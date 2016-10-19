// you can use includes, for example:
// #include <algorithm>
#include <cstring>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int leaves[X];
    int maxtime = 0;
    memset(leaves, -1, sizeof(leaves));
    
    for (unsigned int i = 0; i < A.size(); i++) {      
       if ((leaves[A[i] - 1] > i) || (leaves[A[i] - 1] == -1)) leaves[A[i] - 1] = i; 
    }
    
    for (int i = 0; i < X; i++) {
        if (leaves[i] == -1) return -1;
        if (leaves[i] > maxtime) maxtime = leaves[i];
    }
    
    return maxtime;
}