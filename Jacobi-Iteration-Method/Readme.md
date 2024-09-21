# Jacobi Iteration Method for Solving Linear Equations

## Description
The Jacobi Iteration Method is an iterative algorithm used to solve a system of linear equations. It is particularly useful for diagonally dominant or symmetric positive definite matrices.

## Theory
The Jacobi method solves the system of equations \( Ax = b \) by decomposing the matrix \( A \) into its diagonal and remainder components. Each variable is updated based on the previous values of all the other variables.

Given a system of equations:
1. \( x1 + x2 + x3 = 5 \)
2. \( 3x1 + 5x2 + 2x3 = 15 \)
3. \( 2x1 + x2 + 4x3 = 8 \)

The Jacobi iteration for each variable can be expressed as:
- \( x1 = \frac{5 - x2 - x3}{1} \)
- \( x2 = \frac{15 - 3x1 - 2x3}{5} \)
- \( x3 = \frac{8 - 2x1 - x2}{4} \)

### Steps of the Jacobi Iteration Method:
1. **Initial Setup:** Choose initial guesses for the variables \( x1, x2, \) and \( x3 \).
2. **Iteration:**
   - For each variable, compute its new value based on the most recent values of the other variables.
   - Continue updating until the change in values is within a specified tolerance \( E \).
3. **Repeat** until convergence is achieved or the maximum number of iterations is reached.

### Convergence
The Jacobi method converges if the coefficient matrix \( A \) is strictly diagonally dominant or positive definite.

### Limitations
- The method may converge slowly for poorly conditioned systems or may fail to converge if the matrix is not diagonally dominant.
- The convergence depends on the choice of initial guesses.

## Conclusion
The Jacobi Iteration Method is a fundamental technique for solving systems of linear equations, especially in large-scale problems. Its simplicity and ease of implementation make it a valuable tool in numerical analysis.
