import numpy as np

a=np.array(list(map(int,input().split())))
b=np.array([7,8,9,19,30])

krone=np.kron(a,b)
print(krone)
