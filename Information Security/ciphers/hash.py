import hashlib

s1=input("Enter M1: ")
h1=hashlib.sha256(s1.encode()).hexdigest()
print(h1)

s2=input("Enter M2: ")
h2=hashlib.sha256(s2.encode()).hexdigest()
print(h2)

h1=int(h1,16)
h2=int(h2,16)

xores=h1^h2
diff=bin(xores).count("1")
print(diff)