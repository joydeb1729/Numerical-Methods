# Bisection Method for Root Finding

## Description
The Bisection Method is a numerical technique used to find the roots of continuous functions. It is particularly useful when the function changes sign over an interval, indicating the presence of a root.

## Theory
The Bisection Method operates on the principle that if a continuous function \( f(x) \) changes sign between two points \( x1 \) and \( x2 \) (i.e., \( f(x1) \cdot f(x2) < 0 \)), there exists at least one root in the interval \([x1, x2]\) due to the Intermediate Value Theorem.

### Steps of the Bisection Method:
1. **Initial Setup:** Choose two initial points \( x1 \) and \( x2 \) such that \( f(x1) \cdot f(x2) < 0 \).
2. **Iteration:**
   - Calculate the midpoint \( x0 = \frac{x1 + x2}{2} \).
   - Evaluate the function at the midpoint: \( f(x0) \).
   - If \( f(x0) \) is sufficiently close to zero (within a specified tolerance), then \( x0 \) is the root.
   - If \( f(x0) \) and \( f(x1) \) have opposite signs, set \( x2 = x0 \); otherwise, set \( x1 = x0 \).
3. **Repeat** the process until the desired accuracy is achieved or a maximum number of iterations is reached.

### Convergence
The Bisection Method guarantees convergence to a root, provided that the initial interval is chosen correctly. The method’s convergence rate is linear, meaning the number of correct digits approximately doubles with each iteration.

### Limitations
- Requires that the function is continuous on the interval \([x1, x2]\).
- Slower than other methods (like Newton-Raphson) for finding roots due to its linear convergence rate.

## Conclusion
The Bisection Method is a foundational algorithm in numerical analysis, offering a reliable way to approximate roots of functions. It is particularly advantageous for functions where other methods may fail or where a guaranteed root-finding process is desired.
