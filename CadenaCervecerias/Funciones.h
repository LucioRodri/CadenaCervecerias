#pragma once
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int random(int limite_inferior, int limite_superior);
bool operator==(tm& T1, tm& T2);
bool operator!=(tm& T1, tm& T2);
bool operator<(tm& derecha, tm& izquierda);
bool operator>(tm& derecha, tm& izquierda);