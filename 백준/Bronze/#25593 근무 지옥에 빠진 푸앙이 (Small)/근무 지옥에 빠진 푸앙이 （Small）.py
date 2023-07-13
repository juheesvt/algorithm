import sys
input = sys.stdin.readline


if __name__ == "__main__":

    weekend = int(input())
    work_time_dict = dict()

    for i in range(weekend):
        for j in range(4):
            names = input().split()
            for name in names:
                if name == "-":
                    continue

                if j == 0 or j == 2:
                    work_time = 4
                elif j == 1:
                    work_time = 6
                else:
                    work_time = 10

                if name in work_time_dict.keys():
                    work_time_dict[name] += work_time
                else:
                    work_time_dict[name] = work_time

    if work_time_dict.keys() and max(work_time_dict.values()) - min(work_time_dict.values()) > 12:
        print("No")
    else:
        print("Yes")
