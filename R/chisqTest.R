library('MASS')

car<-data.frame(
  ab=Cars93$AirBags,
  tp=Cars93$Type
  )

car<-table(
  Cars93$AirBags,
  Cars93$Type
)

print(car)
print(chisq.test(car))
