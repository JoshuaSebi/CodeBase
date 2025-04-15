m1 <- matrix(1:9,nrow=3,ncol=3)
m2 <- matrix(9:1,nrow=3,ncol=3)

cat('Matrix 1\n')
print(m1)
cat('Matrix 2\n')
print(m2)

#addition
m3<-m1+m2
cat('Addition\n')
print(m3)

#subtraction
m4<-m1-m2
cat('Subtraction\n')
print(m4)

#multiplication
m5<-m1%*%m2
cat('Multiplication\n')
print(m5)

#transpose
m6<-t(m1)
cat('Transpose of m1\n')
print(m6)

