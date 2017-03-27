set(LEETCODE
    hello
    twoSum
    3Sum
    4Sum
    4Sum2
    3sumClosest
    sellStock
    sellStock2
    sellStock3
    sellStock4
)
foreach(_leetcode ${LEETCODE})
ADD_EXECUTABLE(${_leetcode} ${_leetcode}.cpp )
endforeach(_leetcode ${LEETCODE})
