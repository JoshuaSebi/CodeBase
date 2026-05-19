def inverse(x):
    for i in range(26):
        if (x*i)%26==1:
            return i

def enc_affine(pt,a,b):
    ct=""
    for x in pt:
        shift=(a*(ord(x)-ord('A'))+b)%26
        ct+=chr(shift+ord("A"))
    return ct

    
def dec_affine(ct,a,b):
    pt=""
    a_inv=inverse(a)
    for x in ct:
        shift=(a_inv*((ord(x)-ord('A'))-b))%26
        pt+=chr(shift+ord('A'))
    return pt


pt=input("Enter PlainText: ").upper()
a=int(input("Enter a: "))
b=int(input("Enter b: "))
ct=enc_affine(pt,a,b)
print("CipherText: ",ct)
print("PlainText: ",dec_affine(ct,a,b))