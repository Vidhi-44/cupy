#ifndef INCLUDE_GUARD_CUPY_CUDA_CUB_H
#define INCLUDE_GUARD_CUPY_CUDA_CUB_H

#define CUPY_CUB_INT8        0
#define CUPY_CUB_UINT8       1
#define CUPY_CUB_INT16       2
#define CUPY_CUB_UINT16      3
#define CUPY_CUB_INT32       4
#define CUPY_CUB_UINT32      5
#define CUPY_CUB_INT64       6
#define CUPY_CUB_UINT64      7
#define CUPY_CUB_FLOAT16     8
#define CUPY_CUB_FLOAT32     9
#define CUPY_CUB_FLOAT64    10
#define CUPY_CUB_COMPLEX64  11
#define CUPY_CUB_COMPLEX128 12

#define CUPY_CUB_SUM  0
#define CUPY_CUB_MIN  1
#define CUPY_CUB_MAX  2

#ifndef CUPY_NO_CUDA
#include <cuda_runtime.h>  // for cudaStream_t

void cub_reduce_sum_min_max(void *, void *, int, void *, size_t &, cudaStream_t, int, int);
size_t cub_reduce_sum_min_max_get_workspace_size(void *, void *, int, cudaStream_t, int, int);

#else // CUPY_NO_CUDA
typedef struct CUstream_st *cudaStream_t;

void cub_reduce_sum_min_max(...) {
}

size_t cub_reduce_sum_min_max_get_workspace_size(...) {
    return 0;
}

#endif // #ifndef CUPY_NO_CUDA

#endif // #ifndef INCLUDE_GUARD_CUPY_CUDA_CUB_H
