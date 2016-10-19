// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int>::iterator it1 = A.begin();
    vector<int>::iterator it2 = A.end()-1;
    int result = 0;
    int temp;
    int taskSwitch = 0;
    
    while (*it1 == -2147483648) {
        ++it1;
        result = 1;
    }
    
    while (it1 <= it2) {
        
        taskSwitch |= (abs(*it1) > abs(*it2));
        taskSwitch |= 2 * (abs(*it1) < abs(*it2));
        taskSwitch |= 3 * (abs(*it1) == abs(*it2));
   
        if (taskSwitch & 1) {
            temp = abs(*it1);
            while (abs(*it1) == temp) {
                ++it1;
            }
        }
               
        if (taskSwitch & 2) { 
            temp = abs(*it2);
            while (abs(*it2) == temp) {
                --it2;
            }
        }
        
        taskSwitch = 0;
        result ++;
    }
    
    return result;
        
}