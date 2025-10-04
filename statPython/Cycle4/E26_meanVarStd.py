import numpy as np
data=list(map(float,input("Enter numbers of the array seperated by space:\n").split()))
arr=np.array(data)


mean=np.mean(arr)
var=np.var(arr)
std_dev=np.std(arr)

print(f" \n Input Data: {arr}")
print(f"\nAverage : {mean}")
print(f"\nVariance : {var}")
print(f"\nStandard Deviation: {std_dev}")
