set.seed(1234)

df<-data.frame(
  name=paste(rep('R-',10),1:10),
  wt=round(rnorm(10,30,2),2)
)

print(df)
result<-wilcox.test(df$wt,mu=25,alternative='less')
print(result)