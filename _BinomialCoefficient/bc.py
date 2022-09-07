from sys import argv

MAXN = 100

'''
base case are (n, 0) = 1
(n, n) = 1
'''

# Computes the number of distinct ways to choose k elements from n distinct elements
def choose(n, k):
    bc = [[1]*(MAXN + 1) for i in range(MAXN+1)]

    for i in range(2, n + 1):
        for j in range(1, i):
            bc[i][j] = bc[i - 1][j] + bc[i - 1][j - 1]
            
    return bc[n][k]
    
    
n = int(argv[1])
k = int(argv[2])
print(choose(n, k))
