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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size() > 2 && nums2.size() > 2) {
            int deleteSize = 0;
            if (nums1.size() > nums2.size()) {
                if (nums2.size() % 2 == 0) {
                    deleteSize = (int)(nums2.size() / 2) - 1;
                }else{
                    deleteSize = (int)(nums2.size() / 2);// + 1;
                }
            } else {
                if (nums1.size() % 2 == 0) {
                    deleteSize = (int)(nums1.size() / 2) - 1;
                }else{
                    deleteSize = (int)(nums1.size() / 2);// + 1;
                }
            }
            
            double mid1Value = 0;
            double mid2Value = 0;
            if (nums1.size() % 2 == 0) {
                mid1Value = (nums1[nums1.size()/2] + nums1[nums1.size()/2 - 1])/2.0;
            } else {
                mid1Value = nums1[nums1.size()/2];
            }
            if (nums2.size() % 2 == 0) {
                mid2Value = (nums2[nums2.size()/2] + nums2[nums2.size()/2 - 1])/2.0;
            } else {
                mid2Value = nums2[nums2.size()/2];
            }
            
            vector<int> subNum1,subNum2;
            if (mid1Value > mid2Value) {
                subNum1 = vector<int>(nums1.begin(),nums1.end() - deleteSize);
                subNum2 = vector<int>(nums2.begin() + deleteSize,nums2.end());
            }else if(mid1Value < mid2Value){
                subNum1 = vector<int>(nums1.begin() + deleteSize,nums1.end());
                subNum2 = vector<int>(nums2.begin(),nums2.end() - deleteSize);
            }else{
                return mid2Value;
            }
            return findMedianSortedArrays(subNum1, subNum2);
        } else {
            nums1.insert(nums1.end(), nums2.begin(), nums2.end());
            sort(nums1.begin(), nums1.end());
            
            size_t len = nums1.size();
            bool odd = len & 0x1;
            if (odd)
            {
                return nums1[len / 2];
            }
            else
            {
                return (nums1[len / 2] + nums1[len / 2 - 1]) / (double)2.0;
            }
        }
    }
};
int main(int argc, const char * argv[]) {
    
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(6);
    v1.push_back(7);
    vector<int> v2;
    v2.push_back(3);
    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(8);
    
    Solution sohution;
    printf("%f",sohution.findMedianSortedArrays(v1, v2));
    return 0;
}