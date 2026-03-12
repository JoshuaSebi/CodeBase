def checkOdd(num):
    if (num%2==0):
        return("Even")
    else:
        return("Odd")

n=int(input("Enter a Number: "))
print(f"{n} is", checkOdd(n))
