# Day 2

**Problem summary**: Given an input file containing dimensions of boxes, in the form `LxWxH`, calculate the total amount of wrapping paper needed to wrap all the boxes, and the total amount of ribbon needed to wrap all the boxes.

## The basics

Each line in the file is a string in the format `LxWxH`. Before we do any calculations, we need to parse this string to extract the length, width, and height of the box. We can do this by splitting the string on the 'x' character and converting the resulting substrings to integers.

```cpp
#include <iostream>
#include <sstream>
#include <vector>
// Function to split a string by a delimiter and convert the parts to integers
std::vector<int> split(std::string& s, const char delim){
    std::vector<int> result;
    std::stringstream ss (s); // Create a stringstream from the input string LxWxH
    std::string item;

    while (std::getline(ss, item, delim)){
        result.push_back(std::stoi(item)); // Convert the substring to an integer and add it to the result vector
    }
    return result;
}

```

## Part 1 solution -- Wrapping paper required

Once, we have the dimensions as integers, it is then easy to calculate the warpping paper needed for each box. The formula for the wrapping paper needed is: `2*l*w + 2*w*h + 2*h*l + min(l*w, w*h, h*l)`

```cpp
int get_area(std::vector<int> dims){
    int curr_area=0;
    int l=dims[0], w=dims[1], h=dims[2];
    std::vector<int> areas={l*w, w*h, l*h};
    int min_area=areas[0];

    for (int area:areas){
        if (area<min_area){
            min_area=area;
        }
        curr_area += 2*area;
    }
    return curr_area + min_area;
}

//...
int main(){
    // declare variables ...
    // ...
    while (std::getline(file, line)){
        dimensions = split(line, 'x');
        sheet_area += get_area(dimensions);
    }
    std::cout<<"Part 1: Required wrapping sheet area= "<<sheet_area<<std::endl;
```

## Part 2 solution -- Ribbon length required

The formula for the ribbon length needed is: `2*(min(l+w, w+h, h+l)) + l*w*h`

```cpp
int get_ribbon(std::vector<int> dims){
    int l=dims[0], w=dims[1], h=dims[2];
    std::vector<int> perims={2*(l+w), 2*(w+h), 2*(l+h)};
    int min_perim=perims[0];

    for (int perim:perims){
        if (perim<min_perim){
            min_perim=perim;
        }
    }
    return min_perim + (l*w*h);
}


//...
int main(){
    // declare variables ...
    // ...
    while (std::getline(file, line)){
        dimensions = split(line, 'x');
        ribbon_length += get_ribbon(dimensions);
    }
    std::cout<<"Part 2: Required ribbon length= "<<ribbon_length<<std::endl;
```

## What I learned?

### Declaring vectors in C++

In C++, you can declare a vector using the `std::vector` template class. You need to specify the type of elements that the vector will hold. For example, to declare a vector of integers, you can use:

```cpp
std::vector<int> myVector;
// and then you can add elements to the vector using the push_back method
myVector.push_back(10);
myVector.push_back(20);
```

This creates an empty vector that can hold integers. You can also initialize the vector with a specific size and default value:

```cpp
std::vector<int> myVector(5, 0); // Creates a vector of size 5, initialized with 0
```

### Using stringstream

The `std::stringstream` class in C++ is a part of the `<sstream>` header and is used for input and output operations on strings. It allows you to treat a string as if it were a stream, which can be useful for parsing and formatting strings.
To use `std::stringstream`, you can create an instance of it and then use the stream insertion (`<<`) and extraction (`>>`) operators to read from or write to the string. For example:

```cpp
#include <iostream>
#include <sstream>

int main() {
    std::string input = "10 20 30";
    std::stringstream ss(input);
    int a, b, c;

    // Extract integers from the stringstream
    ss >> a >> b >> c;

    std::cout << "Extracted values: " << a << ", " << b << ", " << c << std::endl;
    return 0;
}
```

In this example, we create a `std::stringstream` object `ss` initialized with the string "10 20 30". We then use the extraction operator (`>>`) to read the integers from the stringstream into the variables `a`, `b`, and `c`. Finally, we print the extracted values to the console.

