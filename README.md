# skyscrapper_solver
## TLDR
This project is about solving a skyscrapper puzzle. By given a 4X4 board, each grid represents a building, the number on it is the height of the building. Higher building will block the building behind depending on the view (left to right, top to bottom...). Contraints on each row and col represents the expected view.

Find a solution that suits the contraints for the 
The puzzle is to make sure:

1. No duplicate numbers in the same row/col;
2. Respect the constraints;
   
## Build & Run

build command example
```
cc -Wall -Wextra -Werror *.c
```

run command structure
```
./rush-01 "col1up col2up [...] col1down col2down [...] row1left row2left
[...] row1right row2right [...]" [a|v]
```

## Arguments

the argument is a string of numbers separated by spaces
each number represents the number of blocks that should be visible
from that position (cf. subject)

**example of a valid 4x4 input**:
```
"1 2 2 4 4 2 2 1 1 2 2 4 4 2 2 1"
```
**expected result**:
```
1 2 3 4
2 3 4 1
3 4 1 2
4 1 2 3
```
**example usage**:
```
./a.out "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
```