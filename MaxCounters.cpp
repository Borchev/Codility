// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> result;
    result.resize(N);
    int maximum = 0;
    int savedmax = 0;
    
    for (unsigned int i = 0; i < A.size(); i++) {
        
        if (A[i] >= 1 && A[i] <= N) {    
            if (result[A[i] - 1] < savedmax) {
                result[A[i] - 1] = savedmax + 1;
            } else result[A[i] - 1]++;
            
            if (result[A[i] - 1] > maximum) maximum = result[A[i] - 1];
            continue;
        } else if (A[i] == N +1) savedmax = maximum;       
    }
    
    for (int i = 0; i < N; i++) {
            if (result[i] < savedmax) result[i] = savedmax;
    }
  
    return result;
}