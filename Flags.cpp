// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int listSize = A.size();
    int flagMap[listSize];
    int lastFlag = -1;
    int tempA = 0;
    int tempB = 0;
    int count = 0;
    int result = 0;
      
    for (int i = listSize - 2; i >= 0; i--) {
            
        if ((i > 0) && (A[i - 1] < A[i]) && (A[i] > A[i + 1])) {
            flagMap[i] = lastFlag;
            lastFlag = i;
        } else flagMap[i] = 0;    
    }
    
    if (lastFlag < 0) return 0;
    
    for (int i = 2; ((i - 1) * i) < listSize; i++) {
        
        count = 1;
        tempA = lastFlag;
        tempB = tempA;
        while (true) {
            tempB = flagMap[tempB];
            if ((tempB < 0) || (count == i)) break;
            if ((tempB - tempA) >= i) {
                count++;
                tempA = tempB;
            }           
        }   
         result = (result < count) ? count : result;
    }  
    return result;
}