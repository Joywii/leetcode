//: Playground - noun: a place where people can play

import UIKit

class Solution1 {
    func maxArea(_ height: [Int]) -> Int {
        var maxArea = 0
        var l = 0
        var r = height.count - 1
        while l < r {
            maxArea = max(maxArea, min(height[l], height[r]) * (r - l))
            if height[l] <= height[r] {
                var k = l
                while k < r && height[k] <= height[l] {
                    k += 1
                }
                l = k
            } else {
                var k = r
                while k > l && height[k] <= height[r] {
                    k -= 1
                }
                r = k
            }
        }
        return maxArea
    }
}

var solution = Solution1()
solution.maxArea([4,6,2,6,7,11,2])