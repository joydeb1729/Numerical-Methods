# Secant Method for Root Finding

## Description
The Secant Method is a numerical technique for finding the roots of real-valued functions. It is an iterative method that uses two initial guesses to approximate the root without requiring the computation of the derivative.

## Theory
The Secant Method approximates the root of a function \( f(x) \) by constructing a secant line between two points. Given two initial guesses \( x1 \) and \( x2 \), the method computes a new approximation \( x3 \) using the formula:
\[
x3 = x2 - \frac{f(x2) \cdot (x2 - x1)}{f(x2) - f(x1)}
\]

### Steps of the Secant Method:
1. **Initial Setup:** Choose two initial guesses \( x1 \) and \( x2 \) such that \( f(x1) \) and \( f(x2) \) have opposite signs.
2. **Iteration:**
   - Calculate the new approximation \( x3 \) using the secant formula.
   - Check for convergence by determining if the relative error \( \left| \frac{x3 - x2}{x3} \right| \) is within a specified tolerance \( E \).
   - If the solution converges, stop the iteration; otherwise, update \( x1 \) and \( x2 \) for the next iteration.
3. **Repeat** until the desired accuracy is achieved or the maximum number of iterations is reached.

### Convergence
The Secant Method can converge faster than the Bisection Method, often exhibiting superlinear convergence. However, convergence is not guaranteed if the initial guesses are not close enough to the actual root.

### Limitations
- Requires two initial guesses; if not chosen appropriately, the method may diverge.
- The function must be continuous, and there should be a sign change between the initial guesses.

## Conclusion
The Secant Method is an effective and straightforward approach for root finding in numerical analysis. Its efficiency and ease of use make it suitable for various applications where derivatives are difficult to compute.
