import numpy as np
import inspect

mat=np.array([
    [1,2,3],
    [5,6,7],
    [8,9,0]])

inv=np.linalg.inv(mat)
print(inv)
