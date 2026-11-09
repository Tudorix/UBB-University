package Validator;

import Domain.Entity;

@FunctionalInterface
public interface Validator<T> {
    void validate(T entity);

    default Validator<T> andThen(Validator<T> other){
        return entity ->{
            this.validate(entity);
            other.validate(entity);
        };
    }
}
