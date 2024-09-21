# Gauss-Seidel Method for Solving Linear Equations

## Description
The Gauss-Seidel Method is an iterative algorithm used to solve a system of linear equations. It improves upon the Jacobi Method by using the most recently updated values during the iteration process, which often leads to faster convergence.

## Theory
The Gauss-Seidel method solves the system of equations $Ax = b$ by iteratively updating each variable based on the previously computed values of the other variables. For a system of equations:

1. $x_1 + x_2 + x_3 = 5$
2. $3x_1 + 5x_2 + 2x_3 = 15$
3. $2x_1 + x_2 + 4x_3 = 8$

The updates for each variable are given by:
- $x_1 = \frac{5 - x_2 - x_3}{1}$
- $x_2 = \frac{15 - 3x_1 - 2x_3}{5}$
- $x_3 = \frac{8 - 2x_1 - x_2}{4}$

### Steps of the Gauss-Seidel Method:
1. **Initial Setup:** Choose initial guesses for the variables $x_1$, $x_2$, and $x_3$.
2. **Iteration:**
   - For each variable, compute its new value using the most recent values of the other variables.
   - Continue updating until the change in values is within a specified tolerance $E$.
3. **Repeat** until convergence is achieved or the maximum number of iterations is reached.

### Convergence
The Gauss-Seidel Method converges if the coefficient matrix $A$ is strictly diagonally dominant or positive definite. It generally converges faster than the Jacobi Method.

### Limitations
- Like the Jacobi Method, convergence is not guaranteed for all systems, especially if the matrix is not diagonally dominant.
- The method may converge slowly for poorly conditioned systems.

## Conclusion
The Gauss-Seidel Method is an efficient iterative technique for solving systems of linear equations. Its ability to use updated values leads to quicker convergence, making it a valuable tool in numerical analysis and computational mathematics.
