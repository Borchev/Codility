// you can use includes, for example:
// #include <algorithm>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    int result = 0;
    
    for (result = sqrt(N); result > 0; result --) {
        
        if ((N % result) == 0) return (2 * ((N / result) + result));
        
    }
}