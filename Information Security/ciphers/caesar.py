def enc_caesar(pt):
    ct=""
    for x in pt:
        if x.isalpha():
            val=(ord(x)-ord("A")+3)%26
            ct+=chr(val+ord('A'))
        else:
            ct+=x
    return ct
    
def dec_caesar(ct):
    pt=""
    for x in ct:
        if x.isalpha():
            val=(ord(x)-ord("A")-3)%26
            pt+=chr(val+ord("A"))
        else:
            pt+=x
    return pt


pt=input("Enter PlainText: ").upper()
ct=enc_caesar(pt)
print("CipherText: ",ct)
print("PlainText: ",dec_caesar(ct))


# def encrypt(text):
#     result=""
#     for x in text:
#         if x.isalpha():
#             shift=(ord(x)-ord("A")+3)%26
#             result+=chr(shift + ord("A"))
#         else:
#             result+=x
#     return result

# def decrypt(text):
#     result=""
#     for x in text:
#         if x.isalpha():
#             shift=(ord(x)-ord("A")-3)%26
#             result+=chr(shift + ord("A"))
#         else:
#             result+=x        
#     return result

# txt=input("Enter the text: ").upper()
# restxt=encrypt(txt)
# print(restxt)
# print(decrypt(restxt))