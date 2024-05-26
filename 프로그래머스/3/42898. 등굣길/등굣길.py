def solution(m, n, puddles):
    MODULAR = 1000000007
    cache = [[0 for i in range(m)] for j in range(n)]
    
    for i, j in puddles:
        cache[j - 1][i - 1] = -1
    
    for i in range(n):
        if cache[i][0] == -1:
            for j in range(i, n):
                cache[j][0] = -1
            break
        else:
            cache[i][0] = 1
            
    for i in range(m):
        if cache[0][i] == -1:
            for j in range(i, m):
                cache[0][j] = -1
            break
        else:
            cache[0][i] = 1
            

    for i in range(1, n):
        for j in range(1, m):
            
            if cache[i][j] == -1:
                continue
                
            if cache[i - 1][j] == -1 and cache[i][j - 1] == -1:
                cache[i][j] = -1
            elif cache[i - 1][j] == -1:
                cache[i][j] = cache[i][j - 1]
            elif cache[i][j - 1] == -1:
                cache[i][j] = cache[i - 1][j]
            else:
                cache[i][j] = (cache[i - 1][j] + cache[i][j - 1]) % MODULAR

    return cache[n - 1][m - 1] if cache[n - 1][m - 1] > 0 else 0