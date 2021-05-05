import sys
import subprocess
import numpy as np
import matplotlib.pyplot as plt

def plot(points):
    axis_font = {"color": "black", "weight": "normal", "size": 16}
    title_font = {"family": "serif", "color": "black", "weight": "normal", "size": 16}

    # rng = np.linspace(start=points[0][0], stop=points[-1][0], num=100)
    # y = []

    # for value in rng:
    #     y.append(p(value))

    rng1 = []
    z = []
    for point in points:
        rng1.append(point[0])
        z.append(point[1])

    plt.style.use('seaborn-ticks')
    # plt.grid(color='grey', linestyle='-', linewidth=0.5)
    plt.xlabel("$x$", fontdict=axis_font)
    plt.ylabel("$y$", fontdict=title_font)
    # plt.plot(rng, y, linestyle="--", linewidth=1.0, color="red")
    plt.plot(rng1, z)
    plt.axis("tight")
    # plt.title("Cubic Regression", fontdict=title_font)
    # plt.savefig("test.eps")
    plt.show()


with open(sys.argv[1], 'r') as c_file:
    parameters = c_file.readline()

    process_cmd = ['./build/Proiect_SD'] + [c.strip('\n') for c in parameters.split(' ')]
    subprocess.run(process_cmd)

    with open(sys.argv[1] + "_out", 'r') as outfile:
        lines = outfile.readlines()
        points = [pair.strip('\n').split() for pair in lines]

        plot(points)


