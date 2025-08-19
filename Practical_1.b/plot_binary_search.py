import pandas as pd
import matplotlib.pyplot as plt

# Load data
data = pd.read_csv('binary_search_times.csv')

# Plot
plt.figure(figsize=(8, 5))
plt.plot(data['n'], data['TimeTakenSeconds'], marker='o', linestyle='-', color='blue')
plt.title('Binary Search Time vs Number of Elements (n)')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time Taken (seconds)')
plt.grid(True)
plt.savefig('binary_search_plot.png')  # Saves image
plt.show()
