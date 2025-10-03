def divisor(num):
    arr=[]
    for i in range (2,(num//2)+1):
        if num%i==0:
            arr.append(i)
        else:
            pass
    return arr

val = int(input("Enter a number: "))
list1=divisor(val)
for i in list1:
    print(i,end=' ')
