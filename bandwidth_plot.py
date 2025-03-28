import pandas as pd
import matplotlib.pyplot as plt

plot_fname = "bandwidth_plot.png"

# Load your memory bandwidth data CSV file
fname = "my_data_bandwidth.csv"
df = pd.read_csv(fname, comment="#")
print(df)

var_names = list(df.columns)
print("var names =", var_names)

# Extract columns: Problem Size, Direct, Vector, Indirect
problem_sizes = df[var_names[0]].values.tolist()
direct_bw = df[var_names[1]].values.tolist()
vector_bw = df[var_names[2]].values.tolist()
indirect_bw = df[var_names[3]].values.tolist()

plt.figure()

# Set up the plot title and axis labels
plt.title("Memory Bandwidth Comparison of 3 Methods")
xlocs = [i for i in range(len(problem_sizes))]
plt.xticks(xlocs, problem_sizes)
plt.xlabel("Problem Size")
plt.ylabel("Bandwidth Utilized (%)")

# Plot the data with different markers/colors
plt.plot(direct_bw, "r-o", label="Direct")
plt.plot(vector_bw, "b-x", label="Vector")
plt.plot(indirect_bw, "g-^", label="Indirect")

plt.legend(loc="best")
plt.grid(axis='both')

# Save and display the plot
plt.savefig(plot_fname, dpi=300)
plt.show()