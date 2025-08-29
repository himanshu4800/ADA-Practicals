import pandas as pd
import matplotlib.pyplot as plt
data = pd.read_csv('quick_sort.csv')

plt.plot(data['n'], data['TimeTaken(seconds)'], marker='o', linestyle='-', color='blue')

plt.title('Quick Sort: Time vs Number of Elements')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time Taken (seconds)')
plt.grid(True)
plt.tight_layout()

plt.savefig('Quick_sort_plot.png')
plt.show()