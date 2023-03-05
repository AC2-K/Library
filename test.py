import random
def Miller_Rabin_test(num):
    if num == 2:
        return True
    if num > 2 and num & 1 == 0:
        return False

    s, t = 0, num-1
    while t & 1 == 0:
        s, t = s+1, t >> 1
    a = random.randint(1, num-1)
    if pow(a, t, num) == 1:
        return True
    for i in range(0, s):
        if pow(a, pow(2, i) * t, num) == num-1:
            return True
    return False



n=int(input())

for _ in range(n):
    p = int(input())

    if Miller_Rabin_test(p):
        print("{} 1\n".format(p))
    else:
        print("{} 0\n".format(p))