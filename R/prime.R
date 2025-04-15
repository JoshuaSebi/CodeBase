for (i in 2:200){
  flag<-TRUE
  for (j in 2:sqrt(i)) {
    if (i%%j==0){
      flag<-FALSE
      break
    }
  }
  if (flag==TRUE){
    cat(i," ") 
  }
}