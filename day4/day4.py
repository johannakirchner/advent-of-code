file1 = open('input.txt', 'r')
Lines = file1.readlines()

pairs = 0
for line in Lines:
    a,b = line.split(',', 1)

    atraco = a.index('-')
    btraco = b.index('-')

    if int(a[0:atraco]) <= int(b[0:btraco]) and int(a[atraco+1:]) >= int(b[btraco+1:]):
        pairs += 1
    elif int(a[0:atraco]) >= int(b[0:btraco]) and int(a[atraco+1:]) <= int(b[btraco+1:]):
        pairs += 1

print(pairs)

pairs = 0
for line in Lines:
    a,b = line.split(',', 1)

    atraco = a.index('-')
    btraco = b.index('-')

    if int(a[0:atraco]) >= int(b[0:btraco]) and int(a[0:atraco]) <= int(b[btraco+1:]):
        pairs += 1
    elif int(b[0:btraco]) >= int(a[0:atraco]) and int(b[0:btraco]) <= int(b[btraco+1:]):
        pairs += 1

print(pairs)