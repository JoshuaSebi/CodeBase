import numpy as np

print(f"Enter elements")
arr1=np.array(list(map(int,input().split()))).reshape(2,2)
arr2=np.array(list(map(int,input().split()))).reshape(2,2)


cormat=np.corrcoef(arr1,arr2)
print("\nArray A:\n", arr1)
print("\nArray B:\n", arr2)
print(f"\nCorrel Matrix':\n", cormat)
print(f"\nCorrel Coeff':\n", cormat[0,1])

