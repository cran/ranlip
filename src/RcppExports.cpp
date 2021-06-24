#include <Rcpp.h>

using namespace Rcpp;



//#include "ranlipproc.h"
// ranlip


#include <R_ext/Rdynload.h>
#include <R_ext/Visibility.h>




SEXP FreeMem_R();
RcppExport SEXP ranlip_FreeMem() {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    FreeMem_R();
 END_RCPP
}

static const R_CallMethodDef callMethods_FreeMem[]  = {
  {NULL, NULL, 0}
};

//static R_NativePrimitiveArgType myC_t_FreeMem[] = NULL;
//{};

static const R_CMethodDef cMethods_FreeMem[] = {
//   {"FreeMem_R", (DL_FUNC) &FreeMem_R, 0, myC_t_FreeMem},
   {"FreeMem_R", (DL_FUNC) &FreeMem_R, 0, 0},
   {NULL, NULL, 0, NULL}
};

/* Fn in PrepareHatFunction, PrepareHatFunctionauto and RandomVec
 SEXP Distribution_R(SEXP Fn);
RcppExport SEXP ranlip_Distribution(SEXP FnSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type Fn(FnSEXP);
    __result = Distribution_R(Fn);
    return __result;
END_RCPP
}

static const R_CallMethodDef callMethods_Distribution[]  = {
  {NULL, NULL, 0}
};

static R_NativePrimitiveArgType myC_t_Distribution[] = {
    REALSXP
};

static const R_CMethodDef cMethods_Distribution[] = {
   {"Distribution_R", (DL_FUNC) &Distribution_R, 1, myC_t_Distribution},
   {NULL, NULL, 0, NULL}
};
*/





void  Seed_R(SEXP seed);
RcppExport SEXP ranlip_Seed(SEXP seed) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
	Rcpp::traits::input_parameter< SEXP >::type Seed(seed);
   // __result = 
	Seed_R(Seed);
    return seed;
END_RCPP
}

static const R_CallMethodDef callMethods_Seed[]  = {
  {NULL, NULL, 0}
};

static R_NativePrimitiveArgType myC_t_Seed[] = {
    INTSXP
};

static const R_CMethodDef cMethods_Seed[] = {
   {"Seed_R", (DL_FUNC) &Seed_R, 1, myC_t_Seed},
   {NULL, NULL, 0, NULL}
};



void Init_R(SEXP dim, SEXP left, SEXP right);
RcppExport SEXP ranlip_Init(SEXP dimSEXP, SEXP leftSEXP, SEXP rightSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type dim(dimSEXP);
    Rcpp::traits::input_parameter< SEXP >::type left(leftSEXP);
    Rcpp::traits::input_parameter< SEXP >::type right(rightSEXP);
     Init_R(dim, left, right);
END_RCPP
}

static const R_CallMethodDef callMethods_Init[]  = {
  {NULL, NULL, 0}
};

static R_NativePrimitiveArgType myC_t_Init[] = {
    INTSXP, REALSXP, REALSXP
};

static const R_CMethodDef cMethods_Init[] = {
   {"Init_R", (DL_FUNC) &Init_R, 3, myC_t_Init},
   {NULL, NULL, 0, NULL}
};





SEXP RandomVec_R(SEXP Fn);
RcppExport SEXP ranlip_RandomVec(SEXP FnSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type Fn(FnSEXP);
    __result = RandomVec_R(Fn);
    return __result;
END_RCPP
}

static const R_CallMethodDef callMethods_RandomVec[]  = {
  {NULL, NULL, 0}
};

static R_NativePrimitiveArgType myC_t_RandomVec[] = {
     INTSXP
};

static const R_CMethodDef cMethods_RandomVec[] = {
   {"RandomVec_R", (DL_FUNC) &RandomVec_R, 1, myC_t_RandomVec},
   {NULL, NULL, 0, NULL}
};




void  PrepareHatFunction_R(SEXP num, SEXP numfine, SEXP Lip, SEXP Fn);
RcppExport SEXP ranlip_PrepareHatFunction(SEXP numSEXP, SEXP numfineSEXP, SEXP LipSEXP, SEXP FnSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type num(numSEXP);
    Rcpp::traits::input_parameter< SEXP >::type numfine(numfineSEXP);
    Rcpp::traits::input_parameter< SEXP >::type Lip(LipSEXP);
    Rcpp::traits::input_parameter< SEXP >::type Fn(FnSEXP);
//    __result = 
	PrepareHatFunction_R(num, numfine, Lip, Fn);
//    return __result;
END_RCPP
}

static const R_CallMethodDef callMethods_PrepareHatFunction[]  = {
  {NULL, NULL, 0}
};

static R_NativePrimitiveArgType myC_t_PrepareHatFunction[] = {
    INTSXP, INTSXP, REALSXP, INTSXP
};

static const R_CMethodDef cMethods_PrepareHatFunction[] = {
   {"PrepareHatFunction_R", (DL_FUNC) &PrepareHatFunction_R, 4, myC_t_PrepareHatFunction},
   {NULL, NULL, 0, NULL}
};



SEXP PrepareHatFunctionAuto_R(SEXP num, SEXP numfine, SEXP minLip, SEXP Fn);
RcppExport SEXP ranlip_PrepareHatFunctionAuto(SEXP numSEXP, SEXP numfineSEXP, SEXP minLipSEXP, SEXP FnSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type num(numSEXP);
    Rcpp::traits::input_parameter< SEXP >::type numfine(numfineSEXP);
    Rcpp::traits::input_parameter< SEXP >::type minLip(minLipSEXP);
    Rcpp::traits::input_parameter< SEXP >::type Fn(FnSEXP);
//__result = PrepareHatFunctionAuto_R(num, numfine, minLip);
    SEXP val = PrepareHatFunctionAuto_R(num, numfine, minLip, Fn);
    
//    return __result;
    return val;
END_RCPP
}

static const R_CallMethodDef callMethods_PrepareHatFunctionAuto[]  = {
  {NULL, NULL, 0}
};

static R_NativePrimitiveArgType myC_t_PrepareHatFunctionAuto[] = {
    INTSXP, INTSXP, REALSXP, INTSXP
};

static const R_CMethodDef cMethods_PrepareHatFunctionAuto[] = {
   {"PrepareHatFunctionAuto_R", (DL_FUNC) &PrepareHatFunctionAuto_R, 4, myC_t_PrepareHatFunctionAuto},
   {NULL, NULL, 0, NULL}
};





SEXP SavePartition_R(SEXP string);
RcppExport SEXP ranlip_SavePartition(SEXP stringSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type mstring(stringSEXP);
    __result = 	SavePartition_R(mstring);
    return __result;
END_RCPP
}

static const R_CallMethodDef callMethods_SavePartition[]  = {
  {NULL, NULL, 0}
};

static R_NativePrimitiveArgType myC_t_SavePartition[] = {
    REALSXP
};

static const R_CMethodDef cMethods_SavePartition[] = {
   {"SavePartition_R", (DL_FUNC) &SavePartition_R, 1, myC_t_SavePartition},
   {NULL, NULL, 0, NULL}
};



SEXP LoadPartition_R(SEXP string);
RcppExport SEXP ranlip_LoadPartition(SEXP stringSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< SEXP >::type mstring(stringSEXP);
    __result = 	LoadPartition_R(mstring);
    return __result;
END_RCPP
}

static const R_CallMethodDef callMethods_LoadPartition[]  = {
  {NULL, NULL, 0}
};

static R_NativePrimitiveArgType myC_t_LoadPartition[] = {
    REALSXP
};

static const R_CMethodDef cMethods_LoadPartition[] = {
   {"LoadPartition_R", (DL_FUNC) &LoadPartition_R, 1, myC_t_LoadPartition},
   {NULL, NULL, 0, NULL}
};
void
R_init_ranlip(DllInfo* info)
{

    R_registerRoutines(info, cMethods_FreeMem, callMethods_FreeMem, NULL, NULL);

    R_registerRoutines(info, cMethods_Seed, callMethods_Seed, NULL, NULL);
    R_registerRoutines(info, cMethods_Init, callMethods_Init, NULL, NULL);

    R_registerRoutines(info, cMethods_RandomVec, callMethods_RandomVec, NULL, NULL);
    R_registerRoutines(info, cMethods_PrepareHatFunction, callMethods_PrepareHatFunction, NULL, NULL);
    R_registerRoutines(info, cMethods_PrepareHatFunctionAuto, callMethods_PrepareHatFunctionAuto, NULL, NULL);

    R_registerRoutines(info, cMethods_SavePartition, callMethods_SavePartition, NULL, NULL);
    R_registerRoutines(info, cMethods_LoadPartition, callMethods_LoadPartition, NULL, NULL);
    
    R_useDynamicSymbols(info, TRUE);
}

