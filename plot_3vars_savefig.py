"""
E. Wes Bethel, Copyright (C) 2022

October 2022

Description: This code loads a .csv file and creates a 3-variable plot, and saves it to a file named "myplot.png"

Inputs: the named file "my_data_mflops.csv"

Outputs: displays a chart with matplotlib

Dependencies: matplotlib, pandas modules

Assumptions: developed and tested using Python version 3.8.8 on macOS 11.6
"""

import pandas as pd
import matplotlib.pyplot as plt

plot_fname = "myplot.png"

# Read your MFLOP/s data from the new CSV file
fname = "my_data_mflops.csv"
df = pd.read_csv(fname, comment="#")
print(df)

var_names = list(df.columns)
print("var names =", var_names)

# Split the dataframe into individual variables
problem_sizes = df[var_names[0]].values.tolist()
direct = df[var_names[1]].values.tolist()
vector = df[var_names[2]].values.tolist()
indirect = df[var_names[3]].values.tolist()

plt.figure()

# Update the title and labels to reflect MFLOP/s data
plt.title("MFLOP/s Comparison of 3 Methods")
xlocs = [i for i in range(len(problem_sizes))]
plt.xticks(xlocs, problem_sizes)
plt.xlabel("Problem Size")
plt.ylabel("MFLOP/s")

# Plot each method with different markers and colors
plt.plot(direct, "r-o", label="Direct")
plt.plot(vector, "b-x", label="Vector")
plt.plot(indirect, "g-^", label="Indirect")

plt.legend(loc="best")
plt.grid(axis='both')

# Save the plot and display it
plt.savefig(plot_fname, dpi=300)
plt.show()
