// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    pair<int,int> leader;
    int leadercount = 0;
    int result = 0;
    int swapb, swapa = 0;
    
    for (unsigned int i = 0; i < A.size(); i++) {
        
        if (leader.second == 0) {
            leader.first = A[i];
            leader.second++;
        } else if (leader.first == A[i]) leader.second++;
        else leader.second--;    
    }
    
    for (unsigned int i = 0; i < A.size(); i++) {
        
        if (A[i] == leader.first) leadercount++;       
    }
    
    for (unsigned int i = 0; i < A.size(); i++) {
    
        if (A[i] == leader.first) swapa++;
        swapb = leadercount - swapa;
        if ((swapb > ((A.size() - i - 1) / 2)) && (swapa > ((i + 1) / 2))) result++;
    }
    
    return result;
}