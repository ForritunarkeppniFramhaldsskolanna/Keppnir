from __future__ import print_function
import sys
n = int(sys.stdin.readline().strip())
print(sum( int(sys.stdin.readline().strip()) for i in range(n) ))
