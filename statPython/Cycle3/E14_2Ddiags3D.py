import numpy as np
import inspect

arr=np.arange(27).reshape(3,3,3)
print(arr)

diag=np.diagonal(arr,axis1=-1,axis2=-2)
print(diag)

