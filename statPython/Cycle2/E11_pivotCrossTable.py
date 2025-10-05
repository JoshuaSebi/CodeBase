import pandas as pd
import inspect

data={
    "Stud":["abhay","nevin","namish","joshua"],
    "Class":["A","A","A","A"],
    "Sub": ["Sci","Math","Sci","Math"],
    "Marks": [35,48,41,23]
}

df=pd.DataFrame(data)
print(df)
print("==============================")
pvt=pd.pivot_table(df, values="Marks", index="Class", columns="Sub", aggfunc="mean")
print(pvt)
print("==============================")
ct=pd.crosstab(df["Sub"],df["Marks"])
print(ct)
