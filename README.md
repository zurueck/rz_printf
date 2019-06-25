A simple printf() for embedded system. 
Originally, this small piece of code is write for myself and my colleagues.
The main goal is to make code size as small as possible to fit in MCUs.
Right now(v0.0.1) the source code is based on ARM Cortex M0 processer. 
Obviously there are still a lot to work on.

## Feature
- No dependency.  
- No additional library required.

## How to use
Copy rz_printf.c .h to your project and set your including. 
Implement your own **_void rz_putchar(char ch)_** function for low level system out. (or do it by register in callback function)
There are two functions availiable:  
```C
int rz_printf ( const char * format, ... );
int rz_vsprintf(char *str, const char *format, char* arg);
```

## Code Size Comparison
Working on it

## Todo
Please refer to the github Project Board

## License
The MIT License

