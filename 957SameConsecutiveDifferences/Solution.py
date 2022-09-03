from sys import argv

def numsSameConsecDiff(n, k):
    
    result = [] 

    # num: Number that is currently being built up
    # n: Number of digits left to reach the global n 
    def dfs(num, n): 
        if n == 0:
            result.append(num)
            
            return
        
        d = num % 10 

        if d + k < 10:
            dfs(num*10 + d+k, n - 1)

        if k != 0 and d - k >= 0:
            dfs(num*10 + d-k, n - 1)

    for num in range(1, 10):
        dfs(num, n - 1) # The first digit is num, there are n - 1 digits left

    return result

print(numsSameConsecDiff(int(argv[1]), int(argv[2])))