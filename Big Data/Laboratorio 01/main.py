import os
import re
import time
import threading
from collections import defaultdict

NUM_PROCESSORS = os.cpu_count()
PERCENTAGES = [0.25, 0.5, 0.75, 1.0]

file_paths = []
with open('file_paths.txt', 'r', encoding='utf-8') as file_paths_txt:
    for file_path in file_paths_txt:
        file_paths.append(file_path.strip())


def partition_list(items, num_partitions):
    partition_size = int(len(items) / num_partitions)
    partitions = []
    for i in range(num_partitions):
        partitions.append(items[i * partition_size:(i + 1) * partition_size])
    return partitions


def count_words_in_text(text):
    words = text.split()
    word_count = defaultdict(int)
    for word in words:
        word_count[word] += 1
    return word_count


def merge_word_counts(counts, word_count):
    for word, count in word_count.items():
        counts[word] += count


def process_file(file_path, counts):
    with open(file_path, 'r', encoding='utf-8') as file:
        text = file.read()       
        word_count = count_words_in_text(text)
        merge_word_counts(counts, word_count)


def map_reduce_helper(file_paths, counts):
    for file_path in file_paths:
        process_file(file_path, counts)    


def map_reduce(file_paths, num_processors):
    threads = []
    counts = defaultdict(int)
    partial_file_paths = partition_list(file_paths, num_processors)

    for i in range(num_processors):
        thread = threading.Thread(target=map_reduce_helper, args=(partial_file_paths[i], counts))
        thread.start()
        threads.append(thread)

    start_time = time.time()
    for thread in threads:
        thread.join()
    end_time = time.time()

    runtime = end_time - start_time

    return counts, runtime


def write_results(word_counts, times, file_name):
    with open(file_name + '.txt', 'w', encoding='utf-8') as result_txt:
        for word, count in word_counts.items():
            result_txt.write(f"{word}: {count}\n")
        result_txt.write(f"\nTimes: {times}\n")



if __name__ == '__main__':
    with open('stats.txt', 'w', encoding='utf-8') as stats_txt:
        for n in range(1, NUM_PROCESSORS + 1):
            for p in PERCENTAGES:
                partial_file_paths = file_paths[:int(len(file_paths) * p)]
                word_counts, runtime = map_reduce(partial_file_paths, n)
                write_results(word_counts, runtime, 'results_n' + str(n) + '_p' + str(int(p*100)))
                print(f"num_processors: {n}, percentage: {int(p*100)}%, runtime: {runtime} seconds")
                stats_txt.write(f"num_processors: {n}, percentage: {int(p*100)}%, runtime: {runtime} seconds\n")
            

