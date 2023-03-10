#include <iostream>
#define DEBUGGING
#ifdef DEBUGGING
#define SHOW_WHERE std::cout << __PRETTY_FUNCTION__ << " id:" << id << std::endl;
#else
#define SHOW_WHERE
#endif
