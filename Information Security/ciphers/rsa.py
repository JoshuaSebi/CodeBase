from sympy import gcd, mod_inverse

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

def encrypt(m, pubkey):
    e,n=pubkey
    c=pow(m,e,n)
    return c

def decrypt(m, pvtkey):
    d,n=pvtkey
    c=pow(m,d,n)
    return c

pub,pvt=genkeys()
m=3

c=encrypt(m,pub)
print(c, decrypt(c, pvt))