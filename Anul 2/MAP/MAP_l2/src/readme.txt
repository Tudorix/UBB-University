ESCRIERE
Aplicația gestionează utilizatori și prietenii. Păstrează funcționalitățile
laboratorului 2 și permite alegerea tipului de persistență prin configurare.

REPOSITORY FACTORY
RepositoryFactory creează repository-urile în funcție de proprietatea
repository.type din config.properties:
- MEMORY: repository-uri în memorie;
- FILE: repository-uri cu persistență în fișiere text;
- DATABASE: repository-uri pentru baza de date (momentan doar schelete).

Factory-ul creează mai întâi repository-ul de utilizatori, apoi pe cel de
prietenii, căruia îi transmite repository-ul de utilizatori pentru a putea
verifica existența persoanelor asociate unei prietenii.

PERSISTENȚA ÎN FIȘIERE ȘI TRATAREA ERORILOR
AbstractFileRepository conține logica comună de citire și scriere în fișier.
La pornire sunt încărcate entitățile și validate; după operațiile reușite
save, delete și update, conținutul fișierului este rescris.

Dacă o linie este coruptă sau conține date invalide, aplicația afișează
numărul liniei și motivul, ignoră acea linie și continuă încărcarea.
Această abordare permite recuperarea celorlalte date valide fără oprirea
întregii aplicații.

PRINCIPII SOLID
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

DESIGN PATTERNS
- Factory: RepositoryFactory centralizează alegerea și construirea
  repository-urilor în funcție de configurație.
- Template Method: AbstractFileRepository definește algoritmul comun
  de încărcare și salvare, iar subclasele furnizează conversia
  extractEntity / createEntityAsString.
- Strategy: implementările Repository pot fi schimbate în funcție de
  modul de persistență, fără schimbarea codului client din service.
- Decorator: BufferedReader și BufferedWriter adaugă buffering peste
  FileReader și FileWriter.

