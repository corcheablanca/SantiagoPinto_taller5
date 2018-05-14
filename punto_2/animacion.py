import numpy as np
import matplotlib.pyplot as plt
import numpy as np
from numpy import genfromtxt, size, shape
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

#metodo para hacer un gif robado de http://www.jamesphoughton.com/2013/08/23/making-gif-animations-with-matplotlib.html

datos = np.loadtxt("data.txt")
frms,points = shape(datos)
x=(np.linspace(0.0,999,999))*0.01

def consigue_frames(i):
    datos_i = datos[i,:]
    plt.cla()
    plt.plot(x ,datos_i, c = "r")
    plt.ylim([-1.2,1.2])

imagen = plt.figure()
gif = FuncAnimation(imagen, consigue_frames, frames=int(frms), interval=10)
gif.save("cuerda.gif", writer = "imagemagick", fps = int(frms/4))

