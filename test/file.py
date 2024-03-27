import matplotlib.pyplot as plt
from queue import Queue

server_full = False
queue = Queue()
time = [0] * 15
time_step = 1.4

for i in range(15):
    queue.put(i)

while not queue.empty():
    if not server_full:
        front = queue.get()
        print("Proceseaza requestul", front, end='')
        time[front] = front * time_step
        print(", Timp de procesare:", time[front], "secunde")

average_time = sum(time) / 15
print("Timpul mediu de asteptare este:", average_time, "secunde")

plt.plot(range(15), time, marker='o', linestyle='-')
plt.grid(True)
plt.show()