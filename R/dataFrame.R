ret<-function(f){
  df<- data.frame(
    sno=c(1,2,3),
    nm=c('A','B','C'),
    place=c('Kerala','Delhi','Mumbai'),
    marks=f
  )
  return (df)
}  

f<-c()
for(i in 1:3){
  inp<-as.numeric(readline('Enter Values: '))
  f<-c(inp,f)
}
op<-ret(f)
print(op)
print(summary(op))

#add to df
a<-data.frame(
  sno=4,
  nm='D',
  place='Chennai',
  marks=4
)

op<-rbind(op,a)

print('/nNew dataframe')
print(op)
