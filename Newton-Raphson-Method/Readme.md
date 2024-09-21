# Newton-Raphson Method for Root Finding

## Description
The Newton-Raphson Method is a powerful numerical technique used to find roots of real-valued functions. It is an iterative method that uses the function and its derivative to converge rapidly to a root.

## Theory
The Newton-Raphson Method is based on the principle of linear approximation. Given an initial guess $x_0$, the method refines this guess by using the formula:

$$
x = x_0 - \frac{f(x_0)}{f'(x_0)}
$$

where $f(x)$ is the function for which the root is being sought, and $f'(x)$ is its derivative.

### Steps of the Newton-Raphson Method:
1. **Initial Setup:** Choose an initial guess $x_0$.
2. **Iteration:**
   - Calculate the next approximation using the formula:
   
   $$
   x = x_0 - \frac{f(x_0)}{f'(x_0)}
   $$
   
   - Check for convergence by determining if the relative error $ \left| \frac{x - x_0}{x} \right| $ is within a specified tolerance $E$.
   - If the solution converges, stop the iteration; otherwise, update $x_0$ to $x$ and repeat the process.
3. **Repeat** until the desired accuracy is achieved or the maximum number of iterations is reached.

### Convergence
The Newton-Raphson Method typically converges quickly, often achieving quadratic convergence under suitable conditions. However, convergence is not guaranteed if the initial guess is not close to the actual root or if the function's derivative is zero at any iteration.

### Limitations
- The method requires the calculation of the derivative $f'(x)$, which may not be feasible for all functions.
- It may fail to converge if the initial guess is poor, or if the function is not well-behaved (e.g., discontinuities or inflection points near the root).

## Conclusion
The Newton-Raphson Method is a highly effective algorithm for finding roots of functions, making it a staple in numerical analysis. Its efficiency and simplicity make it suitable for a wide range of applications.
