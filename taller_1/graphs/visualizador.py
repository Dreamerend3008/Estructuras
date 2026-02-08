import matplotlib.pyplot as plt

files = ['sort_inverse_table.txt','sort_random_table.txt','sort_sorted_table.txt']

data = []
for i in range(3):
    with open(files[i], 'r') as file:
        file_data = []
        for line in file:
            row = [int(x) for x in line.strip().split()]
            file_data.append(row)
        data.append(file_data)


# 3 diferent graphs
tables = ['Inverted', 'Random', 'Sorted']

algorithms = ['Bubble_sort', 'Quick_Sort', 'Heap_Sort']

for d,tb in zip(data,tables):
    x = [int(row[0]) for row in d]
    bubble_time = [int(row[4]) for row in d]
    quick_time = [int(row[5]) for row in d]
    heap_time = [int(row[6]) for row in d]
    plt.plot(x, bubble_time, 'b', label=algorithms[0], linewidth=2, alpha=0.8)
    plt.plot(x, quick_time, 'g--', label=algorithms[1], linewidth=2, alpha=0.8)
    plt.plot(x, heap_time, 'r', label=algorithms[2], linewidth=1, alpha=0.9)
    plt.xlabel('Size')
    plt.ylabel('Time')
    plt.title(tb)
    plt.legend()
    route = tb+'.png'
    plt.savefig(route, dpi=300, bbox_inches='tight')
    plt.close()
