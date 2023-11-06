import multiprocessing as mp
from multiprocessing import Pool

#serie par: i*2; impar: i*i+1: 0,2,4,10,8,26,12,50,16,82,...

def serie(inicial, limite):
  w=[]
  for i in range(inicial, limite):
    if i%2==0:
      ita=par(i)
    else:
      ita=impar(i)
    w.append(round(ita))

  return w

def impar(n):
    return (n*n)+1 

def par(n):
    return n * 2 


if __name__=="__main__":
  limite=int(10000/mp.cpu_count())
  entradas = [(i*limite, limite*(i+1)) for i in range(mp.cpu_count())]

  pool=Pool()
  resultado = pool.starmap(serie, entradas)
  print(entradas, resultado[0])
