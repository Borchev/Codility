// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int min = 1 << ((8 * sizeof(int))-1)-1;
    int arraytotal = 0;
    int temp = 0;
    
    for (unsigned int i = 0; i < A.size(); i++) {
        arraytotal += A[i];
    }
    
    for (unsigned int i = 0; i < A.size() - 1; i++) {
       // cout << arraytotal;
        temp += A[i];
        min = (abs(arraytotal - 2*temp) < min) ? abs(arraytotal - 2*temp): min;
    }  
    return min;
}