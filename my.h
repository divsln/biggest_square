/*
** EPITECH PROJECT, 2022
** mylib
** File description:
** mylib
*/
#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <string.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdbool.h>
typedef struct b_s_q {
    char **map;
    int y, x, bsq;
    int lines, cols;
    int nb_char, nb_o;
}bsq_t;
char *read_map(char *path);
int num_cols(char *path);
int signes(char *str);
void free_map(int **map);
int map_height(char *buff);
int square_size(char **map, int rows, int cols, int size);
bsq_t *square_finder(int **map, int rows, int cols, bsq_t *b);
void verify_bsq(int min, bsq_t *b, int i, int j);
int find_min(int **map, int i, int j);
bsq_t *one_line_bsq(bsq_t *b, int cols);
bsq_t *one_col_bsq(bsq_t *b, int rows);
int signes(char *str);
int get_nbr(char *str);
int **init_tab(char *buff, bsq_t *b);
void display(char **map);
void free_tab(char **map);
void my_putstr(char *str);
#endif
