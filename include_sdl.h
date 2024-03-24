#ifdef _WIN32a
#include "SDL.h"   /* All SDL App's need this */
#else
#include<linux/time.h>
#define __timespec_defined 1
#define __timeval_defined 1
#define __itimerspec_defined 1
#include "SDL2/SDL.h"
#endif