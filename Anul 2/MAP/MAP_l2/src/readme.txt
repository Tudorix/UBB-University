LABORATOR 3 – REȚEA DE SOCIALIZARE
=================================

1. DESCRIERE
Aplicația gestionează utilizatori și prietenii. Păstrează funcționalitățile
laboratorului 2 și permite alegerea tipului de persistență prin configurare.

2. REPOSITORY FACTORY ȘI CONFIGURARE
RepositoryFactory creează repository-urile în funcție de proprietatea
repository.type din config.properties:
- MEMORY: repository-uri în memorie;
- FILE: repository-uri cu persistență în fișiere text;
- DATABASE: repository-uri pentru baza de date (momentan doar schelete).

Factory-ul creează mai întâi repository-ul de utilizatori, apoi pe cel de
prietenii, căruia îi transmite repository-ul de utilizatori pentru a putea
verifica existența persoanelor asociate unei prietenii.

Pentru trecerea la DATABASE, în laboratorul 4 trebuie implementate metodele
repository-urilor DB, apoi schimbată proprietatea repository.type=DATABASE.
Clasele domain, service și UI nu trebuie modificate pentru această trecere.

3. PERSISTENȚA ÎN FIȘIERE ȘI TRATAREA ERORILOR
AbstractFileRepository conține logica comună de citire și scriere în fișier.
La pornire sunt încărcate entitățile și validate; după operațiile reușite
save, delete și update, conținutul fișierului este rescris.

Dacă fișierul nu există, repository-ul pornește gol. Fișierul este creat
la prima salvare reușită.

Dacă o linie este coruptă sau conține date invalide, aplicația afișează
numărul liniei și motivul, ignoră acea linie și continuă încărcarea.
Această abordare permite recuperarea celorlalte date valide fără oprirea
întregii aplicații.

Operațiile de citire/scriere folosesc UTF-8 și try-with-resources.
Erorile de persistență care nu pot fi recuperate sunt semnalate prin
RepositoryException, păstrând cauza inițială (exception chaining).

La eliminarea unui utilizator sunt eliminate și prieteniile asociate,
pentru a păstra consistența datelor.

4. PRINCIPII SOLID
- SRP (Single Responsibility Principle): clasele domain reprezintă
  entitățile; validatorii verifică datele; repository-urile gestionează
  stocarea; service-ul gestionează logica aplicației.
- DIP (Dependency Inversion Principle): service-ul lucrează cu abstracția
  Repository, nu direct cu implementările pentru memorie sau fișier.
- OCP (Open/Closed Principle): pot fi adăugate implementări noi ale
  Repository fără modificarea logicii din service. În schimb, un
  Simple Factory bazat pe switch trebuie modificat pentru un nou tip.
- LSP (Liskov Substitution Principle): implementările Repository trebuie
  să respecte același contract al interfeței, inclusiv valorile returnate
  și excepțiile documentate.

5. DESIGN PATTERNS
- Factory: RepositoryFactory centralizează alegerea și construirea
  repository-urilor în funcție de configurație.
- Template Method: AbstractFileRepository definește algoritmul comun
  de încărcare și salvare, iar subclasele furnizează conversia
  extractEntity / createEntityAsString.
- Strategy: implementările Repository pot fi schimbate în funcție de
  modul de persistență, fără schimbarea codului client din service.
- Decorator: BufferedReader și BufferedWriter adaugă buffering peste
  FileReader și FileWriter.

6. SIMPLE FACTORY VS. ABSTRACT FACTORY (OCP)
Simple Factory este mai simplu de implementat și centralizează crearea
obiectelor. Dezavantajul este că adăugarea unui tip nou de persistență
necesită modificarea switch-ului din factory, ceea ce limitează OCP.

Abstract Factory folosește o interfață pentru fabrici și implementări
distincte (de exemplu FileRepositoryFactory și DbRepositoryFactory).
Astfel, un nou tip de persistență poate fi adăugat printr-o fabrică nouă,
fără modificarea fabricilor existente. Dezavantajul este numărul mai mare
de clase și complexitatea suplimentară pentru un proiect mic.

7. VALIDAREA
Validarea entităților se realizează în repository, astfel încât regulile
să fie aplicate indiferent dacă datele provin din UI sau din fișiere.
Verificarea existenței utilizatorilor unei prietenii este realizată
separat, folosind repository-ul de utilizatori.

