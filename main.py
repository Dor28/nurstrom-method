import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

table = pd.read_csv("/home/dor/practicum/practikum/out.csv")

x = table["x"].values
y = table["y"].values
y_pred = table["y_pred"].values

plt.title("Графики целевой и вычисленной функций")

plt.plot(x, y, label="predicted")
plt.plot(x, y_pred, label="target")
plt.legend()

plt.xlabel("$x$")
plt.ylabel("$f(x)$")

plt.show()
 
