import sys


while True :
    line = sys.stdin.readline()
    if not line :
        break;
    N, r, c = map(int, line.split())
    result = 0
    while N:
        pos = 0
        if r / 2**(N-1):
            pos += 2
            r %= 2**(N-1)
        if c / 2**(N-1):
            pos += 1
            c %= 2**(N-1)

        result += pos * 2**(2*N-2)
        N -= 1

    print result
