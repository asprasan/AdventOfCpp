# Day 4

**Problem summary**: We have to help Santa mining some AdventCoins. To do that, we need to find the lowest positive integer (starting with 1) that, when combined with a secret key and hashed using MD5, produces a hash that starts with a certain number of zeroes.

## Computing md5 checksum of a string

Here, we don't implement the MD5 algorithm ourselves. We use the functions `md5` from [here](https://www.zedwood.com/article/cpp-md5-function). However, for completeness, let's see how the MD5 algorithm works in general.

In MD5, we take the input message and process it in 512-bit blocks. The algorithm consists of four rounds of operations, each round involving a series of mathematical functions and bitwise operations. The output is a 128-bit hash value, which is typically represented as a 32-character hexadecimal string. The MD5 algorithm is designed to be fast and efficient, making it suitable for hashing large amounts of data. However, it is important to note that MD5 is not considered secure for cryptographic purposes, as it is vulnerable to collision attacks. Therefore, it is recommended to use stronger hashing algorithms like SHA-256 or SHA-3 for secure applications.

## Part 1 solution -- lowest integer whose MD5 begins with 00000 when combined with a secret key

Here, all we need to do is to iterate through positive integers, concatenate each integer with the secret key, compute the MD5 hash of the resulting string, and check if the hash starts with "00000". We continue this process until we find the lowest integer that satisfies this condition.

```cpp
int main(){
    // ... declarations
    while (1){
        std::string counter_str=std::to_string(counter);
        std::string md5_input = secret + counter_str;

        md5_output = md5(md5_input);
        if (md5_output.substr(0,5) == "00000"){
            std::cout<<"Solution for part 1: "<<counter<<std::endl;
            break;
        }
        counter++;
    }
}
```

## Part 2 solution -- lowest integer whose MD5 begins with 000000 when combined with a secret key

The only diference between part 1 and part 2 is that we need to check if the hash starts with "000000" instead of "00000". The implementation is similar to part 1, but we change the condition in the if statement accordingly.

```cpp
int main(){
    // ... declarations
    while (1){
        std::string counter_str=std::to_string(counter);
        std::string md5_input = secret + counter_str;
        md5_output = md5(md5_input);
        // std::cout<<"Solution for part 2: "<<md5_input<<std::endl;
        if (md5_output.substr(0,6) == "000000"){
            std::cout<<"Solution for part 2: "<<counter<<std::endl;
            break;
        }
        counter++;
    }
}
```

## What I learned?

### Including external libraries in C++

In C++, we can include external libraries by using the `#include` directive. For example, to include the MD5 library, we can use `#include "md5.h"`. This allows us to use the functions defined in the MD5 library in our code. We also need to make sure that the library is properly linked during compilation, which may involve adding the library file to our project and specifying it in the compiler settings.

### String manipulation in C++

1. Concatenation: We can concatenate strings using the `+` operator or the `append()` method. For example, `std::string result = str1 + str2;` or `str1.append(str2);`.
2. Substring: We can extract a substring from a string using the `substr()` method. For example, `std::string sub = str.substr(0, 5);` will give us the first 5 characters of the string `str`.
3. Comparison: We can compare strings using the `==` operator or the `compare()` method. For example, `if (str1 == str2) { ... }` or `if (str1.compare(str2) == 0) { ... }`.
