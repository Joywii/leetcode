//
//  main.cpp
//  Test
//
//  Created by joywii on 15/4/23.
//  Copyright (c) 2015年 sohu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        
        int p = 1;
        if (x < 0) {
            x = -x;
            p = -1;
        }
        int y = x % 10;
        int m = x / 10;
        int n = 0;
        while (m > 0 || y > 0) {
            
            if ((INT_MAX - y) / 10 < n) {
                return 0;
            }
            n = n*10 + y;
            
            y = m % 10;
            m = m / 10;
        }
        return n*p;
    }
};

int main(int argc, const char * argv[]) {
    
    int a = 100;
    Solution sohution;
    printf("%d",sohution.reverse(a));
    return 0;
}