# Description

This project implements the MergeSort algorithm in Python and C, demonstrating how the same algorithm behaves under two different programming paradigms and runtime environments.

MergeSort is a divide-and-conquer algorithm that recursively  splits a collection of date into halves, sorts each half, and merges them back together.

Real-Time Scenario: Log File Merging

A real-world application of MergeSort is merging timestamped log files from multiple servers.
Each server maintains its own log file, usually sorted by its internal clock. When logs from several servers must be combined for analysis, the global ordering of timestamps is no longer guaranteed.

In this project, each server’s “log file” is represented as a list of timestamps (integers).
Both programs:

	•	Accept log data from multiple servers
	•	Combine all timestamps into one collection
	•	Apply MergeSort to generate a globally sorted timeline, simulating the real process of merging distributed system logs.

# Programming Languages and Paradigms Chosen

Python Version

	•	Paradigm: 
            • High-level, functional-style
	•	Characteristics: 
            • Uses recursive functions returning new lists
            • Automatic memory management (garbage collection)
            • Slicing (a[:mid], a[mid:]) creates new sublists
	•	Why suitable:
            • Simple, expressive, and ideal for modeling lists of timestamps or log records.


C Version

	•	Paradigm: 
                • Low-level, imperative and procedural
	•	Characteristics:
	            • Works directly with arrays and pointers
		        • Sorts in-place
	            • Manual memory allocation using malloc and free
	•	Why suitable:
                • Offers control over memory usage and efficiency for large datasets or real-time systems.

# Compilers / Interpreters Used

Python

• Interpreter: Python 3.x

• command to run 

```python 
python3 2922176.py  #2922176.py is the python file name 
```

C 

•	Compiler: GCC (or any ANSI C compiler)

•	To compile and run

```c
gcc -o 2922176 2922176.c #2922176.c is the C file name
./2922176.c #Executable file 
```
 # Instructions for Running and Testing Your Code

Python 

1. RUN

```python 

python3 2922176.py 
```
2.	Enter the number of servers.
3.	For each server, enter the number of log timestamps and the timestamp values.
4.	Program outputs:

	•	Logs for each server

	•	Combined unsorted logs

	•	Fully merged & sorted timeline

C

1.	Compile the program:

```c
gcc -o 2922176 2922176.c
```
2. Run the program :

```c
./2922176
```

3.	Enter server count and timestamps.

4.	Program outputs:

	•	Raw combined logs

	•	Sorted merged timestamp list

# Testing Recommendations

Try inputs such as:

  • Server 1: 101 205 389

  • Server 2: 150 199 450

  • Server 3: 88 600 601

```
Expected sorted output:
88 101 150 199 205 389 450 600 601
```
# Code Snippets Used for Comparison

```python
python 

left = merge_sort(array[:mid])
right = merge_sort(array[mid:])
result = []

while i < len(left) and j < len(right):
    if left[i] <= right[j]:
        result.append(left[i])
        i += 1
    else:
        result.append(right[j])
        j += 1
```
```c
C

int *L = malloc(n1 * sizeof(int));
int *R = malloc(n2 * sizeof(int));

while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
        a[k++] = L[i++];
    } else {
        a[k++] = R[j++];
    }
}

free(L);
free(R);
```

The above code snippets performs similar algorithm [Merge Sort] but different memory behavior and typing behavior.

# Concept Comparison for python & C

***Concept # 1 - Memory Management / Garbage Collection***

python

    • Memory is managed automatically.

	• Slicing (a[:mid]) creates new lists automatically.

	• Temporary lists are cleaned by Python’s garbage collector.

	• No manual memory freeup is required 

C

	• Memory is manually allocated using malloc.

	• Programmer must call free for every allocation.

	• Errors can cause memory leaks or segmentation faults.

**Summary**

    • Python prioritizes safety and simplicity.

    • C prioritizes control and efficiency.




***Concept # 2: Implementation Model (Interpreted vs Compiled)***

**python**
 
 	• Runs on an interpreter, which executes code dynamically.
	• Allows fast development and testing.
	• Slower execution due to overhead.

**C**

	• Compiled into machine code before execution.
	• Much faster performance.
	• Better suited for real-time log processing workloads.

**Summary**
   
   • Python is flexible.

   • C is high-performance due to its memory management.

***Concept #3: Typing System (Dynamic vs Static)***

**python**

	• Dynamically Typed — no need to declare variable types.
	• Types are decided at runtime.
	• Code is simpler but type errors appear later.

**C**

	• Statically Typed — every variable must have a declared type.
	• Type checking happens at compile time.
	• Catching errors earlier improves safety and performance.


**Summary**

    • Python focuses on ease of use
    • C enforces strict correctness

***Concept #4 Programming Paradigms***

**Python – Functional Flavor**

	• Recursion is central.
	• Produces new lists (not in-place).
	• Minimal side effects.

**C – Imperative Style**

	• Works in-place on arrays.
	• Updates memory directly.
	• Explicit step-by-step instructions.


# Conclusion

Both the Python and C implementations produce the same globally sorted list of timestamps, demonstrating how MergeSort can be adapted for a real-time log analysis scenario.

However, the differences in:

	•	memory handling

	•	execution model

	•	typing behavior

	•	programming paradigm

show how language design dramatically influences the way the same algorithm is expressed.
Python emphasizes abstraction and readability, while C emphasizes performance and control.



## References

1. **GeeksforGeeks – Merge Sort**  
   A simple understanding of merge sort algorithm.  
   https://www.geeksforgeeks.org/merge-sort/

2. **Python Docs**  
   Official documentation for Python language.  
   https://docs.python.org/3/

3. **C Language Reference**  
   Documentation for standard C programming constructs.  
   https://www.tutorialspoint.com/cprogramming/index.htm
   
   https://en.wikipedia.org/wiki/C_(programming_language)#Limitations









