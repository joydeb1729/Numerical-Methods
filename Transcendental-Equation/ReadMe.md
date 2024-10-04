# Transcendental Equation: Power Law Regression Model

This program implements a **Power Law Regression Model** for an equation of the form:

$$
y = a \cdot x^b
$$

By taking the natural logarithm, the equation is transformed into a linear form:

$$
\ln(y) = \ln(a) + b \cdot \ln(x)
$$

The program calculates the constants $a$ and $b$ using the least squares method, fitting the relationship between $x$ and $y$.

## Input

The program prompts for:
1. The number of data points, $n$.
2. A set of $n$ pairs $(x_i, y_i)$.

## Output

After computing the regression, the output is the best-fit equation:

$$
y = a \cdot x^b
$$

Where:
- $a = \exp(\ln(a))$
- $b$ is calculated based on the sum of logarithmic transformations of $x$ and $y$.

## Formulae

The program computes the following summations:
- $\sum \ln(x_i)$
- $\sum \ln(y_i)$
- $\sum (\ln(x_i) \cdot \ln(y_i))$
- $\sum (\ln(x_i)^2)$

Then, $b$ is determined by:

$$
b = \frac{n \sum (\ln(x_i) \cdot \ln(y_i)) - \sum \ln(x_i) \cdot \sum \ln(y_i)}{n \sum \ln(x_i)^2 - (\sum \ln(x_i))^2}
$$

The constant $\ln(a)$ is:

$$
\ln(a) = \frac{\sum \ln(y_i)}{n} - b \cdot \frac{\sum \ln(x_i)}{n}
$$

Finally, $a$ is derived as:

$$
a = \exp(\ln(a))
$$

## Example

For input data points $(X_1, Y_1), (X_2, Y_2), \dots, (X_n, Y_n)$, the program outputs the fitted power law equation.

## Requirements

- C++ standard libraries `<cmath>`, `<iostream>`, `<bits/stdc++.h>`.
