import matplotlib.pyplot as plt
import numpy as np

x= np.linspace(-10,10,5)
y=np.sin(x)

plt.plot(x,y)
plt.title("y = f(x)")
plt.grid()
plt.show()
