import numpy as np
import inspect

arr=np.arange(27).reshape(3,3,3)
print(arr)
print("_____________________\n")

diag=arr.diagonal(axis1=-2,axis2=0)
print(diag)

