
#include "my.h"

char *read_map(char *path)
{
    struct stat info;
    int fd = open(path, O_RDONLY);
    if (fd == -1)
        return NULL;
    stat(path, &info);
    char *buff = (char *)malloc(sizeof(char) * info.st_size + 1);
    int rd = read(fd, buff, info.st_size);
    if (rd == 0) return NULL;
    if (rd == -1) return (NULL);
    buff[rd] = '\0';
    return buff;
}

int map_height(char *buff)
{
    int height = get_nbr(buff);
    if (height == -1) return (-1);
    return height;
}

int num_cols(char *buff)
{
    int i = 0, n = 0;
    for (; buff[i] != '\n'; i++); i++;
    for (n = i; buff[n] != '\n'; n++);
    return (n - i);
}

void display(char **map)
{
    for (int i = 0; map[i]; i++) {
        my_putstr(map[i]);
        my_putstr("\n");
    }
}

int **init_tab(char *buff, bsq_t *b)
{
    int lines = map_height(buff), cols = num_cols(buff);
    int i = 0, j = 0, a = 0, mal = 0; b->nb_char = 0; b->nb_o = 0;
    int **map = (int **)malloc(sizeof(int *) * (lines + 1));
    b->map = (char **)malloc(sizeof(char *) * (lines + 1));
    for (; buff[a] != '\n'; a++); a++;
    for (; i < lines; i++) {
        map[i] = (int *)malloc(sizeof(int) * cols + 1);
        b->map[i] = (char *)malloc(sizeof(char) * cols + 1);
        for (j = 0; buff[a] != '\n' && buff[a] != '\0'; j++, a++) {
            b->map[i][j] = buff[a]; b->nb_char++;
            map[i][j] = (buff[a] == '.') ? 1 : 0;
            b->map[i][j] == 'o' ? b->nb_o++ : 0;
        } a++;
        b->map[i][j] = '\0';
    }
    b->lines = lines; b->cols = cols;
    b->map[i] = NULL; map[i] = NULL;
    free(buff);
    return map;
}
