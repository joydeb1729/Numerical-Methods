# Jacobi Iteration Method for Solving Linear Equations

## Description
The Jacobi Iteration Method is an iterative algorithm used to solve a system of linear equations. It is particularly useful for diagonally dominant or symmetric positive definite matrices.

## Theory
The Jacobi method solves the system of equations $Ax = b$ by decomposing the matrix $A$ into its diagonal and remainder components. Each variable is updated based on the previous values of all the other variables.

Given a system of equations:
1. $x_1 + x_2 + x_3 = 5$
2. $3x_1 + 5x_2 + 2x_3 = 15$
3. $2x_1 + x_2 + 4x_3 = 8$

The Jacobi iteration for each variable can be expressed as:
- $x_1 = \frac{5 - x_2 - x_3}{1}$
- $x_2 = \frac{15 - 3x_1 - 2x_3}{5}$
- $x_3 = \frac{8 - 2x_1 - x_2}{4}$

### Steps of the Jacobi Iteration Method:
1. **Initial Setup:** Choose initial guesses for the variables $x_1$, $x_2$, and $x_3$.
2. **Iteration:**
   - For each variable, compute its new value based on the most recent values of the other variables.
   - Continue updating until the change in values is within a specified tolerance $E$.
3. **Repeat** until convergence is achieved or the maximum number of iterations is reached.

### Convergence
The Jacobi method converges if the coefficient matrix $A$ is strictly diagonally dominant or positive definite.

### Limitations
- The method may converge slowly for poorly conditioned systems or may fail to converge if the matrix is not diagonally dominant.
- The convergence depends on the choice of initial guesses.

## Conclusion
The Jacobi Iteration Method is a fundamental technique for solving systems of linear equations, especially in large-scale problems. Its simplicity and ease of implementation make it a valuable tool in numerical analysis.
