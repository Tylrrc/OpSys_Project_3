# OpSys_Project_3

CS 4328
Operating Systems

# Programming Assignment #3

Assigned: 11/18/19  
Due: Monday, 12/2/19 at 11:55 PM

This project is going to take a good amount of work and time, so please start early. You would not be able to finish if you start a few days before the due date. **Late submissions will not be accepted.** Leave the last few days for documentation, further testing and formatting the results. **Please read the description carefully and come to see me if you have any questions.** You may discuss this project with other students. However, you must write your code and your report on your own.

## 1. Overview
In this project, we are going to write a program that implements several virtual-memory page replacement algorithms. The goal of this project is to compare and assess the impact of these algorithms on the number of page faults incurred across a varying number of physical-memory page frames available.

### 1.1. Page replacement Algorithms
We are going to implement the following page replacement algorithms that we discussed in class:
1.	First-In, First-Out (FIFO)
2.	Least Recently Used (LRU)
3.	Optimal (OPT)
Implement the algorithms so that the number of page frames available can be passed in as an argument.

1.2. Performance Metric
We are interested in computing the following metric:
• The number of page faults incurred

## 2. The Process
First, generate a random page-reference string, of size 100, where virtual page numbers range from 0 to 49. Apply the same page-reference string to each algorithm, and record the number of page faults incurred by each algorithm. Assume that demand paging is used. Structure the program to run so that you vary the number of physical-memory page frames available from 1 to 30.

## 3. Submission details
Submission shall be done using the Assignments tool on the TRACS website for this class. Please submit a single zip file including all your files.
Name your file program3_xxxxx_yyyyy.zip where xxxxx and yyyyy are the TX State NetIDs of the team mates.
Submissions shall include the source code and instructions for how to compile and run the program on one of the CS Linux servers, along with a report containing the results of the runs and their interpretation.
The report shall include a single plot for the above metric. The plot on the x-axis will vary the number of page frames available, and represent the number of page faults on the y-axis, with a different-color line for each of the three algorithms. See example plot on page 406 (Fig. 10.13).
You can write your program in any of these languages (C, C++, Python or Java), however, it is your responsibility to ensure it runs on the CS Linux servers with a command line – nothing graphical (GUI-based). Please indicate clearly how to compile and run your program.

### Grade breakdown:
* 30% of the grade is on developing the correct design and data structures.
* 60% of the grade is on obtaining the correct results (i.e., the metric and plot) for the algorithms.
* 10% of the grade is on proper documentation (i.e., explanation of the results, providing the compile and run command lines, etc.).

Have fun with the project!
