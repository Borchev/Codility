// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
bool iterate(int K, vector<int> &A, int value);

int solution(int K, int M, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
    int min = A[0];
    int max = A[0];
    int result = 0;
    int temp;
    
    for (unsigned int i = 1; i < A.size(); i++) {
        
        min = (A[i] > min) ? A[i] : min; 
        max += A[i];       
    }
    
    while (min <= max) {
        temp = (min + max) / 2;
        if (iterate(K, A, temp)) {
            
            max = temp - 1;
            result = temp;
            
        } else {
            min = temp + 1;
        }
    
    }
    return result;
}

bool iterate(int K, vector<int> &A, int value) {
    
    int sum = 0;
    int count = 1;

    for (unsigned int i = 0; i < A.size(); i++) {
    
        if (sum + A[i] > value) {
            sum = A[i];
            count++;
            if (count > K) return false;
            
        } else sum += A[i];
        
    }

    return true;
}