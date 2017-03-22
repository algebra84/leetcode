set(LEETCODE
    hello
    twoSum
    3Sum
    4Sum
    4Sum2
)
foreach(_leetcode ${LEETCODE})
ADD_EXECUTABLE(${_leetcode} ${_leetcode}.cpp )
endforeach(_leetcode ${LEETCODE})
