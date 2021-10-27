def vueltasRec(listaValoresMonedas,vueltas):
   minMonedas = vueltas
   if vueltas in listaValoresMonedas:
     return 1
   else:
      for i in [m for m in listaValoresMonedas if m <= vueltas]:
         numeroMonedas = 1 + vueltasRec(listaValoresMonedas,vueltas-i)
         if numeroMonedas < minMonedas:
            minMonedas = numeroMonedas
   return minMonedas

print(vueltasRec([1,5,10,25],63))