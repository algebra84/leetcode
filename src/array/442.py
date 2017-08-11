nums = [1,1,1,2,2,3,4]
res = []
for i in range(len(nums)):
    j = i
    flag = 0
    print('loop')
    while nums[j] > 0:
        print(j,'->')
        tmp = nums[j]-1
        if j == i:
            if flag == 0:
                flag = 1
            else:
                nums[j] = -1
        else:
            nums[j] = -1
        j = tmp
        if j <= i:
            break
    print(j)
    if nums[j] == -1 and j != i:
        res.append(j+1)
        nums[j] = -2
        print('append',j+1)
print(res)
