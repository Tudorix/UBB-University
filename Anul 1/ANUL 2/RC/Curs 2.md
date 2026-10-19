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
==🔴send()==
==🔴recv()==

| Client --- | --> Server       |
| ---------- | ---------------- |
|            | IP server : PORT |
2 Procese pot ocupa acelasi port daca:
- Unu e TCP, unu e UDP
- Daca are mai mult de o adresa IP (Wifi, Date Mobile)

**SERVER**
```
s = socket(AF_INET, SOCK_STREAM,0);

bind(s,{PORT,INADDR_ANY}); // < 0 ?

listen(s,5);
while(1){
	c_ = accept(s,&{IP Client,PORT Client});
	if(fork() == 0){
		recv(c_);
		send(c_);
		
		close(c_);
		exit(0);
	}
}
```

**CLIENT**
```
c = socket(...);

connect(c,{AF_INET,IP,PORT},sizeof(struct_de_adresare)); // < 0?
send(c);
recv(c);

close(c);
```

AF_INET ~ IPv4
SOCK_STREAM ~ TCP
INADDR_ANY  ~ Orice adresa IP (0.0.0.0)

MSG_WAITALL

**Status Signal**
Pentru a vedea pe ce caz de executie a ajuns server, se trimite un 
mesaj de status(send(200), send(429))



