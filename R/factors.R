fact<- function(num){
  f<-c()
  for (i in 1:num){
    if(num%%i==0){
      f<-c(i,f)
    }
  }
  return (f)
}

n<-as.numeric(readline('Enter a number: '))
cat('The factors of ',n,' are ', fact(n))