"""
Merge Sort Implementation in Python
Author: Pravalika Neela
CSU ID: 2922176

Scenario:
- Each "server" produces its own log file.
- Each log entry is represented as an integer timestamp.
- We read timestamps from multiple servers, combine them,
  and then sort them using Merge Sort to simulate merging
  log files from different servers for analysis.
"""


def merge_sort(array):
    """
    Recursively sorts the list 'array' using Merge Sort.
    Returns a new sorted list.
    """
    if len(array) <= 1:
        return array

    mid = len(array) // 2
    left = merge_sort(array[:mid])
    right = merge_sort(array[mid:])

    i = j = 0
    result = []

    # Merge the two sorted halves
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1

    # Append any remaining elements
    result.extend(left[i:])
    result.extend(right[j:])
    return result


def main():
    """
    Simulates multiple server log files:
    - Ask how many servers we have.
    - For each server, read timestamps (integers).
    - Combine all timestamps into one list.
    - Sort the combined list using merge_sort.
    """
    print("=== Merge Sort Log Merger (Python) ===")

    # Number of servers (log files)
    num_servers = int(input("Enter number of servers (log files): "))

    all_timestamps = []

    for s in range(1, num_servers + 1):
        print(f"\nServer {s}:")
        count = int(input("  Enter number of log entries for this server: "))
        raw = input("  Enter timestamps (integers) separated by spaces: ").split()

        # Take only 'count' values and convert to int
        server_logs = [int(x) for x in raw[:count]]
        print(f"  Raw log timestamps for server {s}: {server_logs}")

        # Add to global list
        all_timestamps.extend(server_logs)

    print("\nCombined timestamps from all servers (unsorted):")
    print(all_timestamps)

    # Sort combined logs
    sorted_logs = merge_sort(all_timestamps)

    print("\nMerged & sorted timestamps (across all servers):")
    print(sorted_logs)


if __name__ == "__main__":
    main()
