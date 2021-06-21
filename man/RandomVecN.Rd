\name{ranlip.RandomVecN}
\alias{ranlip.RandomVecN}

\title{Generates variate function with density p
}
\description{Function for generating n random variates with density p. It should be called after ranlip.PrepareHatFunctionAuto() and ranlip.PrepareHatFunction().
}
\usage{
  ranlip.RandomVecN(n,dist)
}

\arguments{
	\item{n}{The number of random vectors desired}
    \item{dist}{The distribution function p(x) where x is the  array of size dim..}
}

\value{

  \item{output}{The output is n random variates with the density p, in a matrix arranged by rows.}
  
}

\author{
   Gleb Beliakov, Daniela L. Calderon, Deakin University
}

\examples{

    dim<-2
	left<-c(-2,-2)
	right<-c(2,2)

	ranlip.Init(dim, left, right);

	num <- 10
	numfine <- 4
	MinLip <- 1

	Fn <- function(x,dim){
		r<-x[1]*x[1]+x[2]*x[2]
		out <- exp(-( (x[1]+0.2)^2+(x[2]+0.1)^2)/1.1 )*(1-exp(-sqrt(r)))
		return(out)
	}
	

	ranlip.PrepareHatFunctionAuto(num, numfine, MinLip, Fn)
	
	rv<-ranlip.RandomVecN(100, Fn)
	

	plot(rv[,1],rv[,2],cex=0.5)
 
    ranlip.FreeMem()
                
}

\keyword{ RandomVecN}
\keyword{RandomVecN}% __ONLY ONE__ keyword per line