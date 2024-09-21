# Secant Method for Root Finding

## Description
The Secant Method is a numerical technique for finding the roots of real-valued functions. It is an iterative method that uses two initial guesses to approximate the root without requiring the computation of the derivative.

## Theory
The Secant Method approximates the root of a function $ f(x) $ by constructing a secant line between two points. Given two initial guesses $ x_1 $ and $ x_2 $, the method computes a new approximation $ x_3 $ using the formula:

$$
x_3 = x_2 - \frac{f(x_2) \cdot (x_2 - x_1)}{f(x_2) - f(x_1)}
$$

### Steps of the Secant Method:
1. **Initial Setup:** Choose two initial guesses $ x_1 $ and $ x_2 $ such that $ f(x_1) $ and $ f(x_2) $ have opposite signs.
2. **Iteration:**
   - Calculate the new approximation $ x_3 $ using the secant formula.
   - Check for convergence by determining if the relative error $ \left| \frac{x_3 - x_2}{x_3} \right| $ is within a specified tolerance $ E $.
   - If the solution converges, stop the iteration; otherwise, update $ x_1 $ and $ x_2 $ for the next iteration.
3. **Repeat** until the desired accuracy is achieved or the maximum number of iterations is reached.

### Convergence
The Secant Method can converge faster than the Bisection Method, often exhibiting superlinear convergence. However, convergence is not guaranteed if the initial guesses are not close enough to the actual root.

### Limitations
- Requires two initial guesses; if not chosen appropriately, the method may diverge.
- The function must be continuous, and there should be a sign change between the initial guesses.

## Conclusion
The Secant Method is an effective and straightforward approach for root finding in numerical analysis. Its efficiency and ease of use make it suitable for various applications where derivatives are difficult to compute.
