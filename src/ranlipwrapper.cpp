/************ CRanLip - universal multivariate random  ************************
 *      variate generatior based on acceptance/rejection
 *
 *      begin                : April 30 2004
 *        version                 : 1.0
 *        copyright            : (C) 2004 by Gleb Beliakov
 *        email                : gleb@deakin.edu.au
 *
 *
 *  implementation of CRanLip class
 *
 *
 * Copyright (C) 2004 Gleb Beliakov (gleb@deakin.edu.au)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
 function
 Clas Cranlip:
 (2)SetUniformGenerator(ranlux_get_double_V)
 (11)FreeMem()
 (4)Distribution(double* p)
 (3)Seed(int seed)
 (1) Init(int dim, double* left, double* right)
 (8)RandomVecUniform(double* p)
 (7)RandomVec(double* p)
 (5)PrepareHatFunction(int num, int numfine, double Lip)
 (6)PrepareHatFunctionAuto(int num, int numfine, double minLip)
 --ComputeArray()
 --ComputeArrayCache(int J)
 --GetIndexfromIJK( int* IJK)
 --ComputeMaxBin()
 --ComputeLipschitzBin()
 --GetIJK(int b)
 --GetIJKfineBin(int b)
 (9)SavePartition(char * fname)
 (10)LoadPartition(char * fname)
 
 */
#include "ranlip.h"
#include "ranlipproc.h"


#include <cstdlib>
#include <vector>

#include <Rcpp.h>
#include <Rdefines.h>
#include <stdint.h>

using namespace Rcpp;

typedef void ( *USER_FUNCTION)(int *, double *, double *);
// forward declarations

extern "C" int TheSeed;
extern     ranlux_state_t RLSTATE;

//DistFun GlobalDistFunc;


//' Ranlip code in C++ is being called from R environment with multiple arguments
 //' It then periodically calls a function in R
//' "//[[Rcpp::export]]" is needed to export the function to R environment
//' @param str input character vector
//' @exportPattern("^[[:alpha:]]+")
//' @useDynLib Ranlip
//' @importFrom Rcpp evalCpp
//[[Rcpp::export]]



void* fn;
//global

double myfun(double* p, int dim) 
{
    //double f;
    SEXP fval;
    Rcpp::Function func((SEXP) fn);

//Rprintf("\n%s  %f %f", "inside myfun: ", x[0],x[1]);

    NumericVector X = as<NumericVector>(wrap(std::vector<double>(p, p + dim)));
    fval = func( X, wrap(dim));
    return as<double>(fval);

//Rprintf("\n%s  %f %f", "inside myfun: ", x[0],*f);
//    return f;
}

extern int GlobalFunctionCounter;
extern  ProcRanLip RanLipGenerator;



void FreeMem_R(){

 FreeMemRanLip();

}


void Seed_R(SEXP seed){
	int Seed = as<int>(seed);
	SeedRanLip(Seed);
}

void Init_R(SEXP dim, SEXP left, SEXP right){
    
    int DIM = as<int>(dim);
    
    double *L, *R;

    L = NUMERIC_POINTER(left);
    R = NUMERIC_POINTER(right);
//		Rprintf("\n%s  %x ", "intsideinit init: ",&RanLipGenerator);
	InitRanLip(DIM, L, R);

	SetDistFunctionRanLip(&myfun);  // always the same function			
//	Rprintf("\n%s  %x %x", "intsideinit init: ",&RanLipGenerator,&myfun);
}


SEXP RandomVec_R( SEXP Fn){
    
    double *P;
	int Dim =RanLipGenerator.Dimension;
    //= as<int>(dim)	
	NumericVector p(Dim);

    P = NUMERIC_POINTER(p);
    fn = (void*) Fn;
//	SetDistFunctionRanLip(&myfun);  // always the same function
	
	RandomVecRanLip(P);

	return p;
}

void PrepareHatFunction_R(SEXP num, SEXP numfine, SEXP Lip, SEXP Fn){
    
    int NUM = as<int>(num);
    int NUMF= as<int>(numfine);
    
    double LIP = as<double>(Lip);

    fn = (void*) Fn;
	SetDistFunctionRanLip(&myfun);  // always the same function
	
	PrepareHatFunctionRanLip(NUM, NUMF, LIP);
}

SEXP PrepareHatFunctionAuto_R(SEXP num, SEXP numfine, SEXP minLip, SEXP Fn){
    
    int NUM = as<int>(num);
    int NUMF= as<int>(numfine);
    
	double MINLIP = as<double>(minLip);
    

    double LipConst;

    fn = (void*) Fn;
	SetDistFunctionRanLip(&myfun);  // always the same function

	PrepareHatFunctionAutoRanLip(NUM, NUMF, MINLIP);
	LipConst=LipschitzRanLip();

	return wrap(LipConst);
}



SEXP SavePartition_R(SEXP string){
    
//	char* STR = CHAR(STRING_ELT(string, 0));// extract string
    
	int i=SavePartitionRanlip(CHAR(STRING_ELT(string, 0)));
	return wrap(i);
}

SEXP LoadPartition_R(SEXP string){
	//char* STR = CHAR(STRING_ELT(string, 0));// extract string

	int i=LoadPartitionRanLip(CHAR(STRING_ELT(string, 0)));
	SetDistFunctionRanLip(&myfun);  // always the same function
	return wrap(i);
}
