cmake_minimum_required(VERSION 3.17)
project(DataStruct)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(leetcode)

add_executable(DataStruct
        leetcode/subarraysWithKDistinct.cpp
        hello.c
        leetcode/lengthOfLongestSubstring.cpp
        leetcode/minWindow.cpp
        leetcode/maxSlidingWindow.cpp
        leetcode/longestSubstring.cpp
        leetcode/lengthOfLongestSubstringTwoDistinct.cpp
        leetcode/lengthOfLongestSubstringKDistinct.cpp
        leetcode/characterReplacement.cpp
        leetcode/medianSlidingWindow.cpp
        leetcode/checkInclusion.cpp
        leetcode/maxTurbulenceSize.cpp)
