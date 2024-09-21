# Gauss-Seidel Method for Solving Linear Equations

## Description
The Gauss-Seidel Method is an iterative algorithm used to solve a system of linear equations. It improves upon the Jacobi Method by using the most recently updated values during the iteration process, which often leads to faster convergence.

## Theory
The Gauss-Seidel method solves the system of equations \( Ax = b \) by iteratively updating each variable based on the previously computed values of the other variables. For a system of equations:

1. \( x1 + x2 + x3 = 5 \)
2. \( 3x1 + 5x2 + 2x3 = 15 \)
3. \( 2x1 + x2 + 4x3 = 8 \)

The updates for each variable are given by:
- \( x1 = \frac{5 - x2 - x3}{1} \)
- \( x2 = \frac{15 - 3x1 - 2x3}{5} \)
- \( x3 = \frac{8 - 2x1 - x2}{4} \)

### Steps of the Gauss-Seidel Method:
1. **Initial Setup:** Choose initial guesses for the variables \( x1, x2, \) and \( x3 \).
2. **Iteration:**
   - For each variable, compute its new value using the most recent values of the other variables.
   - Continue updating until the change in values is within a specified tolerance \( E \).
3. **Repeat** until convergence is achieved or the maximum number of iterations is reached.

### Convergence
The Gauss-Seidel Method converges if the coefficient matrix \( A \) is strictly diagonally dominant or positive definite. It generally converges faster than the Jacobi Method.

### Limitations
- Like the Jacobi Method, convergence is not guaranteed for all systems, especially if the matrix is not diagonally dominant.
- The method may converge slowly for poorly conditioned systems.

## Conclusion
The Gauss-Seidel Method is an efficient iterative technique for solving systems of linear equations. Its ability to use updated values leads to quicker convergence, making it a valuable tool in numerical analysis and computational mathematics.