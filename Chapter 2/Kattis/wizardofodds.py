s = input()
nums = s.split(" ")
n, k = int(nums[0]), int(nums[1])
if k > 350 or 2**k  >= n :
    print("Your wish is granted!\n")
else :
    print("You will become a flying monkey!\n")