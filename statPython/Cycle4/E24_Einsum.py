import numpy as np

print(f"Enter elements")
arr1=np.array(list(map(int,input().split())))
arr2=np.array(list(map(int,input().split())))

arr1 = arr1.reshape(2,2)
arr2 = arr2.reshape(2,2)
expr = input("Enter Einstein summation expression (e.g. 'ij,jk->ik'): ")
# Compute Einstein summation
result = np.einsum(expr, arr1, arr2)
print("\nArray A:\n", arr1)
print("\nArray B:\n", arr2)
print(f"\nEinstein Summation Result for '{expr}':\n", result)
