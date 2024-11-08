# Least Squares Regression

This program implements a **Least Squares Linear Regression** model to fit a straight line to a set of data points. The equation of the line is given by:

$$
y = a + bx
$$

Where:
- $a$ is the intercept (the value of $y$ when $x = 0$).
- $b$ is the slope of the line, representing the rate of change of $y$ with respect to $x$.

## Input

The program requires:
1. The number of data points $n$.
2. Pairs of values $(x_i, y_i)$ for each data point.

## Output

The program outputs the best-fit line equation:

$$
y = a + bx
$$

## Formulae

To compute $b$ (the slope):

$$
b = \frac{n \sum (x_i \cdot y_i) - \sum x_i \cdot \sum y_i}{n \sum (x_i)^2 - (\sum x_i)^2}
$$

To compute $a$ (the intercept):

$$
a = \frac{\sum y_i}{n} - b \cdot \frac{\sum x_i}{n}
$$

## Example

For input data points $(x_1, y_1), (x_2, y_2), \dots, (x_n, y_n)$, the program calculates the values of $a$ and $b$, and outputs the equation of the best-fit line.

## How It Works

1. The program prompts the user to input the number of data points $n$.
2. The user enters pairs of $(x_i, y_i)$ values.
3. The program calculates the necessary summations: $\sum x_i$, $\sum y_i$, $\sum x_i \cdot y_i$, and $\sum x_i^2$.
4. Using these sums, it calculates $b$ (the slope) and $a$ (the intercept).
5. The final equation of the regression line is displayed in the form $y = a + bx$.

## Requirements

- C++ Standard Library (for mathematical functions and input/output).
