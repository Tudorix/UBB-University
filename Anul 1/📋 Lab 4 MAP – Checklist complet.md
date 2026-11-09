**Obiectiv:** Refactorizăm proiectul de la Lab 3 folosind Java 8 (Lambda, Stream API, Optional, Method References).

**Nu adăugăm funcționalități noi!** Aplicația trebuie să funcționeze exact ca înainte.

## ✅ 0. Pregătirea proiectului

- [x] Crearea proiectului Gradle.
- [x] Mutarea codului din Lab 3.
- [x] Configurarea `config.properties`.
- [x] Mutarea fișierelor cu date.
- [x] Verificarea funcționării aplicației.

**GATA!** 🎉

## ⬜ 1. Interfețe funcționale și Lambda (2.5p)

- [x] Adăugăm `@FunctionalInterface` la `Validator<T>`.
- [x] Implementăm metoda `default andThen()`.
- [x] Adăugăm o regulă nouă de validare prin lambda, fără modificarea clasei `UtilizatorValidator`.
- [x] Adăugăm `findAll(Predicate<E>)` în interfața `Repository`.
- [x] Creăm clasa `CriteriiUtilizator`, cu metode statice care returnează `Predicate<Utilizator>`.
- [x] Combinăm filtre folosind `and`, `or`, `negate`, `Predicate.not`.
- [x] Înlocuim `switch` din `RepositoryFactory` cu `Map` + `Supplier` (sau `Function`), pentru ambele repository-uri.
- [x] Alegem între `AbstractFileRepository` și un `FileRepository` generic cu `Function` pentru conversia datelor.

## ⬜ 2. Method References (1p)

Folosim toate cele 4 tipuri, unde au sens:

- [ ] Metodă statică: `CriteriiUtilizator::faraPrieteni`
- [ ] Metodă a unui obiect: `System.out::println`
- [ ] Metodă a unei clase: `Utilizator::getLastName`
- [ ] Constructor: `ArrayList::new`

Înlocuim lambda-urile care doar apelează o metodă existentă cu `::`.

## ⬜ 3. Stream API (3.5p) ⭐

**Cea mai mare parte a laboratorului!**

- [ ] Eliminăm buclele clasice `for`, `while`, `do-while` folosite pentru parcurgerea colecțiilor.
- [ ] Refactorizăm obținerea prietenilor unui utilizator.
- [ ] Refactorizăm ștergerea utilizatorului împreună cu prieteniile sale.
- [ ] Refactorizăm calcularea numărului de comunități.
- [ ] Refactorizăm găsirea celei mai sociabile comunități.
- [ ] Folosim operații precum `filter`, `map`, `flatMap`, `sorted`, `distinct`, `count`, `anyMatch`, `allMatch`, `noneMatch`, `max`, `min`, `reduce`, `collect`.
- [ ] Folosim `Collectors.toList`, `toSet`, `toMap`, `groupingBy`, `counting`, `joining`, unde au sens.
- [ ] Folosim `Comparator.comparing`, `comparingInt`, `thenComparing`, `reversed`.
- [ ] Citim fișierele cu `Files.lines()` și `try-with-resources`.
- [ ] Scriem fișierele cu `Files.write()` și stream-uri.

**Important:** Nu modificăm colecții externe din `filter` sau `map`.

## ⬜ 4. Optional (1p)

- [ ] Folosim `Optional` pentru căutarea utilizatorilor care pot să nu existe.
- [ ] Tratăm rezultatele operațiilor `max`, `min`, `reduce`, `findFirst`.
- [ ] Folosim `orElse`, `orElseThrow`, `ifPresent`, `map`.
- [ ] Evităm `Optional.get()` fără verificare.
- [ ] Decidem dacă `Repository.findOne()` returnează `null` sau `Optional<E>`.

## ⬜ 5. Compatibilitate și documentație (1p)

- [ ] Verificăm că toate funcționalitățile din Lab 3 merg identic.
- [ ] Păstrăm formatul fișierelor.
- [ ] Tratăm fișierele lipsă și liniile corupte, inclusiv numărul liniei.
- [ ] Tratăm excepțiile din lambda.
- [ ] Adăugăm Javadoc în engleză pentru metodele și interfețele noi.

## ⬜ 6. README și predare (1p)

**Creăm `readme.txt` care conține:**

- [ ] Tabel cu minimum 5 bucle înlocuite cu stream-uri (clasă, metodă, operații folosite).
- [ ] Lista interfețelor funcționale utilizate și unde.
- [ ] Justificarea alegerii pentru `Optional` în Repository.
- [ ] Justificarea alegerii între Template Method și `Function`.
- [ ] Explicarea eventualelor bucle păstrate.

**La demonstrație:**

- [ ] Arătăm 3 exemple înainte/după refactorizare.
- [ ] Explicăm operațiile intermediare și terminale din stream-uri.
- [ ] Demonstrăm adăugarea unei reguli de validare prin lambda.
- [ ] Demonstrăm adăugarea unui criteriu nou de căutare prin lambda.
- [ ] Avem proiectul versionat cu Git.

---

### ⚠️ Restricții importante

- Fără bucle clasice pentru colecții în `domain`, `service`, `repository` și `UI`, cu excepții justificate.
- Fără clase anonime când putem folosi lambda.
- Fără biblioteci externe.
- Fără implementarea bazei de date (asta vine la Lab 5).
- Fără modificarea formatului fișierelor.

**Deadline: săptămâna 6.** Lab4_2026-2027_InterfeteFunctio…

---

### 🚀 Ordinea în care îți recomand să lucrăm

**1 → 2 → 3 → 4 → 5 → 6**

Luăm fiecare cerință separat, o implementăm, o testăm și o bifăm.

**Momentan avem pregătirea proiectului completă (0), deci următorul pas este `Validator<T>`!**