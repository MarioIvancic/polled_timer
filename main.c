// main.c

#include <stdio.h>
#include "polled_timer.h"
#include "polled_timer_test.h"


int main(int argc, char** argv)
{
    polled_timer_test_all();
    return 0;
}
