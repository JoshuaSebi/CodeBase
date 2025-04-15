data("airquality")
str(airquality$Ozone)

stripchart(airquality$Temp,method='jitter',vertical=TRUE,col='red')