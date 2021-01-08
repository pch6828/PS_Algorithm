def solution(participant, completion):
    answer = ''
    s = dict()
    for str in completion:
        if str in s:
            s[str]+=1
        else:
            s[str]=1
    for str in participant:
        if str in s:
            s[str]-=1
            if s[str]==0:
                del s[str]
        else:
            return str