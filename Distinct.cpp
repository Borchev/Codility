// you can use includes, for example:
 #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int comparator(const void * first, const void * second);

int solution(vector<int> &A) {
    if (A.size() == 0) return 0;
    // write your code in C++11 (g++ 4.8.2)
    int result = 0;
    sort(A.begin(),A.end());
    for (unsigned int i = 1; i < A.size(); i++) {
       // cout << A[i-1] << " " << A[i] << endl;
        if (A[i] != A[i-1]) result++;
    }
    return result+1;
}