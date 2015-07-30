//
//  main.cpp
//  LeetCode
//
//  Created by joywii on 15/7/13.
//  Copyright (c) 2015年 joywii. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x == 0) {
            return true;
        }
        
        long resver = 0;
        
        int last = x;
        while (last > 0) {
            resver = resver * 10 + last % 10;
            last = last / 10;
        }
        if (resver == x) {
            return true;
        }
        return false;
    }
};
int main(int argc, const char * argv[])
{
    Solution solution;
    if (solution.isPalindrome(121)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
