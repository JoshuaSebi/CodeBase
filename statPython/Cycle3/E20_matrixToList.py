import numpy as np

rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))
print(f"Enter {rows * cols} elements separated by spaces:")

list1=list(map(int, input().split()))
list1=np.array(list1).reshape(rows,cols)


flat=list1.flatten().tolist()
print(flat)
