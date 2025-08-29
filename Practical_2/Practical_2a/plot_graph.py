import pandas as pd
import matplotlib.pyplot as plt
data = pd.read_csv('merge_sort.csv')

plt.plot(data['n'], data['TimeTaken(seconds)'], marker='o', linestyle='-', color='blue')

plt.title('Merge Sort: Time vs Number of Elements')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time Taken (seconds)')
plt.grid(True)
plt.tight_layout()

plt.savefig('Merge_sort_plot.png')
plt.show()