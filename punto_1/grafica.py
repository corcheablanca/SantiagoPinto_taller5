import numpy as np
import matplotlib.pyplot as plt

Matrix=np.loadtxt("data.txt")

V=Matrix[0:512,:]
Ex=Matrix[513:1025,:-2]
Ey=Matrix[1026:1537,:-2]

x=np.linspace(0,5,512)
plt.imshow(V)
plt.savefig("placas.pdf")

#no logre que me funcionara :(
plt.streamplot(x,x,Ex,Ey)
plt.show()


