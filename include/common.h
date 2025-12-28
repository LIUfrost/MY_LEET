/**
 * common.h
 * 常用标准库头文件集合
 * 避免在每个源文件中重复包含
 */

#ifndef COMMON_INCLUDES_H
#define COMMON_INCLUDES_H

// 输入输出
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// 字符串处理
#include <string.h>
#include <ctype.h>
#include <string.h>  // bzero, bcopy等

// 数学函数
#include <math.h>
#include <complex.h>  // C99复数支持

// 内存管理
#include <malloc.h>

// 时间和日期
#include <time.h>


// 错误处理
#include <errno.h>
#include <assert.h>

// 类型定义
#include <stdint.h>    // 固定宽度整数类型
#include <inttypes.h>  // 格式化输出整数类型

// 可变参数
#include <stdarg.h>

// 信号处理
#include <signal.h>

// 环境控制
#include <fcntl.h>     // 文件控制

#endif /* COMMON_INCLUDES_H */