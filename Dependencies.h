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