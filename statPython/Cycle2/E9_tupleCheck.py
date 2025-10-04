def tupCheck(word,tup):
    w=word.lower()
    if w in tup:
        return True
    return False

tuple1=("a","g","f","b")
inp=input("ENter a letter to check: ")
if (tupCheck(inp,tuple1)):
    print("Found")
else:
    print("Not Found")
