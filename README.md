*This project has been created as part of the 42 curriculum by jsantini*


| Description |
|-------------|


Push-Swap is a project that takes a list of integers in a stack (ie: 4 8 2 6) and sort them displaying the command at the same time. The goal is to sort them in a restricted number of 
move and having only certain commmands to move the numbers in the stack.

The commands here are:
pb (push the first element of a to stack b), pa (push the first element of b to stack a)

sa (swap the first two element of stack a), sb (swap the first two element of stack b), ss (do sa and sb at the same time)

ra (take the first element of a and put it at the end of stack a), rb (take the first element of b and put it at the end of stack b), rr (do ra and rb at the same time)

rra (take the last element of a and put it on top of a), rrb (take the last element of b and put it on top of b), rrr (do rra and rrb at the same time)



| Instruction |
|-------------|


_Instalation_:

> git clone git@github.com:tales77100/push_swap.git; cd push_swap

_Compiling_:

> make

_Usage_:

> ./push_swap "any list of number" (ie: 1 3 2 4 5 or "1 8 5 6 9 7")


| Resources |
|-----------|


-youtube videos about various algorithm as well as push-swap oriented videos

-IA was use to help understand said algorithm


| Algorithm |
|-----------|


-from 1 to 15, i used my own algorithm (a refined naive aproche)

-from 16 to infinity, i used the radix algorithm using sorted indexes as replacement for numbers to minimize the number of moves (ie: 1 2 727 7, 727 is not 727 in my algorithm its 3)
i check bit by bit the sorted index to put all the number in metaphorical box (aka stack b) and repeat to byte-max (aka size of list - 1 in binary).

