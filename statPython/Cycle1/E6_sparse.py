def sparseMat(mat):
    rows=len(mat)
    cols=len(mat[0])
    sparse={}
    sparse[rows,cols]=0
    for i in range(rows):
        for j in range(cols):
            if mat[i][j]!=0:
                sparse[i,j]=mat[i][j]
                sparse[rows,cols]+=1
    return sparse


matr=[[0,0,3],
        [1,0,6],
        [4,0,0]]

sparsDict=sparseMat(matr)
for i in sparsDict:
    print(i[0],i[1],sparsDict[i])
