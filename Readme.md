# Algorithms and data structures cource in Vilnius university (2021, spring semester)

## [Task 1](/Lab1)
Implement vector data structure using c programming language
## [Task 2](/Lab2)
- [5 queens](/Lab2/5-queens/)
Place 5 queens on the N*N (8 in the code, can be changed) chessboard so that at least one queen crosses each square.
- [8 rooks](/Lab2/8-rooks/)
Place 8 rooks on an N*N(8 in the code, can be changed) chessboard, so that each cell is crossed by at least one rooks.
- [12 knights](/Lab2/12-knights/)
Place 12 knights on the N*N(8 in the code, can be changed) chessboard, with at least one knight crossing each square.
- [Divide in 2](/Lab2/divide_in_two/)
Given N objects with weights s1, s2,..., sN. The program divides the objects into 2 groups so that the weights of the groups are as equal as possible. Print all solutions. The user specifies a file to enter N and the weights.
- [Knights tour](/Lab2/knights-tour/)
    Go through 8*8 chessboard with knight moves.
- [N queens problem](/Lab2/n-queens-problem/)
Place N chess queens on an N×N chessboard so that no two queens attack each other.
- [Send me money](/Lab2/send_me_money/)
Write a program to solve a arithmetic problem:
  SEND + MORE =  MONEY
- [Sudoku](/Lab2/sudoku/)
Write a sudoku solver for a given sudoku in a file.
- [Triangle queens](/Lab2/triangle_queens/)
What is the maximum number of queens that can be placed on an M-triangular board without them crossing each other? Print the solution. Enter M - triangle size. (Triangular N-queens problem)
- [Zero sum](/Lab2/zero-sum/)
Given an array consisting of integers, find if there's subset such that subset sum is equal to zero.

## [Task 3](/Lab3)
Bank (ADT: queue, long integer). Process: customers come to the bank and approach any available teller. If all tellers are busy, customers join the general queue.
Explore how it is more appropriate for the bank to (1) have a small number of fast tellers, who serve customers faster, or (2) a large number of slow tellers, who serve customers slower).
Baseline data: number of tellers, customer service time, probability of a customer coming in. Possible probabilistic implementation: generate a random number and check if it satisfies a certain condition.
Output: statistics for a given simulation time, e.g. N=60 minutes. These are the average and maximum waiting time of the customer, the average occupancy of the cashier (percentage), the maximum queue size, etc.

## [Task 4](/Lab4)

A list of flights: city, city and price. Find the cheapest route and price for a flight from one given city to another given city. Predict the case that no such route exists. (The graph realisation is based on a neighbourhood list.)
- Used DFS to find if there's a way to reach a city at all.