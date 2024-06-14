def solution(bandage, health, attacks):
    answer = health
    casting_time, sec_recovery, add_recovery = bandage
    
    attack_idx = 0
    recovery_time = 0
    for time in range(attacks[-1][0] + 1):
        if answer <= 0:
            return -1
        
        if time == attacks[attack_idx][0]:
            answer -= attacks[attack_idx][1]
            attack_idx += 1
            recovery_time = 0
            continue   
        
        recovery_time += 1
        answer += sec_recovery if answer < health else health - answer
        
        if recovery_time == casting_time:
            recovery_time = 0
            answer += add_recovery if answer + add_recovery < health else health - answer

    return -1 if answer <= 0 else answer 