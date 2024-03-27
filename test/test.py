import queue
import random
import threading
import time
import matplotlib.pyplot as plt

class ServerSimulation:
    def __init__(self):
        self.server_busy = False
        self.process_time = 1.4
        self.queue = queue.Queue()
        self.total_time = 0
        self.num_processed = 0
        self.num_added = 0
        self.processing_times = []

    def add_to_queue(self):
        while self.num_added < 15:  # Limiting to add only 15 items
            entry_time = random.uniform(0.1, 5.0)  # Random entry time between 0.1 and 5.0 seconds
            self.queue.put(entry_time)
            print(f"Added an entry to the queue at time {entry_time:.2f} seconds.")
            time.sleep(entry_time)
            self.num_added += 1

    def process_queue(self):
        while self.num_processed < 15:  # Process only 15 items
            if not self.queue.empty() and not self.server_busy:
                entry_time = self.queue.get()
                self.server_busy = True
                print(f"Processing entry from the queue at time {entry_time:.2f} seconds.")
                start_time = time.time()  # Start time for processing
                time.sleep(self.process_time)
                end_time = time.time()  # End time for processing
                processing_time = end_time - start_time
                self.processing_times.append(processing_time)
                self.total_time += processing_time
                self.num_processed += 1
                average_time = self.total_time / self.num_processed
                print(f"Total time for this entry: {self.total_time:.2f} seconds")
                print(f"Average processing time so far: {average_time:.2f} seconds")
                self.server_busy = False

    def plot_processing_times(self):
        plt.plot(range(1, len(self.processing_times) + 1), self.processing_times, marker='o')
        plt.xlabel('Entry')
        plt.ylabel('Processing Time (seconds)')
        plt.title('Processing Time for Each Entry')
        plt.grid(True)
        plt.show()

if __name__ == "__main__":
    server_sim = ServerSimulation()
    add_thread = threading.Thread(target=server_sim.add_to_queue)
    process_thread = threading.Thread(target=server_sim.process_queue)

    add_thread.start()
    process_thread.start()

    add_thread.join()
    process_thread.join()

    server_sim.plot_processing_times()
