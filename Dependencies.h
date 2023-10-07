#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector> 
#include <map>
#include <list>
#include <algorithm>
#include <cmath>
#include <memory>
#include <chrono>

using namespace std;

typedef double TPrecisionInfo;

#define RAD_MULT 1.695 
#define DENSITY 1000.0
#define STIFF_PRESS 3.0
#define STIFF_COLL 30000.0
#define DAMPING 128.0
#define VISCOSITY 0.4
#define P_SIZE 0.0002
#define T_STEP 1000.0


#define YMIN -0.08
#define YMAX 0.1

#define XMIN -0.065
#define XMAX 0.065

#define ZMIN -0.065
#define ZMAX 0.065

#define INIT_GX 0.0
#define INIT_GY 9.8
#define INIT_GZ 0.0

typedef size_t TBlockIndex;

#define MAX(a,b) ((((a)>(b)))?(a):(b))