num=int(input())

zehn=num//10
eins=num%10
andre=zehn+eins
neu=eins*10+andre%10
i=1


while num != neu:
    zehn=neu//10
    eins=neu%10
    andre = zehn + eins
    neu = eins * 10 + andre%10
    i+=1

print(i)