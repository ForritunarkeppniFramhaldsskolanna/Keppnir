#!/usr/bin/python3

n = int(input())

ans = [
    """
1
1
Single 1
""",
    """
3
1
Single 2
1
Double 1
2
Single 1
Single 1
""",
    """
7
1
Single 3
1
Triple 1
2
Single 1
Single 2
2
Single 1
Double 1
2
Single 2
Single 1
2
Double 1
Single 1
3
Single 1
Single 1
Single 1
""",
    """
16
1
Single 4
1
Double 2
2
Single 1
Single 3
2
Single 1
Triple 1
2
Single 2
Single 2
2
Single 2
Double 1
2
Single 3
Single 1
2
Double 1
Single 2
2
Double 1
Double 1
2
Triple 1
Single 1
3
Single 1
Single 1
Single 2
3
Single 1
Single 1
Double 1
3
Single 1
Single 2
Single 1
3
Single 1
Double 1
Single 1
3
Single 2
Single 1
Single 1
3
Double 1
Single 1
Single 1
""",
    """
31
1
Single 5
2
Single 1
Single 4
2
Single 1
Double 2
2
Single 2
Single 3
2
Single 2
Triple 1
2
Single 3
Single 2
2
Single 3
Double 1
2
Single 4
Single 1
2
Double 1
Single 3
2
Double 1
Triple 1
2
Double 2
Single 1
2
Triple 1
Single 2
2
Triple 1
Double 1
3
Single 1
Single 1
Single 3
3
Single 1
Single 1
Triple 1
3
Single 1
Single 2
Single 2
3
Single 1
Single 2
Double 1
3
Single 1
Single 3
Single 1
3
Single 1
Double 1
Single 2
3
Single 1
Double 1
Double 1
3
Single 1
Triple 1
Single 1
3
Single 2
Single 1
Single 2
3
Single 2
Single 1
Double 1
3
Single 2
Single 2
Single 1
3
Single 2
Double 1
Single 1
3
Single 3
Single 1
Single 1
3
Double 1
Single 1
Single 2
3
Double 1
Single 1
Double 1
3
Double 1
Single 2
Single 1
3
Double 1
Double 1
Single 1
3
Triple 1
Single 1
Single 1
""",
]

print(ans[n - 1].strip())
