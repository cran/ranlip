\name{ranlip.FreeMem}
\alias{ranlip.FreeMem}

\title{Free Memory Function  
}
\description{Freeing the memory occupied by the data structures. It destroys the hat function (Preparehatfunction) and RandomVec().
}
\usage{
  ranlip.FreeMem()
}

  
  \value{
    \item{output}{No return value, called for side effects}
  }
  \author{
     Gleb Beliakov, Daniela L. Calderon, Deakin University
  }
  
  \examples{
		
	dim<-3
	left<-c(0,0,0)
	right<-c(5,5,5)

	ranlip.Init(dim, left, right);
    ranlip.FreeMem();
  }

  \keyword{ FreeMem}
  \keyword{FreeMem}% __ONLY ONE__ keyword per line