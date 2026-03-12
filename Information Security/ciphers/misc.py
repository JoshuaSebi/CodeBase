import numpy as np

def key_gen(size):

    mat=[]
    for i in range(size):
        row=list(map(int, input(f"Enter {size} elts: ").split()))
        mat.append(row)

    return np.array(mat)

def text_gen(text,size):
    text = text.replace(" ","").upper()

    while (len(text)%size!=0):
        text+='X'
    text_val=[]
    for i in text:
        text_val.append(ord(i)-ord("A"))

    return text_val


def encrypt(text,size):
    ct=""
    key=key_gen(size)
    text_val=text_gen(text,size)

    for i in range(0,len(text_val),size):
        pair=text_val[i:i+size]
        pair=np.array(pair).reshape(size,1)

        resmat=np.dot(key,pair)%26

        for j in range(0, size):
            ct+=chr(resmat[j][0]+ord('A'))

    return ct


text=input("Enter : ").upper()
size=int(input("Size: "))
print(encrypt(text,size))