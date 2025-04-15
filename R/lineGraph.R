subs<-c(1,2,3,4,5)
m1<-c(20,50,15,3,45)
m2<-c(5,7,32,46,21)

plot(subs,m1,type='p',col='yellow',ylim=c(0,50),xlim=c(1,5),xlab='marks',ylab='subject',main='RESULTS')
lines(subs,m2,type='p',col='violet')
