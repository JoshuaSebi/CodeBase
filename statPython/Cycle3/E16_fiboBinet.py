import numpy as np

n=10
phi=(1+np.sqrt(5))/2
psi=(1-np.sqrt(5))/2

fib=(phi**np.arange(n)-psi**np.arange(n))/np.sqrt(5)
print("fib: ",fib)
