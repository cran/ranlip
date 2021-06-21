\name{ranlip.PrepareHatFunction}
\alias{ranlip.PrepareHatFunction}

\title{Builds the hat function for a given Lipschitz constant
}
\description{Function for Building the hat function using Lipschitz constant
}
\usage{
  ranlip.PrepareHatFunction(num, numfine, Lip, dist)
}

\arguments{
  \item{num}{The number of subdivisions in each variable to partition the Domain D into hyperrectangles D|k. On each D|k, the hat function will have a constant value h|k }
  \item{numfine}{The number of subdivisions in the finer partition in each variable. Each D|k is subdivided into (numfine-1)^dim smaller hyperrectangles, in order to improve the quality of the overstimate h|k. nunmfine should be a power of 2 for numerical efficiency reason ( if not, it will be automatically changed to a power of 2 larger than the supplied value) numdine can be 2, in which case the fine partition is not used}
  \item{Lip}{Lipschitz constant supplied}
  \item{dist}{The distribution function p(x) where x is the  array of size dim.}
  
}

\value{
  \item{output}{No return value. Generates and stores internally  the hat function. }
}

\author{
   Gleb Beliakov, Daniela L. Calderon, Deakin University
   
}

\examples{


    dim<-2
	left<-c(-1,-1,0)
	right<-c(1,1,5)

	ranlip.Init(dim, left, right)
	

	num <- 10
	numfine <- 2
	Lip <- 1



	Fn <- function(x,dim){
		r<-x[1]*x[1]+x[2]*x[2]
		r<-sqrt(r)
		out <- exp(-( (x[1]+0.2)^2+(x[2]+0.1)^2)/1.1 )*exp(-sqrt(r))
		return(out)
	}


	ranlip.PrepareHatFunction(num, numfine, Lip, Fn);
	ranlip.RandomVec(Fn)	
	r<-ranlip.RandomVec( Fn)
	print(r)
	r<-ranlip.RandomVec( Fn)
	print(r)
	
 	ranlip.FreeMem()

                
}

\keyword{ PrepareHatFunction}
\keyword{PrepareHatFunction}% __ONLY ONE__ keyword per line