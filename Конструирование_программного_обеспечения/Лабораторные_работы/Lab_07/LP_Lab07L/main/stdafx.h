#pragma once
#include "D:\studing\Конструирование_программного_обеспечения\Лабораторные_работы\Lab_07\LP_Lab07L\Lab_07L\Dictionary.h"

#if defined(TEST_DICTIONARY)
#define TEST_CREATE_01
#define TEST_CREATE_02
#define TEST_ADDENTRY_03
#define TEST_ADDENTRY_04
#define TEST_GETENTRY_05
#define TEST_DELENTRY_06
#define TEST_UPDENTRY_07
#define TEST_UPDENTRY_08
#if ((defined(TEST_CREATE_02) && defined(TEST_CREATE_01)) || (defined(TEST_ADDENTRY_03) && (defined(TEST_CREATE_02) || defined(TEST_CREATE_01))) ||  (defined(TEST_ADDENTRY_04) && (defined(TEST_ADDENTRY_03) || defined(TEST_CREATE_02) || defined(TEST_CREATE_01))) || (defined(TEST_GETENTRY_05) && (defined(TEST_ADDENTRY_04) || defined(TEST_ADDENTRY_03) || defined(TEST_CREATE_02) || defined(TEST_CREATE_01))) || (defined(TEST_DELENTRY_06) && (defined(TEST_GETENTRY_05) || defined(TEST_ADDENTRY_04) || defined(TEST_ADDENTRY_03) || defined(TEST_CREATE_02) || defined(TEST_CREATE_01))) || (defined(TEST_UPDENTRY_07) && (defined(TEST_DELENTRY_06) || defined(TEST_GETENTRY_05) || defined(TEST_ADDENTRY_04) || defined(TEST_ADDENTRY_03) || defined(TEST_CREATE_02) || defined(TEST_CREATE_01))) || (defined(TEST_UPDENTRY_87) && (defined(TEST_UPDENTRY_07) || defined(TEST_DELENTRY_06) || defined(TEST_GETENTRY_05) || defined(TEST_ADDENTRY_04) || defined(TEST_ADDENTRY_03) || defined(TEST_CREATE_02) || defined(TEST_CREATE_01))))
#error Превышенно количество тестирующих макросов!
#endif

#endif
