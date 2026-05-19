from sympy import gcd, mod_inverse

def simpleHash(text):
    h=0
    for x in text:
        h=h*31+ord(x)
    return h

def genkeys():
    p=5
    q=3
    n=p*q
    phi=(p-1)*(q-1)

    evals=[e for e in range(2,phi) if gcd(e,phi)==1]
    e=int(input())
    d=mod_inverse(e,phi)

    print(f"Pub: {e},{n}")
    print(f"Pvt: {d},{n}")
    return (e,n),(d,n)

def func1(text):
    has=simpleHash(text)
    pub,pvt=genkeys()
    d,n=pvt
    sign=pow(has,d,n)
    print(sign)
    e,n=pub
    verif=pow(sign,e,n)

    if(verif==has%n):
        print("Yay")
    else:
        print("Nay")

mess=input("Enter: ")
func1(mess)