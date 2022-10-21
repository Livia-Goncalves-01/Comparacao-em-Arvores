#ifndef SHARED_HPP
#define SHARED_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <iostream>
#include <string>
#include <ctime>
#include <ratio>
#include <chrono>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;
using namespace chrono;

typedef struct Record {
	float key;
	int value;
} Record;

#endif