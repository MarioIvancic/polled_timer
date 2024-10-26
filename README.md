# polled_timer
The timer than needs to be polled to check for timeout event


# Building
Makefile is designed for building on Linux using gcc, gcov, lcov and genhtml. You can:

  * **make debug**     to make debug version
  * **make release**   to make release version
  * **make all**       to make debug and release versions
  * **make**           same as 'make all'
  * **make coverage**  to test line and function coverage
  * **make clean**     to clean working directory



# #defines for customization

  * **POLLED_TIMER_TIME_TYPE**
This will define integer type used for time values. Default is unsigned int


  * **POLLED_TIMER_TIME_FCN**
This will define function-like macro that will return current time.
If it is not defined then polled_timer_global_init() must be used
to set callback function used as time source.



# Polled timer API

```C
    typedef POLLED_TIMER_TIME_TYPE polled_timer_t;
```

Definition of timer type.

```C
    void polled_timer_global_init(POLLED_TIMER_TIME_TYPE (*time_fcn)(void));
```

If POLLED_TIMER_TIME_FCN is not defined this function is used to set pointer to
time source function. That function is used by the rest of functions.
If POLLED_TIMER_TIME_FCN is defined this function will not be defined that macro
will be used as time source function.


```C
    polled_timer_t polled_timer_set(POLLED_TIMER_TIME_TYPE timeout);
```

Set timeout and start a timer.


```C
    int_fast8_t polled_timer_is_timedout(polled_timer_t t);
    int_fast8_t polled_timer_expired(polled_timer_t t);
```

Test a timer for timeout event.


```C
    polled_timer_t polled_timer_now(void);
```

Set timer to current time start a timer. To check for expiration use polled_timer_expired_ex function.


```C
    int_fast8_t polled_timer_expired_ex(polled_timer_t t, POLLED_TIMER_TIME_TYPE timeout);
```

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

```C
    uint32_t get_monotonic_time_us(void);

    polled_timer_global_init(get_monotonic_time_us);

    polled_timer_t T = polled_timer_set(1000000);

    if (polled_timer_expired(T))
    {
        do_something();
    }
```

    Simple C example, explicit timeout

```C
    uint32_t get_monotonic_time_us(void);

    polled_timer_global_init(get_monotonic_time_us);

    polled_timer_t T = polled_timer_now();

    if (polled_timer_expired_ex(T, 1000000))
    {
        do_something();
    }
```

    Simple C++ example, implicit timeout

```C++
    extern "C" uint32_t get_monotonic_time_us(void);

    polled_timer_global_init(get_monotonic_time_us);

    PolledTimer T;
    T.set(1000000);

    if (T.expired())
    {
        do_something();
    }
```

    Simple C++ example, explicit timeout

```C++
    extern "C" uint32_t get_monotonic_time_us(void);

    polled_timer_global_init(get_monotonic_time_us);

    PolledTimer T;
    T.now();

    if (T.expired(1000000))
    {
        do_something();
    }
```