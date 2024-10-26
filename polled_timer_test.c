// polled_timer_test.c

#include "polled_timer_test.h"
#include "polled_timer.h"
#include "monotonic_time.h"
#include "unity.h"
#include <stdio.h>
#include <string.h>

void test_polled_timer_now(void);
void test_polled_timer_set(void);
void test_polled_timer_expired_0(void);
void test_polled_timer_expired_1(void);
void test_polled_timer_expired_2(void);
void test_polled_timer_expired_3(void);
void test_polled_timer_expired_ex_0(void);
void test_polled_timer_expired_ex_1(void);
void test_polled_timer_expired_ex_2(void);
void test_polled_timer_expired_ex_3(void);
void test_polled_timer_expired_ex_4(void);


void setUp(void)
{
    // set stuff up here
    polled_timer_global_init(get_monotonic_time);
}

void tearDown(void)
{
    // clean stuff up here
}


int polled_timer_test_all(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_polled_timer_now);
    RUN_TEST(test_polled_timer_set);
    RUN_TEST(test_polled_timer_expired_0);
    RUN_TEST(test_polled_timer_expired_1);
    RUN_TEST(test_polled_timer_expired_2);
    RUN_TEST(test_polled_timer_expired_3);
    RUN_TEST(test_polled_timer_expired_ex_0);
    RUN_TEST(test_polled_timer_expired_ex_1);
    RUN_TEST(test_polled_timer_expired_ex_2);
    RUN_TEST(test_polled_timer_expired_ex_3);
    RUN_TEST(test_polled_timer_expired_ex_4);
    return UNITY_END();
}


void test_polled_timer_now(void)
{
    uint32_t E;
    polled_timer_t t;

    E = 0;
    set_monotonic_time(E);
    t = polled_timer_now();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 1;
    set_monotonic_time(E);
    t = polled_timer_now();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 2;
    set_monotonic_time(E);
    t = polled_timer_now();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 0x7FFFFFFFU;
    set_monotonic_time(E);
    t = polled_timer_now();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 0x80000000U;
    set_monotonic_time(E);
    t = polled_timer_now();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 0x80000001U;
    set_monotonic_time(E);
    t = polled_timer_now();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 0xFFFFFFFEU;
    set_monotonic_time(E);
    t = polled_timer_now();
    TEST_ASSERT_EQUAL_INT32(E, t);

    E = 0xFFFFFFFFU;
    set_monotonic_time(E);
    t = polled_timer_now();
    TEST_ASSERT_EQUAL_INT32(E, t);
}


void test_polled_timer_set(void)
{
    uint32_t now = 0;
    uint32_t T = 1;
    uint32_t E;
    polled_timer_t t;

    now = 0;
    set_monotonic_time(now);

    T = 0;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 1;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 2;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x7FFFFFFU;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x80000000U;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x80000001U;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0xFFFFFFFEU;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0xFFFFFFFFU;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);


    now = 0x7FFFFFFFU;
    set_monotonic_time(now);

    T = 0;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 1;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 2;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x7FFFFFFU;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x80000000U;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x80000001U;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0xFFFFFFFEU;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0xFFFFFFFFU;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    now = 0xFFFFFFFFU;
    set_monotonic_time(now);

    T = 0;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 1;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 2;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x7FFFFFFU;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x80000000U;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0x80000001U;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0xFFFFFFFEU;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);

    T = 0xFFFFFFFFU;  E = now + T;
    t = polled_timer_set(T);
    TEST_ASSERT_EQUAL_INT32(E, t);
}



void test_polled_timer_expired_0(void)
{
    uint32_t T1 = 0;
    uint32_t T2;
    uint32_t TO;
    polled_timer_t t;
    int_fast8_t r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 0

    TO = 0;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);


    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);
}


void test_polled_timer_expired_1(void)
{
    uint32_t T1 = 0x7FFFFFFFU;
    uint32_t T2;
    uint32_t TO;
    polled_timer_t t;
    int_fast8_t r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 0

    TO = 0;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);


    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);
}


void test_polled_timer_expired_2(void)
{
    uint32_t T1 = 0x80000000U;
    uint32_t T2;
    uint32_t TO;
    polled_timer_t t;
    int_fast8_t r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 0

    TO = 0;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);


    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);
}


void test_polled_timer_expired_3(void)
{
    uint32_t T1 = 0xFFFFFFFFU;
    uint32_t T2;
    uint32_t TO;
    polled_timer_t t;
    int_fast8_t r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 0

    TO = 0;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);


    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t = polled_timer_set(TO);

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired(t);
    TEST_ASSERT_TRUE(r);
}


void test_polled_timer_expired_ex_0(void)
{
    uint32_t T1;
    uint32_t T2;
    polled_timer_t t;
    int_fast8_t r;

    // testing for expired timer for timeout 0 when time moves from T1 to T2
    // if should be expired for any times

    // start time = 0
    T1 = 0;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);


    // start time = 0x7FFFFFFFU
    T1 = 0x7FFFFFFFU;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    // start time = 0x80000000U
    T1 = 0x80000000U;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    // start time = 0xFFFFFFFFU
    T1 = 0xFFFFFFFFU;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, 0);
    TEST_ASSERT_TRUE(r);
}



void test_polled_timer_expired_ex_1(void)
{
    uint32_t T1 = 0;
    uint32_t T2;
    uint32_t TO;
    polled_timer_t t;
    int_fast8_t r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);
}


void test_polled_timer_expired_ex_2(void)
{
    uint32_t T1 = 0x7FFFFFFFU;
    uint32_t T2;
    uint32_t TO;
    polled_timer_t t;
    int_fast8_t r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);
}



void test_polled_timer_expired_ex_3(void)
{
    uint32_t T1 = 0x80000000U;
    uint32_t T2;
    uint32_t TO;
    polled_timer_t t;
    int_fast8_t r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);
}



void test_polled_timer_expired_ex_4(void)
{
    uint32_t T1 = 0xFFFFFFFFU;
    uint32_t T2;
    uint32_t TO;
    polled_timer_t t;
    int_fast8_t r;

    // testing for expired timer for timeout time TO when time moves from T1 to T2

    // test for timeout 1

    TO = 1;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);


    // test for timeout 0x7FFFFFFF

    TO = 0x7FFFFFFF;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    // test for timeout 0x80000000U

    TO = 0x80000000U;
    set_monotonic_time(T1);
    t = polled_timer_now();

    T2 = T1 + 0;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 1;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 2;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x7FFFFFFFU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_FALSE(r);

    T2 = T1 + 0x80000000U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000001U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0x80000002U;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);

    T2 = T1 + 0xFFFFFFFEU;
    set_monotonic_time(T2);
    r = polled_timer_expired_ex(t, TO);
    TEST_ASSERT_TRUE(r);
}
