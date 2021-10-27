def vueltasRecB(listaValoresMonedas,vueltas,resultadosConocidos):
    minMonedas = vueltas
    if vueltas in listaValoresMonedas:
        resultadosConocidos[vueltas] = 1
        return 1
    elif resultadosConocidos[vueltas] > 0:
        return resultadosConocidos[vueltas]
    else:
       for i in [m for m in listaValoresMonedas if m <= vueltas]:
            numeroMonedas = 1 + vueltasRecB(listaValoresMonedas, vueltas-i,
                              resultadosConocidos)
            if numeroMonedas < minMonedas:
                minMonedas = numeroMonedas
                resultadosConocidos[vueltas] = minMonedas
    return minMonedas

print(vueltasRecB([1,5,10,25],63,[0]*64))