def solution(routes):
    routes.sort(key=lambda x:x[1])
    print(routes)
    
    
    START = 0
    END = 1
    points = []
    points.append(routes[0][END])
    
    for i in range(1, len(routes)):
        if points[-1] >= routes[i][START]:
            continue
        else:
            points.append(routes[i][END])
    
    print(points)
    return len(points)