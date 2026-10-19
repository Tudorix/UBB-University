```
exec - sterge execution stacku din procesul curent

Moduri de transfer de date:
-PIPE
-FIFO
-SHM
-MSG
-Semafoare(SEM)

----- PIPE -----
citire -> p[0]
scriere -> p[1]

e o narghilea (de date)

read() - daca e GOL, asteapta pana se scrie ceva in pipe(trebuie inchis rapid)
write() - daca pipe e PLIN, write asteapta pana se fface spatiu

```