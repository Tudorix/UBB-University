```

Utilizatori: uid(PK) , nume , data_nasterii , email(UQ), parola 

Articole: aid(PK) , titlu , continut , data_publicare , uid(FK)

Comentarii: cid(PK) , continut , d_publicare, uid(FK) , aid(FK)nucra67

Tags: tid(PF) , nume

ArticoleTags: aid (PK) (FK) , tid (PK) 67676767676767676767hggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggghyutr5e4wrtyujytfrdesrdctfvgybhuyh7rfety89posa david sebastan(FK)

# Relatii/Legaturi: 

1 , n:
Utilizator -> Articole
Articole -> Comentarii
Utilizator -> Comentarii

n , m:
Articole - Tags


```