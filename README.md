# Reverse Polish Notation Convertor and Calculator

The project was created as a part of my study in the university. 
It consists of infix to postfix converter, postfix calculator powered by custom String, Stack and Queue classes along with tests to check the functionality of algorithm.
Additionally I wrote script Python to automatically compile and run algorithm for every of those tests and compare the results.
Tests were provided by the course instructors.

The algorithm needs improvement and its current state cannot be considered final. 
It is functional and passed all the tests (my main goal). 

It can handle not only basic arithmetic operations (+-*/), but also negation (as an N function instead of minus), IF function and MAX/MIN functions (see below). 
Tt accepts only not-negative integers as an input, but can calculate and output negative numbers.

Below are the rules I followed while working on the project.

---

# Rules

Write an integer calculator. Use the postfix notation to handle precedence of operators, functions and parentheses.
Input:
- n - number of formulas
- n formulas, each in the form given below.

Each formula is a valid expression in an infix notation with functions and ends with a dot ('.'). Each token is separated by some whitespace characters. Each operand is a positive integer (although the result of an operation might be negative). Each operator is a single character and every function name consists only of capital letters.

The following operations are available, in the ascending order of priority:

- a + b, a - b ;
- a * b, a / b - all operations are made on integers, hence the results of division are rounded down (standard C '/' operator). You cannot divide by 0 (see the Output section);
- Same priority:
  - IF(a, b, c) - if a > 0 return b, otherwise c,
  - N a - unary negation, i.e. -a,
  - MIN( a1, a2, ... ), MAX( a1, a2, ... ) - functions MIN and MAX do not have a restriction on the number of parameters;
- ( ... ) - parentheses.

### Output for each formula:

- the formula in the postfix notation;
- before executing each operation print the operator or function and the content of the stack;
- the final result;
- if you encounter a division by 0, print "ERROR" and move to the next expression. 

### Additional remarks and hints:

- Each instance of MINi and MAXi function has a specified number of arguments, i, in the postfix notation (see the example output)
- Do not store the given expressions (i.e. in the infix notation), only the latest token should be sufficient. Consequently, you should count the arguments of MIN and MAX during the conversion. Additional instances of data structures might be required.
- You may assume that all values will be withing range of int. Note that each token is separate.
- Using the type string and data structures from libraries is **forbidden**.
- For the full amount of points, a stack based on a list is required. In the case of a stack implemented using an array, the amount of points is scaled by 0.75.
  - This does not mean that stacks are the only permitted data structures. You can use additonal data structures to solve encountered difficulties beyond the basic algorithms from the lecture.
- Remember to clean up any unused memory. Memory leaks will be penalized.

# Credits

The author of the rules is Robert O***. The full name is withheld for confidentiality reasons.