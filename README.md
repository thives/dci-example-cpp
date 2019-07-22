DCI Example C++
===========

A simple example application using C++20 core language features. The goal is to attempt to follow the DCI paradigm. 
(http://fulloo.info/)

The example is inspired by the money transfer algorithm example. 
(http://fulloo.info/Examples/C++Examples/Account1/)

The C++20 core features used are the "Constraints and concepts". Note that at the time of writing this GCC only supports the TS version of this feature and as such that is what is used in this example as well.
(https://en.cppreference.com/w/cpp/language/constraints)

## Compilation under linux

At the time of writing GCC will compile this project with the following command:

```
g++ -std=c++2a -fconcepts main.cpp checkingaccount.cpp savingsaccount.cpp logger.cpp -o moneytransferexample
```

## Running under linux

```
./moneytransferexample
```
