## 1. OOP – Object-Oriented Programming

**OOP (Programare Orientată pe Obiecte)** este o paradigmă de programare care organizează codul în clase și obiecte.

### Cele 4 principii fundamentale OOP

**1. Encapsulation (Încapsulare)**

- Ascunderea datelor interne ale unui obiect.
- Accesul la date se face prin metode controlate.
- Protejează obiectul împotriva modificărilor nedorite.

**2. Abstraction (Abstractizare)**

- Ascunderea detaliilor de implementare.
- Expunerea doar a funcționalităților importante.
- Ne interesează _ce face_ un obiect, nu neapărat _cum face_.

**3. Inheritance (Moștenire)**

- Permite unei clase să moștenească atribute și metode de la altă clasă.
- Ajută la reutilizarea codului și la crearea ierarhiilor de clase.

**4. Polymorphism (Polimorfism)**

- Permite tratarea obiectelor de tipuri diferite printr-un tip comun.
- Aceeași metodă poate avea comportamente diferite în funcție de implementarea obiectului.

---

## 2. SOLID – Principii de proiectare OOP

SOLID reprezintă cinci principii care ajută la construirea unui cod **modular, flexibil, ușor de întreținut și extins**.

### S – Single Responsibility Principle (SRP)

**Principiul responsabilității unice**

- O clasă ar trebui să aibă o singură responsabilitate principală.
- O clasă ar trebui să aibă un singur motiv de schimbare.
- Evităm clasele care se ocupă de prea multe lucruri.

### O – Open/Closed Principle (OCP)

**Principiul deschis/închis**

- Codul trebuie să fie **deschis pentru extindere, dar închis pentru modificare**.
- Ar trebui să putem adăuga funcționalități noi fără să modificăm codul existent.
- Se realizează frecvent folosind interfețe, abstractizare și polimorfism.

### L – Liskov Substitution Principle (LSP)

**Principiul substituției Liskov**

- Un obiect al unei clase derivate trebuie să poată înlocui un obiect al clasei de bază fără să afecteze corectitudinea programului.
- Clasele derivate trebuie să respecte comportamentul promis de clasa de bază.
- Se aplică și claselor care implementează interfețe.

### I – Interface Segregation Principle (ISP)

**Principiul segregării interfețelor**

- Este preferabil să avem mai multe interfețe mici și specifice decât una mare și generală.
- O clasă nu ar trebui să fie obligată să implementeze metode de care nu are nevoie.
- Interfețele trebuie să conțină doar funcționalitățile relevante.

### D – Dependency Inversion Principle (DIP)

**Principiul inversării dependențelor**

- Clasele de nivel înalt nu trebuie să depindă direct de clasele concrete de nivel inferior.
- Ambele trebuie să depindă de abstracții.
- Abstracțiile nu trebuie să depindă de implementări, ci implementările de abstracții.
- Reduce cuplarea dintre componente.

---

## 3. Design Patterns – Șabloane de proiectare

**Design Patterns** sunt soluții generale, reutilizabile, pentru probleme frecvente de proiectare software.

Nu reprezintă cod gata scris, ci modele de organizare a claselor și a relațiilor dintre ele.

Există trei categorii principale:

- **Creational Patterns** – se ocupă de crearea obiectelor.
- **Structural Patterns** – se ocupă de organizarea și combinarea claselor și obiectelor.
- **Behavioral Patterns** – se ocupă de comportamentul și comunicarea dintre obiecte.

### Strategy Pattern (Behavioral)

**Strategy Pattern** permite definirea mai multor algoritmi care realizează aceeași responsabilitate, încapsularea lor separată și schimbarea algoritmului utilizat fără modificarea codului care îl folosește.

Caracteristici:

- Definește o interfață comună pentru algoritmi.
- Fiecare algoritm are propria implementare.
- Algoritmii sunt interschimbabili.
- Clasa care îi utilizează nu trebuie să cunoască detaliile implementării.

**Principii asociate:** OCP, DIP și polimorfism.

### Factory Pattern (Creational)

**Factory Pattern** separă logica de creare a obiectelor de codul care le utilizează.

Caracteristici:

- Centralizează crearea obiectelor.
- Ascunde detaliile instanțierii.
- Reduce dependențele directe față de clasele concrete.
- Facilitează gestionarea diferitelor tipuri de obiecte.

---

## 4. Alte concepte OOP importante

|Concept|Definiție|
|---|---|
|**Class**|Șablon care definește atributele și comportamentul obiectelor.|
|**Object**|Instanță a unei clase.|
|**Interface**|Contract care definește comportamente pe care clasele implementatoare trebuie să le ofere.|
|**Abstract Class**|Clasă care nu poate fi instanțiată direct și poate conține atât metode implementate, cât și metode abstracte.|
|**Coupling**|Gradul de dependență dintre clase. Cu cât este mai redus, cu atât componentele sunt mai independente.|
|**Cohesion**|Gradul în care elementele unei clase contribuie la aceeași responsabilitate. O coeziune ridicată este de preferat.|
|**Composition**|Construirea unui obiect folosind alte obiecte drept componente.|
|**Dependency Injection**|Furnizarea dependențelor unui obiect din exterior, în loc ca acesta să le creeze singur.|

---

### 5. Diferența dintre OOP, SOLID și Design Patterns

**OOP** → Modul în care organizăm și construim programe folosind obiecte.

**SOLID** → Principii care ne ajută să proiectăm corect clasele și relațiile dintre ele.

**Design Patterns** → Soluții de proiectare reutilizabile pentru probleme care apar frecvent în OOP.

**Pe scurt:**

- OOP îți oferă instrumentele.
- SOLID îți spune cum să le folosești bine.
- Design Patterns îți oferă modele consacrate de organizare a lor.