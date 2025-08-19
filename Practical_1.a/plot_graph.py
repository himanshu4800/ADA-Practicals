import pandas as pd
import matplotlib.pyplot as plt

# Load data from CSV
data = pd.read_csv('linear_search_times.csv')

# Plot time vs n
plt.plot(data['n'], data['TimeTaken(seconds)'], marker='o', linestyle='-', color='blue')

plt.title('Linear Search: Time vs Number of Elements')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time Taken (seconds)')
plt.grid(True)
plt.tight_layout()

plt.savefig('linear_search_plot.png')  # Optional: save the plot as PNG
plt.show()
