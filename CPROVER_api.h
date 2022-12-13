#pragma once

/**** 常用内置API ****/

/* 1. 前后置条件 */

// 前置条件声明
void __CPROVER_assume(__CPROVER_bool assumption);

// 后置条件声明
void __CPROVER_assert(__CPROVER_bool assertion, const char *description);

/* 2. 内存相关 */ 

// 返回指针在验证器内存模型中的ID
__CPROVER_size_t __CPROVER_POINTER_OBJECT(const void *p);

// 返回指针的偏移量
__CPROVER_ssize_t __CPROVER_POINTER_OFFSET(const void *p);

// 返回指针p后连续size个字节的内存可读性
__CPROVER_bool __CPROVER_r_ok(const void *p, size_t size);

// 返回指针p后连续size个字节的内存可写性
__CPROVER_bool __CPROVER_w_ok(const void *p, size_t size);

// 返回指针p后连续size个字节的内存可读写性
__CPROVER_bool __CPROVER_rw_ok(const void *p, size_t size);

// 读入一个有效指针并将其所有字节初始化为未定值
void __CPROVER_havoc_object(void *p);

// 读入一个可写的内容，将其后连续size个字节设为未定值
void __CPROVER_havoc_slice(void *p, __CPROVER_size_t size);

// 判断两个指针是否只向同一对象
__CPROVER_bool __CPROVER_same_object(const void *, const void *);

/* 3. 溢出判断 */

// 对两个任意数值类型的数的乘法做溢出判断，溢出时返回真
__CPROVER_bool __CPROVER_overflow_plus();

// 对两个任意数值类型的数的减法做溢出判断，溢出时返回真
__CPROVER_bool __CPROVER_overflow_minus();

// 对两个任意数值类型的数的乘法做溢出判断，溢出时返回真
__CPROVER_bool __CPROVER_overflow_mult();

// 对一个任意数值类型的数取负后做溢出判断，溢出时返回真
__CPROVER_bool __CPROVER_overflow_unary_minus();

/* 4. 一些类型的未定值 */

bool nondet_bool();
int nondet_int();
size_t nondet_size_t();
uint16_t nondet_uint16_t();
uint32_t nondet_uint32_t();
uint64_t nondet_uint64_t();
uint8_t nondet_uint8_t();
void *nondet_voidp();