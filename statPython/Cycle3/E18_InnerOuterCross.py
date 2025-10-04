import numpy as np

a=np.array(
    [4,5,6])

b=np.array([7,8,9])

print("inner: \n",np.inner(a,b),"\n")
print("outer: \n",np.outer(a,b),"\n")
print("cross: \n",np.cross(a,b),"\n")
