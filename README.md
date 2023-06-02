# biggest_square
A program that finds the biggest square composed of '.'s possible.
After cloning the repository type: make
A binary name bsq will be generated
For usage, try : ./bsq with a map of your choice.
Some maps are available in the repository but you can create other. A map is caracterised by '.'s as empty spaces and 'o's as obstacles with each lines having the same length.
After the execution of the program, a map will be printed but this time with 'x's showing the location of the biggest square.
I used an algorithm that implied creating a copy of the map passed as argument but this time as an array of integers when I founded on each case what was the minimum size of square possible on that case and changed the value of the integer at that particular case.
The algorrithm's name is Minesweeper algorithm.
