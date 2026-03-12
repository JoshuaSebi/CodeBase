def encrypt(text,key):
    result=""
    j=0
    kl=len(key)
    for x in text:
        shift=((ord(x)-ord("A"))+(ord(key[j%kl])-ord("A")))%26
        result+=chr(shift + ord("A"))
        j+=1
    return result

def decrypt(text,key):
    result=""
    j=0
    kl=len(key)
    for x in text:
        shift=((ord(x)-ord("A"))-(ord(key[j%kl])-ord("A")))%26
        result+=chr(shift + ord("A"))  
        j+=1      
    return result

txt=input("Enter the text: ").upper()
key="KEY".upper()
restxt=encrypt(txt,key)
print(restxt)
print(decrypt(restxt,key))