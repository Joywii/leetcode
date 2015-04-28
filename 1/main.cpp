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
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> index;
        for (int i = 0 ; i < nums.size() ; i++) {
            index[nums[i]] = i;
        }
        vector<int> twoNum;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            map<int,int>::iterator it = index.find(target - num);
            if (it != index.end()) {
                
                int i2 = it->second;
                if (i == i2) {
                    continue;
                }
                if (i < i2) {
                    twoNum.push_back(i + 1);
                    twoNum.push_back(i2 + 1);
                } else {
                    twoNum.push_back(i2 +1);
                    twoNum.push_back(i + 1);
                }
                break;
            }
        }
        return twoNum;
    }
};
int main(int argc, const char * argv[]) {
    
    Solution sohution;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    
    vector<int> result = sohution.twoSum(nums, 6);
    for (int i = 0; i < result.size(); i++) {
        printf("%d ", result[i]);
    }
    
    return 0;
}
