file1 = open('input.txt', 'r')
Lines = file1.readlines()

line = Lines [0]

for i in range(len(line)-1):
    repeat = False;
    marker = line[i:i+4]
    
    for k in range(len(marker)-1):
        if repeat:
            break
        for j in range(len(marker)-1):
            j += 1
            if j == k:
                j += 1 
            if marker[k] == marker[j]:
                repeat = True
                break
    
    if repeat == False:
        print(i+4)
        break


for i in range(len(line)-1):
    repeat = False;
    marker = line[i:i+14]
    
    for k in range(len(marker)-1):
        if repeat:
            break
        for j in range(len(marker)-1):
            j += 1
            if j == k:
                j += 1 
            if marker[k] == marker[j]:
                repeat = True
                break
    
    if repeat == False:
        print(i+14)
        break