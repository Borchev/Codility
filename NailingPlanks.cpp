// you can use includes, for example:
// #include <algorithm>
#include <cstring>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
void generateRunningNails(int *runningNails, vector<int> &C, int count, int size);
bool doCheck(vector<int> &A, vector<int> &B, int *runningNails);

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    // write your code in C++11 (g++ 4.8.2)
    
    int *runningNails = new int[(2 * C.size())+1]{};
    int max = C.size();
    int min = 1;
    int result = -1;
    int temp = 0;
 
   
      while (min <= max) {
        temp = (min + max) / 2;
        generateRunningNails(runningNails, C, temp, (2 * C.size())+1);
         
        if (doCheck(A, B, runningNails)) {
            
            max = temp - 1;
            result = temp;
            
        } else {
            min = temp + 1;
        }
    
    }
    
    return result;
}

void generateRunningNails(int *runningNails, vector<int> &C, int count, int size) {

    memset(runningNails, 0, size * sizeof(int));
    
    for (int i = 0; i < count; i++) {
        runningNails[C[i]] = 1;
    }
    
    for (int i = 1; i < size; i++) {
        runningNails[i] += runningNails[i-1];
    }


}


bool doCheck(vector<int> &A, vector<int> &B, int *runningNails) {
    
    for (unsigned int i = 0; i < A.size(); i++) {
        if (((runningNails[A[i] - 1] - runningNails[B[i]]) == 0)) return false;
    }
    
    return true;
    
}