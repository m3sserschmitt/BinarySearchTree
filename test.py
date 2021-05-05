import sys
import subprocess
import numpy as np
import matplotlib.pyplot as plt
import math

def plot(points, file):
    axis_font = {"color": "black", "weight": "normal", "size": 16}
    title_font = {"family": "serif", "color": "black", "weight": "normal", "size": 16}

    rng1 = []
    z = []

    for point in points:
        try:
            rng1.append(float(point[0]))
            z.append(float(point[1]))
        except Exception:
            continue

    # M /= len(points)

    # rng = np.linspace(start=float(points[0][0]), stop=float(points[-1][0]), num=len(points))
    # y = []

    # for value in rng:
    #     # if value:
    #     y.append(math.log2(value))

    plt.style.use('seaborn-ticks')
    plt.grid(color='grey', linestyle='-', linewidth=0.5)
    plt.xlabel("$n$", fontdict=axis_font)
    plt.ylabel("$O$", fontdict=title_font)
    # plt.plot(rng, y, linestyle="--", linewidth=1.0, color="red")
    plt.plot(rng1, z)
    plt.axis("tight")

    plt.savefig(file)
    plt.show()


with open(sys.argv[1], 'r') as c_file:
    parameters = c_file.readline()

    process_cmd = ['./build/Proiect_SD'] + [c.strip('\n') for c in parameters.split(' ')]
    raw_result = subprocess.check_output(process_cmd)
    # print(raw_result)
    result = [pair.split(' ') for pair in raw_result.decode('utf-8').split('\n') if len(pair)]
    # print(result)
    # print(result)
    plot(result, sys.argv[1] + "_out.eps")

