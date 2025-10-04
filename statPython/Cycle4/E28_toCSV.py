import numpy as np

data=list(map(float,input("Enter numbers of the array seperated by space:\n").split()))
arr=np.array(data).reshape(3,2)


np.savetxt("D:\code\college-codes\statPython\Cycle4\misc.csv",arr,fmt="%d",delimiter=",")
