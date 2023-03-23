
// 
// BLAS level 3
// 30 subroutines in total
//

//?gemm
//

void sgemm_(const char *transa, const char *transb, const int *m, const int *n, const int *k, 
                const float *alpha, const float *a, const int *lda, const float *b, const int *ldb, 
                const float *beta, float *c, const int *ldc) 
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

void dgemm_(const char *transa, const char *transb, const int *m, const int *n, const int *k,
                const double *alpha, const double *a, const int *lda, const double *b, const int *ldb,
                const double *beta, double *c, const int *ldc) 
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    if(peakprof_debug && ifrecord) printf ("dgemm -- matrix size A:%dx%d  B:%dx%d:   C:%dx%d\n", *m, *k,*k,*n,*m,*n);
    orig_f(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 

    if(ifrecord){
      int isize=(int)( cbrt(*m)*cbrt(*n)*cbrt(*k) );
      if(isize==0) isize=1;
      int log10_isize=(int)log10(isize);
      char callpath[400]="";
      struct item2* item2;
      strcat(callpath,layer_caller[0]);
      for(int j=1;j<=layer_count+1;j++) { 
         strcat(callpath,"->");
         strcat(callpath,layer_caller[j]);
      }
      item2 = hash2_get(callpath); 
      if (item2 == NULL )  item2 = hash2_insert(callpath);
      
      item2->value.time_in += local_time;
      item2->value.distribution_time[log10_isize] += local_time;
      item2->value.count ++;
      item2->value.distribution_count[log10_isize] ++;
      item2->value.distribution_sizesum[log10_isize] += (float)isize;
      item2->value.distribution_sizesumsq[log10_isize] += (float)isize*(float)isize;
      
    }

    return;
}

void cgemm_(const char *transa, const char *transb, const int *m, const int *n, const int *k,
                const void *alpha, const void *a, const int *lda, const void *b, const int *ldb,
                const void *beta, void *c, const int *ldc) 
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

void zgemm_(const char *transa, const char *transb, const int *m, const int *n, const int *k,
                const void *alpha, const void *a, const int *lda, const void *b, const int *ldb,
                const void *beta, void *c, const int *ldc) 
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

//?hemm 
//

void chemm_(const char *side, const char *uplo, const int *m, const int *n,
    const void *alpha, const void *a, const int *lda, const void *b, const int *ldb,
    const void *beta, void *c, const int *ldc)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

void zhemm_(const char *side, const char *uplo, const int *m, const int *n,
    const void *alpha, const void *a, const int *lda, const void *b, const int *ldb,
    const void *beta, void *c, const int *ldc)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

//?herk
//

void cherk_(const char *uplo, const char *trans, const int *n, const int *k,
    const float *alpha, const void *a, const int *lda, const float *beta, void *c, const int *ldc)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

void zherk_(const char *uplo, const char *trans, const int *n, const int *k,
    const float *alpha, const void *a, const int *lda, const float *beta, void *c, const int *ldc)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

//?her2k
//

void cher2k_(const char *uplo, const char *trans, const int *n, const int *k,
    const void *alpha, const void *a, const int *lda, const void *b, const int *ldb,
    const float *beta, void *c, const int *ldc) 
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
  orig_f(uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

void zher2k_(const char *uplo, const char *trans, const int *n, const int *k,
    const void *alpha, const void *a, const int *lda, const void *b, const int *ldb,
    const float *beta, void *c, const int *ldc) 
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
  orig_f(uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

//?symm
//

void ssymm_(const char *side, const char *uplo, const int *m, const int *n,
    const float *alpha, const float *a, const int *lda, const float *b, const int *ldb,
    const float *beta, float *c, const int *ldc) 
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

void dsymm_(const char *side, const char *uplo, const int *m, const int *n,
    const double *alpha, const double *a, const int *lda, const double *b, const int *ldb,
    const double *beta, double *c, const int *ldc) 
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

void csymm_(const char *side, const char *uplo, const int *m, const int *n,
    const void *alpha, const void *a, const int *lda, const void *b, const int *ldb,
    const void *beta, void *c, const int *ldc) 
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

void zsymm_(const char *side, const char *uplo, const int *m, const int *n,
    const void *alpha, const void *a, const int *lda, const void *b, const int *ldb,
    const void *beta, void *c, const int *ldc) 
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

//?syrk
//
void ssyrk_(const char *uplo, const char *trans, const int *n, const int *k,
    const float *alpha, const float *a, const int *lda, const float *beta, float *c, const int *ldc) 
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

void dsyrk_(const char *uplo, const char *trans, const int *n, const int *k,
    const double *alpha, const double *a, const int *lda, const double *beta, double *c, const int *ldc) 
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

void csyrk_(const char *uplo, const char *trans, const int *n, const int *k,
    const void *alpha, const void *a, const int *lda, const void *beta, void *c, const int *ldc) 
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

void zsyrk_(const char *uplo, const char *trans, const int *n, const int *k,
    const void *alpha, const void *a, const int *lda, const void *beta, void *c, const int *ldc) 
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

//?syr2k
//

void ssyr2k_(const char *uplo, const char *trans, const int *n, const int *k, 
    const float *alpha, const float *a, const int *lda, const float *b, const int *ldb, 
    const float *beta, float *c, const int *ldc)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

void dsyr2k_(const char *uplo, const char *trans, const int *n, const int *k, 
    const double *alpha, const double *a, const int *lda, const double *b, const int *ldb, 
    const double *beta, double *c, const int *ldc)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

void csyr2k_(const char *uplo, const char *trans, const int *n, const int *k, 
    const void *alpha, const void *a, const int *lda, const void *b, const int *ldb, 
    const void *beta, void *c, const int *ldc)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

void zsyr2k_(const char *uplo, const char *trans, const int *n, const int *k, 
    const void *alpha, const void *a, const int *lda, const void *b, const int *ldb, 
    const void *beta, void *c, const int *ldc)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
#include "function_wrapper_body2.c" 
    return;
}

//?trmm 
//
void strmm_(const char *side, const char *uplo, const char *transa, const char *diag, 
    const int *m, const int *n, const float *alpha, const float *a, const int *lda, float *b, const int *ldb)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
#include "function_wrapper_body2.c" 
    return;
}

void dtrmm_(const char *side, const char *uplo, const char *transa, const char *diag, 
    const int *m, const int *n, const double *alpha, const double *a, const int *lda, double *b, const int *ldb)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
#include "function_wrapper_body2.c" 
    return;
}

void ctrmm_(const char *side, const char *uplo, const char *transa, const char *diag, 
    const int *m, const int *n, const void *alpha, const void *a, const int *lda, void *b, const int *ldb)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
#include "function_wrapper_body2.c" 
    return;
}

void ztrmm_(const char *side, const char *uplo, const char *transa, const char *diag, 
    const int *m, const int *n, const void *alpha, const void *a, const int *lda, void *b, const int *ldb)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
#include "function_wrapper_body2.c" 
    return;
}

//?trsm
//
void strsm_(const char *side, const char *uplo, const char *transa, const char *diag, 
    const int *m, const int *n, const float *alpha, const float *a, const int *lda, float *b, const int *ldb)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
#include "function_wrapper_body2.c" 
    return;
}

void dtrsm_(const char *side, const char *uplo, const char *transa, const char *diag, 
    const int *m, const int *n, const double *alpha, const double *a, const int *lda, double *b, const int *ldb)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
#include "function_wrapper_body2.c" 
    return;
}

void ctrsm_(const char *side, const char *uplo, const char *transa, const char *diag, 
    const int *m, const int *n, const void *alpha, const void *a, const int *lda, void *b, const int *ldb)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
#include "function_wrapper_body2.c" 
    return;
}

void ztrsm_(const char *side, const char *uplo, const char *transa, const char *diag, 
    const int *m, const int *n, const void *alpha, const void *a, const int *lda, void *b, const int *ldb)
{
    void (*orig_f)()=NULL;
#include "function_wrapper_body1.c" 
    orig_f(side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
#include "function_wrapper_body2.c" 
    return;
}


