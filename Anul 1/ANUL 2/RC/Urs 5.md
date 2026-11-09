Time to Live: o parte din headeru IP care se decrementeaza la fiecare router pprin care trece -> ca sa nu circule internetu prea mult

# Tipuri de trafic
1) Unicast (1:1)
2) Broadcast (specific ==🟣retelelor cu difuzare==); ex: LAN
	1) Deviceurile trimit mesaje la tote deviceurile din retea: 
		1) Semnal de a primi un IP -> RAspunde DHCP
		2) Up signal (Deviceuri cu casting)
3) Multicast(1:N)
4) Anycast(1:Any)

```
STIVA TCP:
-----------------|
Web              |
-----------------|
Aplicatie        | 
_send()/revc()___| ----> S C E
Transport   UDP  | ---->  O K T
____________TCP__|
Retea(Internet)  |
_____________IP__|
Data Link + Fizic|
_________________|
```

Nivelu data link dauaga adresele MAC - FRAME
## Adresele MAC (hardware)
==🟠6Octeti:==
1) Primii 3 octeti - Producatorul Deviceului
2) Ultimill 3 - Serial - cod 'unic'

FF:FF:FF:FF:FF:FF -> Mac **DESTINATIE** de Broadcast (Ca sa ajunga la toti)
# Topologii de retele
1) Retele cu topologie BUS (liniar)
2) Retele cu topologie STEA -> HUB - SWITCH (Deviceuri conectate in paralel)
	1) HUB - Repeates de date
	2) SWITCH - Numeroteaza porturile - trimite informatia unde trebuie, nu la toti
3) Retele cu topologie STEA-EXTINSA (Switch central -> Switchuri Secundare)
4) Retele de tip GRAF