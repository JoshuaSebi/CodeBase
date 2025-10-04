import numpy as np

print(f"Enter elements")
arr=np.array(list(map(int,input().split())))

diff=np.diff(arr,n=4)

print(diff)
