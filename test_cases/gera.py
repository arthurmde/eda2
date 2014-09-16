minimo=10**7
maximo=99999999
variacao=777777
for i in range(minimo,maximo+1,variacao):
    print ((i - minimo)/variacao),
    vetor = range(i,minimo,-variacao)
    for j in range(0,len(vetor)):
        print " "+str(vetor[j]),
    print
