# Operating Systems - CS 4328
## Project 3

### Group Members

- Tyler Cummings - trc119
- Cameron Peterson - cnp23

### Instructions

To compile the program, perform the following command:

    g++ main.cpp
    
To run the program, perform the following command:

    ./a.out
    
To change the number of runs, edit the following line (line 14) in `main.cpp`:

    #define RUN_COUNT 10
    
In the above case, the program will run 10 times, each with a different frame size between 1 and 30.

### Results

The following is the redacted output of a single run of a.out:

    *************** TEST 1 ***************

    Number of page frames:  14

    Page fault count: 

            FIFO:           75
            LRU:            76
            OPTIMAL:        53


    *************** TEST 2 ***************

    Number of page frames:  11

    Page fault count: 

            FIFO:           79
            LRU:            79
            OPTIMAL:        55


    *************** TEST 3 ***************

    Number of page frames:  14

    Page fault count: 

            FIFO:           74
            LRU:            71
            OPTIMAL:        49


    *************** TEST 4 ***************

    Number of page frames:  13

    Page fault count: 

            FIFO:           72
            LRU:            74
            OPTIMAL:        55


    *************** TEST 5 ***************

    Number of page frames:  19

    Page fault count: 

            FIFO:           59
            LRU:            60
            OPTIMAL:        42


    *************** TEST 6 ***************

    Number of page frames:  12

    Page fault count: 

            FIFO:           84
            LRU:            81
            OPTIMAL:        56


    *************** TEST 7 ***************

    Number of page frames:  23

    Page fault count: 

            FIFO:           60
            LRU:            63
            OPTIMAL:        46


    *************** TEST 8 ***************

    Number of page frames:  6

    Page fault count: 

            FIFO:           91
            LRU:            92
            OPTIMAL:        71


    *************** TEST 9 ***************

    Number of page frames:  2

    Page fault count: 

            FIFO:           96
            LRU:            96
            OPTIMAL:        85


    *************** TEST 10 ***************

    Number of page frames:  17

    Page fault count: 

            FIFO:           74
            LRU:            75
            OPTIMAL:        51

The following chart reflects the results of the aforementioned run:

![](https://github.com/Tylrrc/OpSys_Project_3/blob/master/FIFO%2C%20LRU%20and%20OPTIMAL.png)


