import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt("data.txt")
plt.plot(datos[:,0],datos[:,1])
plt.xlabel("q2")
plt.ylabel("p2")
plt.title("q2 Vs p2")
plt.savefig("caos.pdf")

