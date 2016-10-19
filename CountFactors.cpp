// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++11 (g++ 4.8.2)
    int count = 0;
    int upperlimit = sqrt(N);
    int incrementer;
    
    if (N == 1) return 1;
    for (incrementer = 2; incrementer <= upperlimit; incrementer++) {

        if (!(N % incrementer)) { 
            
            if ((incrementer * incrementer) == N) count+=1; // should move outside loop
            else count+=2;
        }
    }
    
    return count + 2;
}