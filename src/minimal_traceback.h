#ifndef MINIMAL_TRACEBACK_H_INCLUDED
#define MINIMAL_TRACEBACK_H_INCLUDED

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/* Maximal number of location in the traceback */
#define MTB_MAX 100

/* If the tb contains errors, store current location and returns */
#define MTB_V if(tb->n>0){MTB_propagate_error(tb,__FILE__,__LINE__,__func__);return;}

/* In the main function, stop is tb contains erros */
#define MTB_S if(tb->n>0){MTB_stop_if_error(tb,__FILE__,__LINE__,__func__);};

/* Raise different error type */
#define MTB_raise_IOError_V(msg) MTB_raise_error(tb,MTB_IOError,__FILE__,__LINE__,__func__,msg);return;
#define MTB_raise_MemoryError_V(msg) MTB_raise_error(tb,MTB_MemoryError,__FILE__,__LINE__,__func__,msg);return;
#define MTB_raise_ZeroDivisionError_V(msg) MTB_raise_error(tb,MTB_ZeroDivisionError,__FILE__,__LINE__,__func__,msg);return;
#define MTB_raise_NotImplementedError_V(msg) MTB_raise_error(tb,MTB_NotImplementedError,__FILE__,__LINE__,__func__,msg);return;

typedef enum {MTB_MemoryError, MTB_ZeroDivisionError, MTB_IOError,
    MTB_NotImplementedError} MTB_Error;
extern const size_t MTB_n_error;
extern const char* MTB_str_error[4];

typedef struct {
    const char* filename[MTB_MAX];
    size_t line[MTB_MAX];
    const char* func[MTB_MAX];
    const char* msg;
    size_t error;
    size_t n;
} MTB_T;

MTB_T*
MTB_new_tb();

void
MTB_tb_print(MTB_T* tb);

void
MTB_stop_if_error(MTB_T* tb, const char* filename, const size_t line,
                 const char* func);

void
MTB_raise_error(MTB_T* tb, MTB_Error error, const char* filename, const size_t line,
                const char* func, const char* msg);

void
MTB_propagate_error(MTB_T* tb, const char* filename, const size_t line,
                   const char* func);

#endif
