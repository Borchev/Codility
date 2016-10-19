// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int gcd(int a, int b);
bool sameFactors(int a, int b);

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11 (g++ 4.8.2)
    int result = 0;
    
    for (unsigned int i = 0; i < A.size(); i++) {
        
        if (sameFactors(A[i], B[i]) && sameFactors(B[i], A[i])) result++;
             
    }

    return result;
}

bool sameFactors(int a, int b) {
    
        int common = gcd(a,b);
        int noncommon = a / common;
        int temp;
    
       while ((common % noncommon) != 0) {
           
           temp = gcd(common, noncommon);
           noncommon /= temp;
           
           if ((noncommon != 1) && (temp == 1)) return false;
           
       }
       
       return true;
}

int gcd(int a, int b) {
    if (b == 0)
       return a; 
    else
       return gcd(b, a % b);
}