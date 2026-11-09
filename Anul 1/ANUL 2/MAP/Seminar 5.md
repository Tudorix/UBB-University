# Interfata Functionala
- O interfata cu o singura metoda abstarcta

Implmentare:
- Clasa Concreta
- Clasa Anonima
```
Operation o = new Operation(){
	int compute(int x){
		return x * x;
	}
};
```
- Expresie Lambda (parametrii) -> expresie
```
Operation o = x -> 6*7;
```
- Referinta la o alta metoda
```
Operation o = Math::abs; // Clase statice
```

# Default Methods
```
default void print(){
	...
}
```

# Predicate
- Testeaza o conditie pe o entitate generica

```
.and()
.or()
.negate()
Predicate.not()
```

# Consumer
```
void accept(T t);

Consumer<String> c = s -> String.out.println(s);
```
