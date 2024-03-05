# Coding Tasks Overview

This collection of programming tasks is designed to challenge and enhance your coding skills through a variety of exercises ranging from simple input/output operations to complex algorithmic problems. Below you will find a detailed description of each task along with its objectives.

## Task 1: Custom Greeting Program

**Objective:** Modify a basic program to personalize its greeting. Instead of the generic "Hello, World", the program should prompt the user to enter their name and then greet them by name.

- **Implementation Tips:** Utilize the `scanf` function to read the user's name. You'll need to pass a pointer to a variable where the input will be stored. For now, don't worry about the intricacies of pointers; just focus on getting the basic functionality to work.

## Task 2: Average Grades Calculation

**Objective:** Calculate the average grades for a group of five students across two subjects: Mathematics and Physics.

- **Implementation Details:** Use a two-dimensional array named `grades` to store the marks. Store the Mathematics grades in the first row (`grades[0]`) and the Physics grades in the second row (`grades[1]`).

## Task 3: Factorial Calculation

**Objective:** Write a function to calculate the factorial of each number in a given array `int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};`.

- **Implementation Tips:** The function should accept an array as input and compute the factorial for each element in the array. This is an excellent exercise to practice loops and recursion.

## Task 4: Custom Number Printing

**Objective:** Print numbers from 1 to 200, with a twist. For multiples of 5, print "Foo"; for multiples of 7, print "Bar"; and for numbers that are multiples of both 5 and 7, print "FooBar" instead of the number.

- **Implementation Details:** This task requires careful consideration of the order in which you check for multiples to ensure that "FooBar" is printed correctly for numbers like 35, 70, etc.

## Task 5: Sum of Multiples

**Objective:** Calculate the sum of all multiples of 3 or 5 below a given number. For negative numbers, the function should return 0. Note: If a number is a multiple of both 3 and 5, it should only be counted once in the sum.

- **Example:** For all natural numbers below 10, the multiples of 3 or 5 are 3, 5, 6, and 9. The sum of these multiples is 23.

## Task 6: Rock, Paper, Scissors Game

**Objective:** Develop a program that allows two players to play Rock, Paper, Scissors. The program should keep track of the scores and moves in each round and display them upon request, for example, when a user enters the command `scores`.

- **Implementation Tips:** Consider how to store the moves and results of each round efficiently. The program should allow users to play multiple rounds and retrieve the game history whenever requested.

---

Happy coding!