
# Chapter 4 Divide and Conquer

In divide-and-conquer, we solve a problem recursively, applying three steps at each level of the recursion:

- Divide the problem into a number of subproblems that are smaller instances of the
same problem.
- Conquer the subproblems by solving them recursively. If the subproblem sizes are
small enough, however, just solve the subproblems in a straightforward manner.
- Combine the solutions to the subproblems into the solution for the original problem.

To characterize the running times of divede-and-conquer, we can use recurrences equation or inequality, for example

T(n) = aT(n/b) + f(n)

this is also called master method


