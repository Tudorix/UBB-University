## REFACTORIZAREA BUCLELOR

Buclele clasice au fost înlocuite cu operații funcționale pentru procesarea colecțiilor.

| Clasa | Metoda | Înainte | După |
|---|---|---|---|
| `UserService` | `exists()` | Parcurgerea utilizatorilor și compararea ID-urilor | `anyMatch()` |
| `UserService` | `removeUser()` | Parcurgerea prieteniilor și ștergerea celor asociate utilizatorului | `filter()`, `map()`, `forEach()` |
| `UserService` | `getFriends()` | Parcurgerea prieteniilor și construirea listei de prieteni | `filter()`, `map()`, `toList()` |
| `FriendshipService` | `existsFriendship()` | Parcurgerea prieteniilor pentru verificarea existenței | `anyMatch()` |
| `AbstractFileRepository` | `writeToFile()` | Parcurgerea entităților și conversia în text | `map()`, `toList()` |

Operațiile intermediare, precum `filter()` și `map()`, sunt evaluate lazy. Operațiile terminale, precum `anyMatch()`, `forEach()` și `toList()`, declanșează procesarea.

## INTERFEȚE FUNCȚIONALE

- **Validator<T>** – utilizată pentru validarea entităților. Metoda `andThen()` permite combinarea regulilor de validare, inclusiv a celor definite prin lambda.

- **Predicate<T>** – utilizată în `Repository.findAll(Predicate<E>)` pentru filtrarea entităților. Predicate-urile pot fi combinate prin `and()`, `or()` și `negate()`.

- **Function<T,R>** – utilizată în operațiile `map()` pentru transformarea elementelor, de exemplu transformarea prieteniilor în ID-uri.

- **Consumer<T>** – utilizată în `forEach()` pentru executarea acțiunilor asupra elementelor, de exemplu ștergerea prieteniilor.

- **Supplier<T>** – utilizată în `RepositoryFactory`. Fiecare tip de persistență este asociat unui Supplier, care construiește repository-ul corespunzător la apelarea metodei `get()`.

## OPTIONAL ÎN REPOSITORY

Am păstrat contractul existent al interfeței `Repository`, unde `findOne()` returnează `null` dacă entitatea nu există.

În `UserService`, rezultatul este tratat folosind `Optional.ofNullable()` și `orElseThrow()`.

Am ales această variantă pentru a evita modificarea tuturor implementărilor repository-ului, gestionând explicit valorile absente la nivelul service-ului.

## PERSISTENȚA ÎN FIȘIERE

Am păstrat șablonul de proiectare **Template Method**.

`AbstractFileRepository` conține logica generală de citire și scriere a fișierelor, iar subclasele implementează conversia dintre text și entități.

În `loadData()` se utilizează `Files.lines()` și `IntStream.range()` pentru citirea și procesarea liniilor.

În `writeToFile()` se utilizează `map(this::createEntityAsString)` pentru conversia entităților în text și `Files.write()` pentru salvare.

Am păstrat Template Method deoarece permite reutilizarea structurii existente și separarea logicii de persistență de conversia entităților.

Alternativa ar fi fost utilizarea unui repository generic care primește funcții `Function<String, E>` și `Function<E, String>` prin constructor.

## BUCLE CLASICE PĂSTRATE

Operațiile obișnuite de procesare a colecțiilor din service și repository au fost refactorizate folosind Stream API.
Algoritmii de graf utilizează în continuare parcurgerea DFS pentru determinarea comunităților.
Aceasta este o parcurgere recursivă, necesară explorării componentelor conexe.

ALTE CONCEPTE UTILIZATE

- **Method References** – utilizate pentru apelarea metodelor existente, precum `Friendship::getId` și `friendshipRepo::delete`.
- **Default Methods** – utilizate în `Repository` pentru implementarea metodei `findAll(Predicate<E>)` și în `Validator` pentru `andThen()`.
- **StreamSupport** – utilizat pentru transformarea rezultatelor de tip `Iterable` în `Stream`.
- **Optional** – utilizat pentru tratarea valorilor absente fără verificări explicite repetate împotriva lui `null`.
- **IntStream** – utilizat pentru procesarea liniilor fișierelor pe baza indicilor, permițând identificarea liniilor invalide.
- **Lazy Evaluation** – operațiile intermediare ale Stream-urilor sunt executate doar la apelarea unei operații terminale.