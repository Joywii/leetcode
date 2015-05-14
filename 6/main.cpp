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
    string convert(string s, int numRows) {
        string s1;
        int per = numRows * 2 - 2;
        if (per <= 0) {
            return s;
        }
        int count = (int)s.length() / per + 1;
        
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < count; j++) {
                int m = j*per + i;
                if (m >= s.length()) {
                    break;
                }
                s1.insert(s1.end(),s[m]);
                if (i != 0 && i != numRows-1) {
                    int t = j*per + per - i;
                    if (t < s.length()) {
                        s1.insert(s1.end(), s[t]);
                    }
                }
            }
            
        }
        return s1;
    }
};

int main(int argc, const char * argv[]) {
    
    string s("ABCDEF");
    Solution sohution;
    printf("%s",sohution.convert(s,3).c_str());
    return 0;
}