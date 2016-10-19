// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++11 (g++ 4.8.2)
    vector<pair<int,int>> fish_stack;
    
    fish_stack.push_back(pair<int,int> {A[0],B[0]});
    
    for (unsigned int i = 1; i < A.size(); i ++) {
             
         if ((B[i] < fish_stack[fish_stack.size()-1].second)) {
            
           
           if  (A[i] > fish_stack[fish_stack.size()-1].first) {
           
            fish_stack.pop_back();
            i--;
           }
        
         
         } else fish_stack.push_back(pair<int,int> {A[i],B[i]});
        
    }

    return fish_stack.size();
}