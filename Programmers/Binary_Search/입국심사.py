def solution(n, times):
    ans = 2000000000000000000
    
    l = 1
    r = 1000000000000000000

    while l<=r:
        mid = (l+r)//2
        cnt = 0

        for i in times:
            cnt = cnt+mid//i

        if cnt>=n:
            ans = min(ans, mid)
            r = mid-1
        else:
            l = mid+1
    
    return ans