<h1 align="center">42 Cursus: ft_printf</br></br>
  <sup><sup><sup><sup>Because ft_putnbr() and ft_putstr() aren’t enough.</sup></sup></sup></sup></h1>
  
:dart: Goal of the project
> Write a library that contains ft_printf(), a function that will mimic the original printf()

:thinking: What need to know to complete this project
> – Knowledge of how to print number and convert in decimal and hexadecimal using write()</br>
> – Knowledge of how to print chars and strings using write()</br>
> – Variadic functions in C</br>

### **Mandatory Part**
> handle the following conversions: cspdiuxX%.</br>
> • %c Prints a single character.</br>
> • %s Prints a string (as defined by the common C convention).</br>
> • %p The void * pointer argument has to be printed in hexadecimal format.</br>
> • %d Prints a decimal (base 10) number.</br>
> • %i Prints an integer in base 10.</br>
> • %u Prints an unsigned decimal (base 10) number.</br>
> • %x Prints a number in hexadecimal (base 16) lowercase format.</br>
> • %X Prints a number in hexadecimal (base 16) uppercase format.</br>
> • %% Prints a percent sign.</br>

### **Bonus Part**
> • # flag. Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.
> • " " (space) flag. If no sign is going to be written, a blank space is inserted before the value.
> • + flag. Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers.
> • 0 flag. Left-pads the number with zeroes (0) instead of spaces when padding is specified.
> • - flag. Left-justify within the given field width.
> • . flag. Make number and string to be precised with specified length and width.
> Cr. Thanks to https://cplusplus.com/reference/cstdio/printf/

</br>

|**Function name**|**ft_printf**|
|:---         |:---           |
|Prototypes|int ft_printf(const char *, ...);|
|Turn in files|Makefile, *.h, */*.h, *.c, */*.c|
|External Functions|rmalloc, free, write, va_start, va_arg, va_copy, va_end|
|Libft authorized|Yes|

