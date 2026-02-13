# Reverse Polish Notation Converter and Calculator

Infix to Postfix converter and Postfix calculator.

# Features

- Manually implemented String, Stack and Queue classes.
- Tests: python script that runs tests and compares results.
- Handles basic arithmetic operations (`+-*/`).
- Handles functions: `N` (negation), `IF`, `MAX`/`MIN` (more on it below).
- Handles parentheses.
- Calculates and outputs negative numbers (though, doesn't accept negative numbers of input).
- No memory leaks.

# Description of operations

The following operations are available, in the ascending order of priority:

- a + b, a - b ;
- a * b, a / b - all operations are made on integers, hence the results of division are rounded down (standard C '/' operator). No division by 0.
- Same priority:
  - IF(a, b, c) - if a > 0 return b, otherwise c,
  - N a - unary negation, i.e. -a,
  - MIN( a1, a2, ... ), MAX( a1, a2, ... ) - functions MIN and MAX do not have a restriction on the number of parameters;
- ( ... ) - parentheses.

# Accepted input

Basic input:
- n - number of formulas
- n formulas, each in the form given below.

Rules:
- Each formula must be in an infix notation and end with a dot ('.').
- Each token must be separated by some whitespace characters.
- Each operand must be a positive integer.
- Each operator must be a single character.
- Every function name must consist only of capital letters.
- All values must be within range of int.

# Output

- Formula in the postfix notation.
- Printed operator or function and the content of the stack, before executing any operation.
- Final result.
- If division by 0 encountered, "ERROR" is printed. Algorithm moves to the next expression.
- Each instance of `MIN` and `MAX` function has a specified number of arguments, `i`, in the postfix notation (e.g. `MIN3`, `MAX5` - see examples).

# Examples
Example input:
```
4
MIN ( 100 , MAX ( 1 , 34 , 2 ) , 80 ,  MIN ( 66 , 36  , 35 , 77 ) , 50 , 60 ) .
2 + MIN ( 100 , MAX ( 1 , 6 * 5 + 2 , 2 ) , 80 ,  MIN ( 66 , 36  , 35 , 77 ) , 50 , 60 ) * 3 .
N 400 + ( 11 - ( 3 * 2 ) ) / 2 + N N 200 .
IF ( ( 6 + 8 ) , ( 4 / 2 ) , MIN ( 8 , 2 , 1 , 0 , 3 ) ) * 2 * 6 / N ( 3 ) .
```
Example ouput:
```
100  1  34  2  MAX3  80  66  36  35  77  MIN4  50  60  MIN6
MAX3 2 34 1 100
MIN4 77 35 36 66 80 34 100
MIN6 60 50 35 80 34 100
34

2  100  1  6  5  *  2  +  2  MAX3  80  66  36  35  77  MIN4  50  60  MIN6  3  *  +
* 5 6 1 100 2
+ 2 30 1 100 2
MAX3 2 32 1 100 2
MIN4 77 35 36 66 80 32 100 2
MIN6 60 50 35 80 32 100 2
* 3 32 2
+ 96 2
98

400  N  11  3  2  *  -  2  /  +  200  N  N  +
N 400
* 2 3 11 -400
- 6 11 -400
/ 2 5 -400
+ 2 -400
N 200 -398
N -200 -398
+ 200 -398
-198

6  8  +  4  2  /  8  2  1  0  3  MIN5  IF  2  *  6  *  3  N  /
+ 8 6
/ 2 4 14
MIN5 3 0 1 2 8 2 14
IF 0 2 14
* 2 2
* 6 4
N 3 24
/ -3 24
-8
```

