N = int(input())

stack = []
max_area = 0
for n in range(N+1):
    h = 0
    if n == N:
        h = 0
    else:
        h = int(input())
    poped = None
    while stack and stack[-1][0] >= h:
        poped = stack.pop()
        area = poped[0] * (n-poped[1])
        if area > max_area:
            max_area = area
    if poped:
        poped[0] = h
        stack.append(poped)
    try:
        if stack[-1][0] < h :
            stack.append([h, n])
    except IndexError: # empty stack
        stack.append([h, n])
    # print(stack)

print(max_area)
