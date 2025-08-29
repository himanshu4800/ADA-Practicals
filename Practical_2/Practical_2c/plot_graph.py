import pandas as pd
import matplotlib.pyplot as plt
data = pd.read_csv('Insertion_sort.csv')

plt.plot(data['n'], data['TimeTaken(seconds)'], marker='o', linestyle='-', color='blue')

plt.title('Insertion Sort: Time vs Number of Elements')
plt.xlabel('Number of Elements (n)')
plt.ylabel('Time Taken (seconds)')
plt.grid(True)
plt.tight_layout()

plt.savefig('Insertion_sort_plot.png')
plt.show()