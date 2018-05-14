import numpy as np
import matplotlib.pyplot as plt

Matrix=np.loadtxt("data.txt")
V=Matrix[0:511,:]
Ex=Matrix[512:1022,:-2]
Ey=Matrix[1025:1535,:-2]
x=np.linspace(0,500,510)
plt.imshow(V)
plt.streamplot(x,x,Ex,Ey)
plt.show()
plt.savefig("placas.pdf")
