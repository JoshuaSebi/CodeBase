import numpy as np
import matplotlib.pyplot as plt

y = np.array(list(map(int,input().split())))
x=np.arange(len(y))

plt.plot(x,y)
plt.title("NAME")
plt.grid()
plt.show()
