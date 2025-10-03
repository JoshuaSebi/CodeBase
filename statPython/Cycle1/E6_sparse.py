def sparseMat(mat):
    rows, cols=len(mat), len(mat[0])
    dict_spar={}
    dict_spar[rows,cols]=0
    list_spar=[]
    c=0
    for i in range(0,rows):
        for j in range (0,cols):
            if mat[i][j]!=0:
                c+=1
                add=[i,j,mat[i][j]]
                list_spar.append(add)
                dict_spar[i,j]=mat[i][j]
    list_spar.insert(0,[rows,cols,c])
    dict_spar[rows,cols]=c
    return dict_spar


matr=[[0,0,3],
        [1,0,6],
        [4,0,0]]

sparss=sparseMat(matr)
for i in sparss:
    print(i[0],i[1],sparss[i])
