import sys
def find(nda,arr):
    seen = set()
    for num in arr:
        if num in seen:
            print(1)
            print(num)
            return
        seen.add(num)
    print(-1)
t = int(sys.stdin.readline().strip())
for _ in range(t):
    nda = int(sys.stdin.readlines().strip())
    arr = list(map(int,sys.stdin.readlines().split()))
    find(nda,arr)
            