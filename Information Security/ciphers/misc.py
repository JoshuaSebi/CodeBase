import numpy as np

def keygen(size):
    key=[]
    for i in range (size):
        val=list(map(int, input(f"Enter {size} elements: ").split()))
        key.append(val)
    return np.array(key)
    
def textgen(text,size):
    tm=[]
    while(len(text)%size!=0):
        text+="X"

    for x in text:
        val=(ord(x)-ord('A'))%26
        tm.append(val)

    return tm

def encrypt(text,key,size):
    rest=""
    pt=textgen(text,size)
    for i in range(0,len(pt),size):
        block=pt[i:i+size]
        blck=np.array(block).reshape(size,1)

        resmat=np.dot(key,blck)%26
        for j in range(size):
            val=(resmat[j][0]+ord('A'))
            rest+=chr(val)
    return rest 

pt=input("Enter Text: ").upper()
key=keygen(3)
ct=encrypt(pt,key,3)
print("Encrypted: ",ct)