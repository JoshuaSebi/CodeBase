def encrypt(txt,key):
    kl=len(key)
    restxt=""
    k=0
    for x in txt:
        shift=((ord(x)-ord('A'))+(ord(key[k])-ord("A")))%26
        restxt+=chr(shift+ord("A"))
        k=(k+1)%kl
    return restxt

def decrypt(restxt,key):
    kl=len(key)
    txt=""
    k=0
    for x in restxt:
        shift=((ord(x)-ord('A'))-(ord(key[k])-ord("A")))%26
        txt+=chr(shift+ord("A"))
        k=(k+1)%kl
    return txt

txt=input("Enter the text: ").upper()
key="KEY".upper()
restxt=encrypt(txt,key)
print(restxt)
print(decrypt(restxt,key))