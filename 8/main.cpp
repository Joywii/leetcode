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
    int myAtoi(string str) {
        int value = 0;
        int mark = 0;
        int count = 0;
        int numCount = 0;
        int max = 0;
        int min = 0;
        for (int i = 0; i < str.length(); i++) {
            char item = str[i];
            if (value == 0) {
                if (item == '-') {
                    count++;
                    mark -= 1;
                    if (count > 1) {
                        break;
                    } else {
                        continue;
                    }
                }
                if (item == '+') {
                    count++;
                    mark += 1;
                    if (count > 1) {
                        break;
                    } else {
                        continue;
                    }
                }
            }
            if (item >= '0' && item <= '9') {
                numCount++;
                int itemValue = item - '0';
                
                min = 0;
                if (mark < 0) {
                    //负数最小值判断
                    if ((itemValue < ((INT32_MAX - value*10) + 1) || itemValue < (INT32_MAX - value*10)) && numCount < 11) {
                        value = (value * 10) + itemValue;
                    } else {
                        min = 1;
                        value = INT32_MIN;
                        break;
                    }
                } else {
                    if (itemValue < (INT32_MAX - value*10) && numCount < 11) {
                        value = (value * 10) + itemValue;
                    } else {
                        max = 1;
                        value = INT32_MAX;
                        break;
                    }
                }
            } else {
                //if (numCount != 0 || count != 0) {
                //    break;
                //}
                if (item == ' ' && numCount == 0 && count == 0) {
                    continue;
                } else {
                    break;
                }
            }
        }
        
        if (min == 1 || max == 1) {
            return value;
        }
        if (count == 0) {
            return value;
        } else {
            if (mark < 0) {
                if (max == 1) {
                    return INT32_MIN;
                }
                return value * -1;
            }
            else if (mark > 0) {
                return value;
            } else {
                return value * mark;
            }
        }
        return value * mark;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    //"  +0 123"  "  + 123"
    int value = solution.myAtoi("    10522545459");
    cout << value;
    cout << endl;
    cout << INT32_MAX << " " << INT32_MIN;
    return 0;
}
