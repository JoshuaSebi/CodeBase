def encrypt(text):
    result=""
    for x in text:
        if x.isalpha():
            shift=(ord(x)-ord("A")+3)%26
            result+=chr(shift + ord("A"))
        else:
            result+=x
    return result

def decrypt(text):
    result=""
    for x in text:
        if x.isalpha():
            shift=(ord(x)-ord("A")-3)%26
            result+=chr(shift + ord("A"))
        else:
            result+=x        
    return result

txt=input("Enter the text: ").upper()
a=int(input("Enter A: "))
b=int(input("Enter B: "))
restxt=encrypt(txt)
print(restxt)
print(decrypt(restxt))