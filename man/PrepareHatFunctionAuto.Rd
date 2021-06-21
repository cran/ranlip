\name{ranlip.PrepareHatFunctionAuto}
\alias{ranlip.PrepareHatFunctionAuto}

\title{Computation function of building the hat function and an estimated Lipschitz constant 
}
\description{Builds the hat function and automatically computes an estimate to the Lipschitz constant. 
}
\usage{
  ranlip.PrepareHatFunctionAuto(num, numfine, minLip, dist)
}

\arguments{
  \item{num}{The number of subdivisions in each variable to partition the Domain D into hyperrectangles D|k. On each D|k, the hat function will have a constant value h|k }
  \item{numfine}{The number of subdivisions in the finer partition in each variable. Each D|k is subdivided into (numfine-1)^dim smaller hyperrectangles, in order to improve the quality of the overstimate h|k. nunmfine should be a power of 2 for numerical efficiency reason ( if not, it will be automatically changed to a power of 2 larger than the supplied value) numdine can be 2, in which case the fine partition is not used}
  \item{minLip}{the lower bound on the value of the computed Lipschitz constant, the default value is 0}
   \item{dist}{The distribution function p(x) where x is the  array of size dim. }
  
}

\value{
  \item{output}{The estimated Lipschitz constant. Stores the hat function internlly.}
  
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
	numfine <- 2
	MinLip <- 1



	Fn <- function(x,dim){
		r<-x[1]*x[1]+x[2]*x[2]
		out <- exp(-( (x[1]+0.2)^2+(x[2]+0.1)^2)/1.1 )*(1-exp(-sqrt(r)))
		return(out)
	}


	Lip<-ranlip.PrepareHatFunctionAuto(num, numfine, MinLip, Fn)
	
	print(Lip)
	ranlip.RandomVec( Fn)
 	ranlip.FreeMem()
	
                
}

\keyword{ PrepareHatFunctionAuto}
\keyword{PrepareHatFunctionAuto}% __ONLY ONE__ keyword per line