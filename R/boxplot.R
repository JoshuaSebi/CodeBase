data(airquality)
str(airquality)

boxplot(airquality[,c('Ozone','Solar.R','Wind',"Temp",'Day','Month')])