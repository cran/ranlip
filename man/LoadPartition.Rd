\name{ranlip.LoadPartition}
\alias{ranlip.LoadPartition}
\title{Load   the computed hat function 
}
\description{Loads previously computed hat function from file name(string)
}
\usage{
  ranlip.LoadPartition(string)
}

\arguments{
  \item{string}{The file name to read saved partition from}
  }

\value{
  \item{output}{The output is 0 if the function was successful, or: 2 if the file cannot be opened, 3 if file is corrupted, 4 if memory cannot be allocated}
}

\author{

    Gleb Beliakov, Daniela L. Calderon, Deakin University
}

\examples{
	Fn <- function(x,dim){
		out <- sum(exp(-x))
  
		return(out)
	}
    out<-ranlip.LoadPartition("mypartition.txt")
	if(out>0) {
		print("Error loading hat function. ")
		err<-switch(out,"Unknown","Fice cannot be opened",
		 "File is corrupted","Memory not allocated")
		print(err)
	} else {

		r<-ranlip.RandomVec( Fn)
		print(r)
	}
   	ranlip.FreeMem();
}

\keyword{ LoadPartition}
\keyword{LoadPartition}% __ONLY ONE__ keyword per line