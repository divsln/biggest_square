
#include "my.h"

int signes(char *str)
{
    int sig = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            sig *= -1;
        if (str[i] == '+')
            sig *= 1;
        if (str[i] >= '1' && str[i] <= '9')
            return sig;
    }
    return sig;
}

int get_nbr(char *str)
{
    int nbr = 0, sig = signes(str);
    bool neg = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = (nbr * 10) + (str[i] - 48);
        }
        if (str[i] != '\n') {
            !(str[i] >= '0' && str[i] <= '9') ? -1 : 0;
        }
    }
    nbr *= sig;
    return nbr;
}
