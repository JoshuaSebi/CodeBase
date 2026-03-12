def div(num):
    list1=[]
    for i in range (1,num+1):
        if(num%i==0):
            list1.append(i)
    return list1

val = int(input("Enter a number: "))
list1=div(val)
print(list1)

