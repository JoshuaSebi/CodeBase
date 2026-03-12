def encrypt(text,a,b):
    result=""
    for x in text:
       shift=(a*(ord(x)-ord("A"))+b)%26
       result+=chr(shift + ord("A"))
    return result

def decrypt(text,a,b):
    result=""
    a_inv=pow(a,-1,26)

    for i in range(26):
        if(a*i)%26==1:
            a_inv=i
            break

    for x in text:
        shift=a_inv*((ord(x)-ord("A"))-b)%26
        result+=chr(shift + ord("A"))
    return result

txt=input("Enter the text: ").upper()
# a=int(input("Enter A: "))
# b=int(input("Enter B: "))
restxt=encrypt(txt,5,8)
print(restxt)
print(decrypt(restxt,5,8))