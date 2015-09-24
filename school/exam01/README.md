# Program
## Usage
#### Arguments
- opt = optional
- sorting_methods (default merge): ```merge```, ```bubble```
- files in this repo is: ```1.txt```, ```2.txt```, ```3.txt```, ```4.txt```
- ```loud``` tells the program to output the sorted array
```sh
$ ./program [file_to_search] [opt: sorting_method] [opt: loud]
```
#### Run example
Standard merge sort:
```sh
$ ./program 4.txt
>(sorting with merge took 45 ms.)
>Number to search for (0 to skip): 998869
>index of 998869 in the sorted array is 199766 (used to be index 114504)
```

Specify other sorting methods:
```sh
$ ./program 3.txt bubble
```
Print sorted array to output with ```loud ``` (requires specifying sorting as well)
```sh
$ ./program 3.txt merge loud
```

# Sources
Sources are also commented where they are used.

- Getting timestamp in milliseconds: http://stackoverflow.com/questions/3756323/getting-the-current-time-in-milliseconds
- Dynamic array implementation: http://www.happybearsoftware.com/implementing-a-dynamic-array.html
- Merge-sort is inspired by the sudo-code here: http://www.sorting-algorithms.com/merge-sort
- Makefile inspired by: http://c.learncodethehardway.org/book/ex2.html