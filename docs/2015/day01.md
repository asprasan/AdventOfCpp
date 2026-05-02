# Day 1

**Problem summary**: Given a string of parentheses, determine the final floor Santa ends up on. An opening parenthesis `(` means going up one floor, and a closing parenthesis `)` means going down one floor.

## Part 1 solution

Once the input string is read, we can iterate through each character and keep track of the current floor. We start at floor 0, and for each `(` we add 1 to the floor, and for each `)` we subtract 1 from the floor. After processing the entire string, the final value of the floor variable will be the answer.

```cpp
// code snipped to check for the parantheses and calculate the final floor
// ... 
    while (getline(file, str)){ // read the input line by line
        for (const char c : str){ // iterate through each character in the line
            if (c=='('){
                soln1++;
            }
            else if (c==')'){
                soln1--;
            }
        }
    }
    std::cout<<"Santa's final floor: "<<soln1<<std::endl;
    std::cout<<"First time Santa reaches the basement: "<<soln2<<std::endl;
// floor now contains the final floor number
```

## Part 2 solution

In the second part of the problem, we need to determine the position of the first character in the input string that causes Santa to enter the basement (floor -1). We can modify our previous solution to keep track of the current floor and also check if it becomes -1 at any point. If it does, we can return the index of that character.

```cpp
// Update the previous snippet to 
// ... 
    while (getline(file, str)){
        for (const char c : str){
            if (c=='('){
                soln1++;
            }
            else if (c==')'){
                soln1--;
            }
            inp_counter++;
            if (soln1==-1 && soln2==0){
                soln2=inp_counter;
            }
        }
    }
    std::cout<<"Santa's final floor: "<<soln1<<std::endl;
    std::cout<<"First time Santa reaches the basement: "<<soln2<<std::endl;
```

## What I learned?

### Reading files in C++

In C++, we can read files using the `<fstream>` library. We create an `ifstream` object to read from a file, and we can use the `getline` function to read the file line by line. This allows us to process large files without loading the entire content into memory at once.

```cpp
#include <fstream>

int main() {
    std::ifstream file("input.txt");
    std::string str;
    while (getline(file, str)) {
        // Process the line
    }
    return 0;
}
```

### Iterating through characters in a string

In C++, we can iterate through each character in a string using a range-based for loop. This allows us to easily access each character and perform operations based on its value.

```cpp
std::string str = "(()())";
for (const char c : str) {
    if (c == '(') {
        // Do something for opening parenthesis
    } else if (c == ')') {
        // Do something for closing parenthesis
    }
}
```
