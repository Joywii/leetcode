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
    string longestPalindrome(string s) {
        
        string sub = "";
        for (int i = 0; i < s.length(); i++) {
            int m = i-1,n = i+1;
            
            while (n < s.length()) {
                if (s[i] == s[n]) {
                    n++;
                }else{
                    break;
                }
            }
            n--;
            while (m >= 0) {
                if (s[i] == s[m]) {
                    m--;
                }else{
                    break;
                }
            }
            m++;
            while (m >= 0 && n < s.length()) {
                if (s[m] == s[n]) {
                    m--;
                    n++;
                }else{
                    break;
                }
            }
            int length = n - (++m);
            string temp = s.substr(m++,length);
            if (temp.length() > sub.length()) {
                sub = temp;
            }
        }
        return sub;
    }
};
int main(int argc, const char * argv[]) {
    
    string s("ccc");
    Solution sohution;
    printf("%s",sohution.longestPalindrome(s).c_str());
    return 0;
}