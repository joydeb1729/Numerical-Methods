# Gauss-Jordan Elimination Solver for 3x3 Linear System

This C++ program solves a system of three linear equations with three unknowns using the **Gauss-Jordan Elimination** method. The program accepts the equations in the form `a1x1 + b1x2 + c1x3 = d1` and applies forward elimination followed by backward elimination (also called Gauss-Jordan) to compute the values of `x1`, `x2`, and `x3`.

## Features

- Extracts coefficients and constants from input linear equations.
- Uses Gauss-Jordan elimination to reduce the system into row-reduced echelon form (RREF).
- Provides the final solution for all three unknowns.