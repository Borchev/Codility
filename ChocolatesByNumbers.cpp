// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int gcd(int a, int b);
int solution(int N, int M) {
    // write your code in C++11 (g++ 4.8.2)
    return N / gcd(M,N);
}

int gcd(int a, int b) {

    if (b == 0)
       return a; 
    else
       return gcd(b, a % b);
}