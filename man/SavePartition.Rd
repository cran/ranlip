\name{ranlip.SavePartition}
\alias{ranlip.SavePartition}

\title{Saves the computed hat function into a file
}
\description{Function for saving previously computed hat function to file name(string)
}
\usage{
  ranlip.SavePartition(string)
}
\arguments{
  \item{string}{The file name to save the partition}
  
}

\value{
  \item{output}{The output is 0 if the function was successful, or 1 if no hat function was computed, or 2 if the file cannot be opened.}
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
		out <- exp(-sum(x*x))
  
		return(out)
	}
	
	ranlip.PrepareHatFunctionAuto(num, numfine, MinLip, Fn);
	
# we don't want to create this file unnecessarily	
	\donttest{ out<-ranlip.SavePartition("mypartition.txt")}
	\donttest{if(out>0) {print("File cannot be opened.")}  }

	
 	ranlip.FreeMem()
}

\keyword{ SavePartition}
\keyword{SavePartition}% __ONLY ONE__ keyword per line