sum_dig <- function(num){
  sum<-0
  while (num>0){
    digit<-num%%10
    sum<-sum+digit
    num<-num%/%10
  }
  cat('Sum of digits',sum)
}

n<-as.numeric(readline('Enter a number: '))
sum_dig(n)
