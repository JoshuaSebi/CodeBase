import numpy as np

n=10
psi=(1+np.sqrt(5))/2
phi=(1-np.sqrt(5))/2

fib=((psi**np.arange(n))-(phi**np.arange(n)))/np.sqrt(5)
print(fib.astype(int))
