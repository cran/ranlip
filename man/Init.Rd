\name{ranlip.Init}
\alias{ranlip.Init}
\title{Initialization of the internal variables 
}
\description{Function for initialing the internal variables. Int must be called only once before any other method.
}
\usage{
  ranlip.Init(dim, left, right)
}

\arguments{
  \item{dim}{The dimension }
  \item{left}{An array of size dim which determine the domain of p: left|i <= x|i <= right|i}
  \item{right}{An array of size dim which determine the domain of p: left|i <= x|i <= right|i}

  }
  
  \value{
    \item{output}{No return value, called to initialise the  internal variables.}
  }
  \author{
      Gleb Beliakov, Daniela L. Calderon, Deakin University
  }
  
  \examples{
    dim<-3
	left<-c(0,0,0)
	right<-c(1,1,1)
	ranlip.Init(dim, left, right);
	
	ranlip.FreeMem();
  }
  \keyword{ Init}
  \keyword{Init}% __ONLY ONE__ keyword per line