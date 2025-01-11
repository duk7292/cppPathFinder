list = [1,2,3,4,5,6,7,8,9]
test4 =[1234,1243,1324,1342,1423,1432]
test5 =[12345,12354,12435,12453,124]

done =[list]

def fact(s):
    
    r = 1
    for i in range(s):
        r *= i+1

    return r

def shiftAt(pos,li):
    r = li.copy()
    for i in range(len(li)-pos,len(li)-1):
        r[i+1] = li[i]
    r[len(li)-pos] = li[len(li)-1]
    return r



def numFromList(numList):
    s = ''.join(map(str, numList))
    return int(s)
def listFromNum(num):
    return [int(digit) for digit in str(num)]


checkpoints = []
counter = []

for i in range(len(list)-2):
    checkpoints.append(list)
    counter.append(0)

j = 0

i = 0
while i < (fact(len(list)-1)-1):
    
    if(counter[j] < j+1):
        checkpoints[j] = shiftAt(j+2,checkpoints[j])
        
        counter[j]+=1
        done.append(checkpoints[j])
        i+=1
    else:
        counter[j] = 0
        j+=1
        continue
    if(j != 0):
        while j !=0:
            j -=1
            checkpoints[j] = checkpoints[j+1]

def hasDuplicateLists(list_of_lists):
    seen = set()
    for sublist in list_of_lists:
        sublist_tuple = tuple(sublist)  # Convert to a tuple to make it hashable
        if sublist_tuple in seen:
            return True
        seen.add(sublist_tuple)
    return False


print(len(done))

print(hasDuplicateLists(done))

    

    
    
