import numpy as np

rows=int(input("Enter Rows: "))
cols=int(input("Enter cols: "))

print(f"Enter {rows*cols} elements")
arr=np.array(list(map(int,input().split()))).reshape(rows,cols)

Q,R=np.linalg.qr(arr)

print("Matrix Q(orthogonal):")
print(Q)
print("\nMatrix R(upper triangular):")
print(R)
print("Q@R==A: ",np.allclose(arr,Q@R))
