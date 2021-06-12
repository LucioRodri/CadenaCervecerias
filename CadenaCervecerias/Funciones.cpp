#include "Funciones.h"

int random(int limite_inferior, int limite_superior)
{
    int random = rand() % limite_superior + limite_inferior;
    return random;
}
