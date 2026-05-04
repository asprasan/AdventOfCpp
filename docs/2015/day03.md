# Day 3

**Problem summary**: Santa is delivering presents to an infinite two-dimensional grid of houses. He moves based on a series of directions (^, v, <, >) and we need to determine how many unique houses receive at least one present. In part 2, Santa is joined by Robo-Santa, and they take turns moving based on the same series of directions. We need to determine how many unique houses receive at least one present from either Santa or Robo-Santa.

## The basics

To solve this problem, we need to keep track of the positions of Santa and Robo-Santa as they move based on the given directions. We can use a set to store the unique positions of the houses that receive presents. We will use tuples to represent the coordinates of the houses, where (x, y) represents the position on the grid.

We can define tuples as follows:

```cpp
#include <tuple>
std::set<std::tuple <int, int>> house_grid1, house_grid2; //define the grid of visited homes
std::tuple<int, int> house={0,0}; // define the santa's location for part 1
std::tuple<int, int> santa_house={0,0}, robo_house={0,0}; //define the santa's or robot's location for part 2
```

### Defining a function to move Santa and Robo-Santa

We can define a function that takes the current position and the direction as input and returns the new position after moving in that direction. The function can be defined as follows:

```cpp
std::tuple<int, int> next_house(std::tuple<int, int> house, const char c){
    // Compute the next house visited by Santa/robot for delivering gifts
    // If < move Left
    // If > move Right
    // If ^ move Up
    // If v move Down
    if (c=='<'){
        std::get<0>(house)--;
    }
    else if (c=='>'){
        std::get<0>(house)++;
    }
    else if (c=='^'){
        std::get<1>(house)++;
    }
    else if (c=='v'){
        std::get<1>(house)--;
    }
    return house;
}

```

## Part 1 solution -- Unique houses visited by Santa

At each step, we will update Santa's position based on the direction and add the new position to the set of visited houses. Then for each addition, we can update the counter of unique houses visited.

```cpp
while (std::getline(file, line)){
        for (const char c: line){
            // solution for part 1
            house=next_house(house, c);
            if (!house_grid1.count(house)){
                soln1++; //update counter of unique houses visited
                house_grid1.insert(house);
            }
        }
}
std::cout<<"Solution for part 1: "<<soln1<<std::endl;
```

## Part 2 solution -- Unique houses visited by Santa and Robo-Santa

Here, although, we need to keep track of two positions, one for Santa and one for Robo-Santa, we just need one grid to keep track of the unique houses visited by either of them. However, we need a different grid than the one used in part 1.

```cpp
while (std::getline(file, line)){
    for (const char c: line){
        // solution for part 2
        if (counter%2==0){
            // logic for santa's movements
            santa_house=next_house(santa_house, c);
            if (!house_grid2.count(santa_house)){
                soln2++;
                house_grid2.insert(santa_house);
            }
        }
        else if (counter%2==1){
            // logic for robot's movements
            robo_house = next_house(robo_house, c);
            if (!house_grid2.count(robo_house)){
                soln2++;
                house_grid2.insert(robo_house);
            }
        }
        counter++; // used to check if it's santa's or robot's turn to move
        }
    }
std::cout<<"Solution for part 2: "<<soln2<<std::endl;
```

## What I learned?

### Declaring a tuple in C++

Tuples can be declared using the `std::tuple` template. For example, to declare a tuple that holds two integers, we can use:

```cpp
#include <tuple>
std::tuple<int, int> my_tuple;
std::get<0>(my_tuple) = 5; // Accessing the first element
std::get<1>(my_tuple) = 10; // Accessing the second element
```

We can also store tuples with different data types, such as:

```cpp
std::tuple<int, std::string> my_tuple;
std::get<0>(my_tuple) = 42; // Accessing the first element
std::get<1>(my_tuple) = "Hello"; // Accessing the second element
// can also initialize directly
std::tuple<int, std::string> my_tuple={42, "Hello"};
```

### Using a set to store unique values

A set is a data structure that stores unique values. In C++, we can use the `std::set` container to store unique tuples representing the positions of the houses. For example:

```cpp
#include <set>
std::set<std::tuple<int, int>> house_grid;
std::tuple<int, int> house = {0, 0};
house_grid.insert(house); // Insert a house into the set
if (house_grid.count(house)) {
    // This will return true if the house is already in the set
}
```

We could have also used a `std::vector` to store the visited houses. However, checking for the presence of a house in a vector would require iterating through the entire vector, which has a time complexity of O(n). In contrast, using a set allows us to check for the presence of a house in O(log n) time, making it more efficient for this problem.
