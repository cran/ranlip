
#SEXP way Rcpp


ranlip <- function()
{
  # This function outputs a list of all functions included in this toolbox.
  
  print("The list of functions in ranlip Tool Box:")
  
  print("ranlip.FreeMem()")
  print("ranlip.Init([dimension], [domain determined], [domain determined])")
  print("ranlip.LoadPartition([file name])")
  print("ranlip.PrepareHatFunction([subdivisions number], [subdivisions number],  [Lipschitz constant], [Distribution])")
  print("ranlip.PrepareHatFunctionAuto([subdivisions number], [subdivisions number],  [Lipschitz constant computed], [Distribution])")
  print("ranlip.RandomVec([Distribution])")
  print("ranlip.RandomVecN([number of vectors], [Distribution])")
  print("ranlip.SavePartition([file name])")
  print("ranlip.Seed([seed])")
}





ranlip.FreeMem <- function() {
   .Call('ranlip_FreeMem', PACKAGE = 'ranlip')
}


ranlip.Seed <- function(seed) {
    .Call('ranlip_Seed', PACKAGE = 'ranlip', seed)
}

ranlip.Init <- function(dim, left, right) {
    .Call('ranlip_Init', PACKAGE = 'ranlip', dim, left, right)
}



ranlip.RandomVec<- function(dist) {

    out <-  .Call('ranlip_RandomVec', PACKAGE = 'ranlip', dist)
    return (out)
}

ranlip.PrepareHatFunction <- function(num, numfine, Lip, dist) {
    .Call('ranlip_PrepareHatFunction', PACKAGE = 'ranlip', num, numfine, Lip, dist)
}

ranlip.PrepareHatFunctionAuto <- function(num, numfine, minLip, dist) {
    out <-  .Call('ranlip_PrepareHatFunctionAuto', PACKAGE = 'ranlip', num, numfine, minLip,dist)
  return (out)
}

ranlip.SavePartition<- function(string) {
    out <-  .Call('ranlip_SavePartition', PACKAGE = 'ranlip', string)
  return (out)
}

ranlip.LoadPartition<- function(string) {
    out <-   .Call('ranlip_LoadPartition', PACKAGE = 'ranlip', string)
  return (out)
}



ranlip.RandomVecN<- function(n,dist){
	r<-c()
	for(i in 1:n) {r<-c(r,ranlip.RandomVec(dist))}
	return (matrix(r,nrow=n,byrow=TRUE))
}