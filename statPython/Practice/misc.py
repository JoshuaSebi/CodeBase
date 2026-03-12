fname=input("Enter Filename: ")
csent=cchar=cspl=cdig=0

with open(fname,"r") as f:
    txt=f.read()
    for i in txt:
        if i in '.?!':
            csent+=1
        if i !=' ':
            cchar+=1
            if i.isdigit():
                cdig+=1
            elif i.isalnum()==False:
                cspl+=1
            
            
print("Sentences:", csent)
print("Characters (excluding spaces):", cchar)
print("Digits:", cdig)
print("Special characters:", cspl)
