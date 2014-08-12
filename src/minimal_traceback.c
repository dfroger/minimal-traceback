#include "minimal_traceback.h"

const size_t MTB_n_error = 2;
const char* MTB_str_error[4] = {"MemoryError", "ZeroDivisionError", "IOError",
    "NotImplementedError"};

MTB_T*
MTB_new_tb() {
    MTB_T* tb = (MTB_T*) malloc(sizeof(MTB_T));
    tb->n = 0;
    return tb;
}

void
MTB_tb_print(MTB_T* tb) {
    size_t i;
    printf("************************************************\n");
    printf("An error occured, this is the traceback of MTB:\n");
    for (i=tb->n-1 ; ; i--) {
        printf("File: %s, line %zu, in function %s\n",
               tb->filename[i], tb->line[i], tb->func[i]);
        if (i==0)
            break;
    }
    printf("  %s: %s\n",MTB_str_error[tb->error],tb->msg);
    printf("************************************************\n");
}

void
MTB_stop_if_error(MTB_T* tb, const char* filename, const size_t line,
                 const char* func) {
    MTB_propagate_error(tb,filename,line,func);
    MTB_tb_print(tb);
    free(tb);
    exit(1);
}

void
MTB_propagate_error(MTB_T* tb, const char* filename, const size_t line,
                   const char* func) {
    size_t n = tb->n;
    tb->filename[n] = filename;
    tb->line[n] = line;
    tb->func[n] = func;
    tb->n++;
};

void
MTB_raise_error(MTB_T* tb, MTB_Error error, const char* filename, const size_t line,
                const char* func, const char* msg) {
    MTB_propagate_error(tb,filename,line,func);
    tb->error = error;
    tb->msg = msg;
};
