def binary_string_to_int(binary):
    """Converts a binary string to its integer
    representation"""
    result = 0
    for i in range(len(binary)):
        result += pow(2, len(binary) - 1 - i) * int(binary[i])
    return result

def gray_to_binary(gray):
    """Returns the index of a gray code"""
    result = 0
    i = 0
    while (gray >> i) > 0:
        result ^= (gray >> i)
        i += 1
    return result

def gray_string_to_binary(s):
    """Converts a gray code string to an integer"""
    return gray_to_binary(binary_string_to_int(s))

nums = input().split(" ")
first = gray_string_to_binary(nums[1])
second = gray_string_to_binary(nums[2])
print(second - first - 1)