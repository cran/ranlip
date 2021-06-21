\name{ranlip.RandomVec}
\alias{ranlip.RandomVec}
\title{Generated variate function with density p
}
\description{Function for generating a random variate with density p. It should be called after ranlip.PrepareHatFunctionAuto() and/or ranlip.PrepareHatFunction().

}
\usage{
  ranlip.RandomVec(dist)
}
%- maybe also 'usage' for other objects documented here.
\arguments{

    \item{dist}{The distribution function p(x) where x is the  array of size dim..}
}

\value{
  \item{output}{The output is a random variate with the density p.}
  
}

\author{
   Gleb Beliakov, Daniela L. Calderon, Deakin University
}

\examples{

    dim<-3
	left<-c(0,0,0)
	right<-c(5,5,5)

	ranlip.Init(dim, left, right);

	num <- 10
	numfine <- 4
	MinLip <- 1

	Fn <- function(x,dim){
		out <- exp(-sum(x*x))
  
		return(out)
	}
	

	ranlip.PrepareHatFunctionAuto(num, numfine, MinLip, Fn)
	
	r<-ranlip.RandomVec( Fn)
	
	print(r)
	r<-ranlip.RandomVec( Fn)
	
	print(r)
 
   ranlip.FreeMem()
	

 


                
}

\keyword{ RandomVec}
\keyword{RandomVec}% __ONLY ONE__ keyword per line