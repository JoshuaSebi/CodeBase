import numpy as np
import matplotlib.pyplot as plt
import inspect as i

print(i.signature(np.savetxt))
print("Enter 9 elements")
#a=np.array(list(map(int, input().split()))).reshape(2,2)
b=np.array(list(map(int, input().split())))
b=np.arange(5)

np.savetxt("D:\\code\\college-codes\\statPython\\Cycle4\\acpu.csv", b,
           delimiter=",",
           fmt="%d")

