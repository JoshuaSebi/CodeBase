import pandas as pd

data={
    "Stud":["abhay","nevin","namish","joshua"],
    "Class":["A","B","A","C"],
    "Sub": ["Sci","Math","Sci","Math"],
    "Marks": [35,48,41,23]
}

df= pd.DataFrame(data)
print(df)

print("==============================")
pt=pd.pivot_table(df,values="Marks",index="Class",columns="Sub",aggfunc="mean")
print(pt)
print("==============================")

ct=pd.crosstab(df["Sub"],df["Class"])
print(ct)
