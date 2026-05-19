import numpy as np
def findx(keymat,x):
    for i in range(5):
        for j in range(5):
            if (x==keymat[i][j]):
                return i,j

def keygen(key):
    k=[]
    key=key.replace("J","I")
    for x in key:
        if x not in k:
            k.append(x)

    for y in "ABCDEFGHIKLMNOPQRSTUVWXYZ":
        if y not in k:
            k.append(y)

    return np.array(k).reshape(5,5)

def textprep(text):
    newt=""
    i=0
    while (i<len(text)):
        a=text[i]
        if (i+1<len(text)):
            b=text[i+1]
        else:
            b="X"

        if (a==b):
            newt+=a+'X'
            i=i+1
        else:
            newt+=a+b
            i=i+2
        
    while(len(newt)%2!=0):
        newt+='X'
    return newt
            
def encrypt(text,key):
    keymat=keygen(key)
    text=textprep(text)
    ct=""

    for i in range(0,len(text),2):
        r1,c1=findx(keymat,text[i])
        r2,c2=findx(keymat,text[i+1])

        if (r1==r2):
             ct+=(keymat[r1][(c1+1)%5])
             ct+=(keymat[r2][(c2+1)%5])
        elif (c1==c2):
            ct+=(keymat[(r1+1)%5][c1])
            ct+=(keymat[(r2+1)%5][c2])
        else:
            ct+=(keymat[r1][c2]+keymat[r2][c1])
    return ct



key=input("Enter Key: ").upper()
text=input("Enter text: ").upper()
print(encrypt(text,key))