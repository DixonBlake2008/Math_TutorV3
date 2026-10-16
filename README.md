# Math Tutor V3

<b>Table of Content</b>
- [Summary](#summary)
- [Maintainers](#maintainers)
- [New Concepts Used](#new-concepts-used)
- [Console Output Example](#console-output-example)
  - [Leveling up](#leveling-up)
  - [Leveling down](#leveling-down)
  - [Invalid Numeric Input](#invalid-numeric-input)
  - [Invalid Yes or No Input](#invalid-yes-or-no-input)

## Summary
This is a Silly Simple Math Tutor for young children.
- Display the program header
- Tells a few jokes
- Gets the user's full name and welcomes to the user to the game
- Displays random math questions
- Checks the user's answer
- Gives the user 3 attempts if they are incorrect
- Gives the user multiple math questions
- asks the user if they want to continue
- Levels the user up if they get 3 correct 
- Levels the user down if they get 3 incorrect unless they are on level 1


## Maintainers
[@ConnorStolpe](https://github.com/ConnorStolpe) Connor Stolpe   
[@DixonBlake2008](https://github.com/DixonBlake2008) Blake Dixon


## New Concepts Used
- enum
- while loops
- static_cast
- for loops


## Leveling Up
```
[Level [1] Blake, what does 18 / 2 =9

9 was correct, great job!
Do you want to continue? (Yes or No):y

[Level [1] Blake, what does 6 + 1 =7

7 was correct, great job!
Do you want to continue? (Yes or No):y

[Level [1] Blake, what does 9 - 5 =4

4 was correct, great job!
You leveled up. You are now level #2 The numbers now range from 1 to 20.
```

## Leveling Down
```
[Level [2] Blake, what does 11 - 11 =2

That is incorrect, you have 2 trys left!
[Level [2] Blake, what does 11 - 11 =1

That is incorrect, you have 1 trys left!
[Level [2] Blake, what does 11 - 11 =2

That is incorrect, the correct answer was 0
Do you want to continue? (Yes or No):y

[Level [2] Blake, what does 11 - 2 =2

That is incorrect, you have 2 trys left!
[Level [2] Blake, what does 11 - 2 =2

That is incorrect, you have 1 trys left!
[Level [2] Blake, what does 11 - 2 =2

That is incorrect, the correct answer was 9
Do you want to continue? (Yes or No):y

[Level [2] Blake, what does 18 + 13 =2

That is incorrect, you have 2 trys left!
[Level [2] Blake, what does 18 + 13 =2

That is incorrect, you have 1 trys left!
[Level [2] Blake, what does 18 + 13 =2

That is incorrect, the correct answer was 31
You leveled down. You are now level #1 The numbers now range from 1 to 10.

Do you want to continue? (Yes or No):
```
## Invalid Numeric Input
```
That is incorrect, you have 2 trys left!
[Level [2] Blake, what does 11 - 11 =abc

        Invalid input!
        Please enter a number:1

That is incorrect, you have 1 trys left!
[Level [2] Blake, what does 11 - 11 =
```
## Invalid Yes or No Input
```
You leveled up. You are now level #2 The numbers now range from 1 to 20.

Do you want to continue? (Yes or No):what

Please enter a valid input!
Do you want to continue? (Yes or No):
```