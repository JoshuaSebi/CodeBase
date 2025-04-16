fact<-function(n){
  if (n==1 || n==0){
    return (1)
  }
  else{
    return (n*fact(n-1))
  }
}

# Main program
cat('Factorial of a number using recursion\n')
num<-as.numeric(readline('Enter a number: '))
cat('Factorial=',fact(num))