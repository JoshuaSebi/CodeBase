print_days<-function(val){
  if (val<1 || val>7){
    print("Invalid input")
  }
  else{
    out<-switch(val,
        'Mon',
        'Tue',
        'Wed',
        'Thur',
        'Fri',
        'sat',
        'Sun')
  }
  return (out)
}

opt<-as.numeric(readline('Enter value: '))
res<-print_days(opt)
cat(res)