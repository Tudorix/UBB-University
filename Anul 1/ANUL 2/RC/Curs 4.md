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

## Headere

Nivel Aplicatie : adauga un ANtet, un header informatiei transmise acre e utilizata de 
aplicatiile reciever

Nivelul Transport adauga la rnadul lui headere.

## Transport

Pachetele pot fii transmise pe drumuri diferite si pot ajunge ==🔴OUT OF ORDER==, motiv pentru care TCP trimite in antet multi informatii, printre care si numerotarea pachetelor.
- PORT Sursa
- PORT Destinatie
- Numerotare Pachete
- Confirmare Pachete
## Retea

Reteaua adauga la randu ei un antet:
- IP Sursa
- IP Destinatie

## Data Link

Antet:
- MAC Sursa
- MAC Destinatie

---
# Rata transport

Pentru ca compensa diferentele de viteze citire/scriere, trebuie sa se infraneze senderul daca este mai capabil pentru ca lasa recieverul sa tina pasul cu informatiile trimise

TCP - are in antet un camp prin care confirma primirea pachetelor

1 Pchet -> trimitere -> Ajuns
<---------------------- TCP trimite inapoi o confirmare (un pachet fara IU, doar cu header, in care scrie
==🟣ce pachete asteapta==)

2 Pachete -------> TCP
4 Pachete -------> TCP
8 ....
16... => ==🟢se dubleaza cand se trimite si ajunge cu success==

## RTT = Round Trip Time
-> Cat ii ia IU sa ajunga de la sursa la destinatie + in cat timp ajunge ack inapoi la sursa

## RTO = Retrnasmisssion Timeout
-> Delay de retransmitere a unui pachet
**f(RTT, DRTT)

ACK -> Numeroteaza octetii circulati

# 3 Way Handshake

Intre connect si accept se face 3 way handshake - se ocupa de asta TCP IP

1 --------------------------> SYN = 1
2 <------------- SYN = 1, ACK = 1
3 --------------------------> ACK = 1

close(c) -------> FIN =1 

## RED
Algoritm care arunca pachete (mai) cinstit intre TCP si UDP





