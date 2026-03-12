import numpy as np

def text_gen(text):
    
    text=text.replace(" ","").upper()

    while (len(text)%size!=0):
        text+='X'

    text_list=[]
    for i in text:
        text_list.append(ord(i)-ord('A'))

    return text_list


def get_key(size):
    key=[]
    print("Enter elements")
    for i in range(size):
        row=list(map(int, input(f"Enter {size} elements: ").split()))
        key.append(row)

    return np.array(key)
    

def encrypt(text, key):
    cipher=""
    text_val=text_gen(text)

    for i in range(0, len(text_val),size):
        pair=text_val[i:i+size]
        pair=np.array(pair).reshape(size,1)

        result=np.dot(key, pair)%26

        for j in range(size):
            cipher+=chr(result[j][0]+ord('A'))
    return cipher



pt=input("Enter pt: ")
size=int(input("Enter size: "))

key=get_key(size)
ct=encrypt(pt, key)
print(ct)