BasicTimer
==========

A simple, portable timer
------------------------

For some reason it is rather difficult to obtain elapsed milliseconds in C++. You can use time(), but that only has a resolution of 1 second. You can use clock() but then I/O operations which do not use clock cycles will report an ellapsed time of 0. Furthermore this is OS dependent. Consider the following example:
```
std::clock_t tick = std::clock();

// Wait for user input.
std::string input;
std::cin >> input;

std::clock_t now = std::clock();
int milliseconds = float(now - tick) / CLOCKS_PER_SEC * 1000; 
```
On Windows this example will work as intended, and `milliseconds` will hold the number of milliseconds spent waiting for user input. However in Linux and OS X IO operations do not use clock cycles and `milliseconds` will be near 0.

BasicTimer provides a portable solution using the timeb struct and ftime.
