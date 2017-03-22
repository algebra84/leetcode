set(LEETCODE
    hello
    twoSum
    3Sum
    4Sum
)
foreach(_leetcode ${LEETCODE})
ADD_EXECUTABLE(${_leetcode} ${_leetcode}.cpp )
endforeach(_leetcode ${LEETCODE})
