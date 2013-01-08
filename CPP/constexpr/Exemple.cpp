Note: I'm using the "gcc version 4.8.0 20120307 (experimental) (GCC)".

Since we like to know what's up under the hood, we investigated about how gcc optimizes the code with that new keyword.

Part 1: Constexpr impact on the binary

Here is a code snippet

#include <iostream>

constexpr uint32_t factorial(uint32_t n)
{
    return n > 0 ? n * factorial(n - 1) : 1;
}

constexpr uint32_t fib(uint32_t x)
{
    return (x <= 1) ? 1 : (fib(x - 1) + fib(x - 2));
}

void foo(uint32_t test)
{
    std::cout << test << std::endl;
}

int main()
{
    uint32_t a = fib(0xa);
    std::cout << std::hex << a << std::endl; //gives 0x59

    std::cout << fib(0xa) << std::endl; //gives 0x59

    foo(fib(0xc)); //gives 0xe9

    std::cout << factorial(0x5) << std::endl; //gives 0x78

    uint32_t b = factorial(0x6);
    std::cout << b << std::endl;//gives 0x2d0

    return EXIT_SUCCESS;
}

We compile this code with these switches "-std=c++0x -O3". Looking at the assembly code generated, we can see that gcc did evaluate some of the constexpr functions at compilation time:

... 
4007fb: be 59 00 00 00 mov esi,0x59
... 
400828: bf 0a 00 00 00 mov edi,0xa
40082d: e8 de 01 00 00 call 400a10 
...
400846: bf 0c 00 00 00 mov edi,0xc
40084b: e8 c0 01 00 00 call 400a10 
400850: 89 c7          mov edi,eax
400852: e8 49 01 00 00 call 4009a0 
...
400857: be 78 00 00 00 mov esi,0x78
...
40086e: be d0 02 00 00 mov esi,0x2d0
...

But not all of them are converted, the second fib() call at

0x40082d //std::cout << fib(0xa) << std::endl

isn't.

This is weird, we could think that gcc couldn't solve it at compilation time, but it has an integer value and it has the exact same argument (0xa) as the first fib() call (and also doesn't exceed the -fconstexpr-depth of 512 by default) :

uint32_t a = fib(0xa);

We thought that may be it was because the ostream::operator<< comes from the libstdc++ so gcc may not optimize it as if it was a function from the program, but even when calling fib() as parameter of foo()

foo(fib(0xc));

it didn't evaluated it at compile time.

It's a pretty weird comportment we didn't find any reliable explanation. Plus the calls to factorial() are all processed at compilation time, even the ones that are in parameter of ostream::operator<<. So may be because fib() calls himself twice on the return it makes it too complicated to evaluate it at compile time.

Part 2: Is constexpr useless with gcc ?

The standard put some restrictions on the constexpr keyword (only a return inside the function, no incrementation, ...), but the gcc optimizations are so powerful that even if the code contains more than one line or incrementation it will sometimes evaluate it a compile time and then set the result in the assembly avoiding a function call and processing.

Another funny thing is that if you try compiling the same code snippet as in the first part without the constexpr in the function declarations, the calls to factorial() are all evaluated at compilation time, but the calls to fib() aren't.

Conclusion:

So constexpr has its uses, but for the optimization part gcc optimizations are so good, that I think in most cases it would be optimized even without it. But for code portability it's might be useful to specify it.

