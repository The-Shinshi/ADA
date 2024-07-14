from collections import deque
import copy
file = open(input('Enter the file name:'))
line = file.readlines()
# A lambda function can take any number of arguments, but can only have one expression.
line = list(map(lambda s: s.strip(), line))
R = []
for i in range(len(line)):
    k = i+1
    if line[i] == '1) Rules':
        while line[k] != '2) Facts':
            r = deque(line[k].split())
            ths = r.copy()
            r.append(ths)
            R.append(list(r))
            k = k + 1
    elif line[i] == '2) Facts':
        Fact = line[k].split()
    elif line[i] == '3) Goal':
        Goal = line[k]

print('PART1. Data')
print('1) Rules')
for i in range(len(R)):
    print('R', i+1, ':', end='')
    for j in range(len(R[i])-1):
        print(R[i][j], end=' ')
    print('->', R[i][-1])

print()
print('2) Facts')
print('', end='')
for i in Fact:
    print(i, '', end='')
print()
print()

print('3) Goal')
print('', Goal)
Path = []
Flag = []
origin_fact = copy.deepcopy(Fact)
print('PART2. Trace')
# Set initial value
count = 0
Yes = False
while Goal not in Fact and Yes == False:
    # fact When the final element is added to or when it doesen't work evenafter finishing it.

    count += 1
    print('', end='')
    print('ITERATION', count)
    K = 1
    apply = False
    while K <= len(R) and not apply:  # until it finds one applicable rule.
        K = K+1
        print('R', K-1, ':', end='')
        for j, v in enumerate(R[K]):
            # Print Kth rule (R[K])
            if j < len(R[K]) - 1:
                print(v, '', end='')
            else:
                print('->', v, end='')
        if str(K+1) in Flag:  # if there is a flag
            b = Flag.index(str(K+1)) + 1
            if Flag[b] == 1:
                print(' skip, because flag1 raised')
            elif Flag[b] == 2:
                print(' skip, because flag2 raised')
        else:  # no flag
            # Are all the left sides of the kth rule present?
            for j, v in enumerate(R[K]):
                if j == len(R[K]) - 1:
                    continue
                if v in Fact:
                    if R[K][-1] in Fact:  # If the right-hand side already exists
                        print(' not applied, because RHS in facts. Raise flag2')
                        Flag.append(str(K + 1))
                        Flag.append(2)
                        break
                    elif j == R[K][-2]:
                        apply = True
                        P = K+1
                        break
                else:
                    print(' not applied, because of lacking ', v)
                    break
    if apply:
        Fact.append(R[P-1][-1])
        Flag.append(str(P))
        Flag.append(1)
        Path.append(P)
        print(' apply, Raise flag1. Facts ', end='')
        for i in Fact:
            print(i, '', end='')
        print()
    elif K == len(R)-1:
        Yes = True

print()
print('PART3. Results')
if Goal in origin_fact:
    print('', end='')
    print('Goal A in facts. Empty path.')
else:
    if Goal in Fact:
        print('', end='')
        print('1) Goal', Goal, 'achieved')
        print('', end='')
        print('2) Path:', end='')
        for i in Path:
            print('R', i, '', end='')
    else:
        print('1) Goal', Goal, 'not achieved')
