// polled_timer.c
// general purpose polled timer implementation
// Mario Ivancic, 2022
// Version 0.1.1 2022-03-14   Initial implementation
// Version 0.1.2 2022-03-17   See polled_timer.h for details
// Version 0.2.0 2023-04-29   See polled_timer.h for details

#include "polled_timer.h"

#if !defined(POLLED_TIMER_TIME_FCN)

// global get_time function pointer and timer list
POLLED_TIMER_TIME_TYPE (*polled_timer_get_time_)(void);

#endif // !defined(POLLED_TIMER_TIME_FCN)
