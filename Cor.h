#ifndef _Cor_h_
#define _Cor_h_

#include <stdio.h>
#include <thread>
#include <map>


#define CorLog printf


#define SyncCor(func, arg) \
do{ \
int ret = 0; \
jmp_buf j; \
ret = setjmp(j); \
if (ret == 1) \
{ \
break; \
} \
func(arg); \
CorLog("SyncCor %d finished!\n", arg); \
longjmp(j, 0); \
} while (0)

#if 0 //��Ҫ��lambda std::function֮���callback��װһ�����longjmp
#define AsyncCor(func, callback) \
do{\
int ret = 0; \
jmp_buf j; \
ret = setjmp(j); \
if (ret == 1) \
{ \
break; \
} \
func(callback); \
CorLog("SyncCor %d finished!\n", arg); \
longjmp(j, 0); \
} while (0)
#endif

#define ThreadCor(func, arg) \
do{ \
int ret = 0; \
jmp_buf j; \
ret = setjmp(j); \
if (ret == 1) \
{ \
	break; \
} \
std::thread cor(func, arg); \
cor.join(); \
CorLog("ThreadCor %d finished!\n", arg); \
longjmp(j, 0); \
} while (0)


#endif // _Cor_h_
