Laborator 1 – MAP
Calculator de expresii cu numere complexe

Descrierea proiectului

Aplicatia primeste din linia de comanda o expresie aritmetica formata din numere complexe si un operator repetat (+, -, * sau /).
Expresia este validata, numerele sunt interpretate, iar rezultatul este calculat si afisat.

Principii SOLID urmarite

- SRP (Single Responsibility Principle): responsabilitatile sunt separate intre modelarea numerelor, parsare si evaluare. Fiecare clasa are un rol bine delimitat.
- OCP (Open/Closed Principle): ExpressionEvaluator poate folosi o implementare noua de Operation fara modificarea algoritmului sau de evaluare.
- LSP (Liskov Substitution Principle): implementari diferite ale interfetei Operation pot fi substituite in evaluator,
atat timp cat respecta contractul metodei execute.
- ISP (Interface Segregation Principle): interfata Operation este restransa la o singura responsabilitate.
- DIP (Dependency Inversion Principle): ExpressionEvaluator depinde de abstractia Operation.

Design Pattern utilizat

Strategy : interfata Operation defineste strategia comuna,iar Addition, Subtraction, Multiplication si Division
reprezinta strategii concrete. ExpressionEvaluator este contextul care foloseste strategia primita.
Algoritmul de evaluare ramane acelasi, indiferent de operatia aleasa.

Reflectarea conceptelor in diagrama UML

-ComplexNumber – clasa care modelează un număr complex, stocând partea reală și partea imaginară.
-ComplexNumberParser – responsabilă cu transformarea unui șir de caractere într-un obiect de tip ComplexNumber.
-ExpressionParser – responsabilă cu interpretarea și validarea expresiei aritmetice. Stochează numerele complexe într-un array și operatorul utilizat.
-Operation – interfață care definește metoda execute(), reprezentând contractul comun pentru efectuarea operațiilor aritmetice.
-Addition, Subtraction, Multiplication, Division – clase care implementează interfața Operation, fiecare definind comportamentul specific unei operații matematice.
-ExpressionEvaluator – responsabilă cu evaluarea întregii expresii. Deține o referință de tip Operation și aplică succesiv metoda execute() asupra numerelor complexe.