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
    
    
    while (*it1 == -2147483648) {
        ++it1;
        result = 1;
    }
  
    while (it1 <= it2) {
        if (abs(*it1) > abs(*it2)) {
            temp = abs(*it1);
            while (temp == abs(*it1)) {
                ++it1;
            }
        }
        else if (abs(*it1) < abs(*it2)) {
            temp = abs(*it2);
            while (temp == abs(*it2)) {
                --it2;
            }
        }
        else {
            temp = abs(*it1);
            while ((abs(*it1) == temp)) {
                ++it1;
            }
            
            while ((abs(*it2) == temp)) {
                --it2;
            }
        }
        result ++;
    }
    
    return result;
        
}