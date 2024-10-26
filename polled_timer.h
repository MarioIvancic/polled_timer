// polled_timer.h
// general purpose polled timer implementation
// Mario Ivancic, 2022
// Version 0.1.1 2022-03-14   Initial implementation
// Version 0.1.2 2022-03-17
// C API extended with polled_timer_now() and polled_timer_expired_ex(polled_timer_t, POLLED_TIMER_TIME_TYPE).
// C++ API extended with now() and expired(POLLED_TIMER_TIME_TYPE).
// Return type from API is changed from char to int_fast8_t.
// Removed macros POLLED_TIMER_CRITICAL_SECTION_START and POLLED_TIMER_CRITICAL_SECTION_END.
// If there is some non-atomic operations in implementation and the same timer is used in interrupt and in non-interrupt
// context than operation on that timer in non-interrupt context must be protected from interrupting.
// Version 0.2.0 2023-04-29
// All C inline functions are now static inline.
// Added unit test framework Unity and some unit tests.

#ifndef POLLED_TIMER_H_INCLUDED
#define POLLED_TIMER_H_INCLUDED

#include <stdint.h>     // for int_fast8_t

// macros for customization
//#define POLLED_TIMER_TIME_TYPE   unsigned
//#define POLLED_TIMER_TIME_FCN()    now

/**
    #defines for customization

    POLLED_TIMER_TIME_TYPE

This will define integer type used for time values. Default is unsigned int


    POLLED_TIMER_TIME_FCN

This will define function-like macro that will return current time.
If it is not defined then polled_timer_global_init() must be used.



    Polled timer API

    typedef POLLED_TIMER_TIME_TYPE polled_timer_t;

Definition of timer type.


    void polled_timer_global_init(POLLED_TIMER_TIME_TYPE (*time_fcn)(void));

If POLLED_TIMER_TIME_FCN is not defined this function is used to set pointer to
time source function. That function is used by the rest of functions.
If POLLED_TIMER_TIME_FCN is defined this function will not be defined that macro
will be used as time source function.



    polled_timer_t polled_timer_set(POLLED_TIMER_TIME_TYPE timeout);

Set timeout and start a timer.



    int_fast8_t polled_timer_is_timedout(polled_timer_t t);
    int_fast8_t polled_timer_expired(polled_timer_t t);

Test a timer for timeout event.



    polled_timer_t polled_timer_now(void);

Set timer to current time start a timer. To check for expiration use polled_timer_expired_ex function.



    int_fast8_t polled_timer_expired_ex(polled_timer_t t, POLLED_TIMER_TIME_TYPE timeout);

Test a timer for timeout event where timeout is explicit.



We are using free running timer/counter as time source so all counter values forms a circle.
For instance, on 8-bit counter we will have 0, 1, 2, .., 253, 254, 255, 0, 1, ...
Timer current time and timer time of timeout (now() + timeout) are on the same circle.
All operations on timer values are done using modular arithmetic, so we can't tell which is
lower or higher, we can only calculate the distance between time points.
The distance D between time T and current time C is: D = (C - T) where D, C and T are all
of some unsigned integer type.

So, we must define some threshold value H so that for all distances lower than H timer is
expired and for distances higher or equal to H timer is active.

If H is big we can have longer timeout value but shorter time window for timer expiration
detection so it can be missed.

If timer period is P (for instance 65536 for 16-bit timer) then best option is to set H = P / 2

In this code POLLED_TIMER_MAX_TIMEOUT has the role of threshold H and it is set to
( ( (POLLED_TIMER_TIME_TYPE) -1 ) / 2 ).

There is no flags in the timer object so timer is stateless. If you set a timer to some timeout
value, as time pass by polled_timer_expired() will at first return false, then after some time
true, then after some time false, and so on.
You can't start or stop a timer, it is always running as long as you test it.
If you want to "stop" it just stop testing it, and don't forget to set it again later.


    Simple C example, implicit timeout

    uint32_t get_monotonic_time_us(void);

    polled_timer_global_init(get_monotonic_time_us);

    polled_timer_t T = polled_timer_set(1000000);

    if (polled_timer_expired(T))
    {
        do_something();
    }


    Simple C example, explicit timeout

    uint32_t get_monotonic_time_us(void);

    polled_timer_global_init(get_monotonic_time_us);

    polled_timer_t T = polled_timer_now();

    if (polled_timer_expired_ex(T, 1000000))
    {
        do_something();
    }


    Simple C++ example, implicit timeout

    extern "C" uint32_t get_monotonic_time_us(void);

    polled_timer_global_init(get_monotonic_time_us);

    PolledTimer T;
    T.set(1000000);

    if (T.expired())
    {
        do_something();
    }


    Simple C++ example, explicit timeout

    extern "C" uint32_t get_monotonic_time_us(void);

    polled_timer_global_init(get_monotonic_time_us);

    PolledTimer T;
    T.now();

    if (T.expired(1000000))
    {
        do_something();
    }
*/


#ifndef POLLED_TIMER_TIME_TYPE
    #define POLLED_TIMER_TIME_TYPE unsigned int
#endif // POLLED_TIMER_TIME_TYPE

#define POLLED_TIMER_MAX_TIMEOUT    ( ( (POLLED_TIMER_TIME_TYPE) -1) / 2U + 1U )


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus


// ############     simple polling API, no callbacks     ############


typedef POLLED_TIMER_TIME_TYPE polled_timer_t;

#if defined(POLLED_TIMER_TIME_FCN)

extern POLLED_TIMER_TIME_TYPE POLLED_TIMER_TIME_FCN ();

#define POLLED_TIMER_TIME_FCN_ POLLED_TIMER_TIME_FCN

#else

// global get_time function pointer and timer list
extern POLLED_TIMER_TIME_TYPE (*polled_timer_get_time_)(void);
#define POLLED_TIMER_TIME_FCN_() polled_timer_get_time_()

// initialize global timer data and set time function
static inline void polled_timer_global_init(POLLED_TIMER_TIME_TYPE (*time_fcn)(void))
{
    polled_timer_get_time_ = time_fcn;
}

#endif // !defined(POLLED_TIMER_TIME_FCN)


// set timer to fire for timeout from now
static inline polled_timer_t polled_timer_set(POLLED_TIMER_TIME_TYPE timeout)
{
    POLLED_TIMER_TIME_TYPE now = POLLED_TIMER_TIME_FCN_();
    return timeout + now;
}


// set timer to current time (to be used by polled_timer_expired_ex)
static inline polled_timer_t polled_timer_now(void)
{
    return POLLED_TIMER_TIME_FCN_();
}


// test for timeout event
static inline int_fast8_t polled_timer_expired(polled_timer_t t)
{
    POLLED_TIMER_TIME_TYPE diff = t - POLLED_TIMER_TIME_FCN_();
    if( diff > POLLED_TIMER_MAX_TIMEOUT ) return 1;
    return 0;
}

// alias for polled_timer_expired()
static inline int_fast8_t polled_timer_is_timedout(polled_timer_t t)
{
    return polled_timer_expired(t);
}


// test for timeout event when timeout is explicit
// in this case you mush use: t = polled_timer_now();
// timeout should not be 0
static inline int_fast8_t polled_timer_expired_ex(polled_timer_t t, POLLED_TIMER_TIME_TYPE timeout)
{
    POLLED_TIMER_TIME_TYPE diff = POLLED_TIMER_TIME_FCN_() - t;
    if( diff >= timeout ) return 1;
    return 0;
}


#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef __cplusplus

// ############     C++ class for polled timer     ############

class PolledTimer
{
private:
    polled_timer_t timer_;

public:

    inline void set(POLLED_TIMER_TIME_TYPE timeout)
    {
        timer_ = polled_timer_set(timeout);
    }

    inline void now()
    {
        timer_ = polled_timer_now();
    }

    inline int_fast8_t is_timedout() const
    {
        return polled_timer_is_timedout(timer_);
    }

    inline int_fast8_t expired() const
    {
        return polled_timer_is_timedout(timer_);
    }

    inline int_fast8_t expired(POLLED_TIMER_TIME_TYPE timeout) const
    {
        return polled_timer_expired_ex(timer_, timeout);
    }

    inline polled_timer_t value() const
    {
        return timer_;
    }

};

#endif // __cplusplus


#endif // POLLED_TIMER_H_INCLUDED

