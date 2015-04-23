//
//  main.cpp
//  Test
//
//  Created by joywii on 15/4/23.
//  Copyright (c) 2015年 sohu. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int charCount[256] = {0};
        int maxLength = 0;
        int currentL = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if (charCount[static_cast<int>(s[i])] == 0) {
                charCount[static_cast<int>(s[i])] = 1;
                currentL ++;
                if (currentL > maxLength) {
                    maxLength = currentL;
                }
            } else {
                int deleteL = 0;
                for (int j = i - currentL; j < i; j++) {
                    charCount[static_cast<int>(s[j])] = 0;
                    deleteL ++;
                    if (charCount[static_cast<int>(s[i])] == 0) {
                        break;
                    }
                }
                currentL -= deleteL;
                charCount[static_cast<int>(s[i])] = 1;
                currentL++;
            }
            
            
        }
        return maxLength;
    }
};
int main(int argc, const char * argv[]) {
    
    Solution sohution;
    string sss = "loddktdji";
    printf("%d",sohution.lengthOfLongestSubstring(sss));
    
    return 0;
}

