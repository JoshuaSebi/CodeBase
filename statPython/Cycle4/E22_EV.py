import numpy as np

rows=int(input("Enter Rows: "))
cols=int(input("Enter cols: "))

print(f"Enter {rows*cols} elements")
arr=np.array(list(map(int,input().split()))).reshape(rows,cols)

eigenval, eigenvect=np.linalg.eig(arr)

print("EigVal\n",eigenval)
print("EigenVect\n",eigenvect)
