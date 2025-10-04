def parenthesis(string):
    s=[]
    for i in string:
        if i in ['{','[','(']:
            s.append(i)
        else:
            if i==')':
                if not s or s[-1]!='(':
                    return False
                s.pop()
            elif i=='}':
                if not s or s[-1]!='{':
                    return False
                s.pop()
            elif i==']':
                if not s or s[-1]!='[':
                    return False
                s.pop()
            else:
                return False
    if s==[]:
        return True
    else:
        return False


p="{[([])]}"
b=parenthesis(p)
if b:
    print("Yes")
else:
    print("No")
