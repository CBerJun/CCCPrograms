# I made a silly mistake in j5.cpp when debugging it...
# I wrote this to proof that the algorithm works...
# Both j5.py and j5.cpp work now.

q = int(input())
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort()
if q == 1:
    b.sort()
else:
    b.sort(reverse=True)

print(sum(max(x, y) for x, y in zip(a, b)))
