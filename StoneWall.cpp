// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &H) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> heights;
    heights.push_back(H[0]);
    int closecount = 0;

    for (unsigned int i = 1; i < H.size(); i++) {
        if (heights.back() == H[i]) continue;
        if (heights.back() < H[i]) {
            heights.push_back(H[i]);
        } else {
            closecount++;
            heights.pop_back();
            i--;
        }    
    }
    
    closecount += heights.size();
    return closecount;
}