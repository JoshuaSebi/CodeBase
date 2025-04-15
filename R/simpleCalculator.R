calc <- function(x,y){
  opt<-as.numeric(readline('Enter Option: '))
  
  if (opt==1) {
  s<-x+y
  cat('Sum = ',s)
  }
  else if (opt==2){
    s=x-y
    cat('Diff =',s)
  }
  else if (opt==3){
    s=x*y
    cat('Pdt =',s)
  }
  else{
    s=x/y
    cat("Div =",s)
  }
}

a<-as.numeric(readline("Enter a number: "))
b<-as.numeric(readline("Enter a number: "))

calc(a,b)


