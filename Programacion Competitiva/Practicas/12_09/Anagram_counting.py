import fileinput

memo = [1]
for i in range(1,101):
    memo.append(memo[i-1] * i)

for line in fileinput.input():
    line = line[:-1]
    total = memo[len(line)]
    count = [0] * 128
    for c in line:
        count[ord(c)] += 1
    for i in count:
        if i > 0:
            total //= memo[i]

    print(total)
    
# End of Program