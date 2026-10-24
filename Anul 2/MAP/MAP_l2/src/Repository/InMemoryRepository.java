package Repository;

import Domain.Entity;
import Validator.Validator;

import java.util.HashMap;
import java.util.Map;

public class InMemoryRepository<ID, E extends Entity<ID>> implements Repository<ID, E> {

    private final Validator<E> validator;
    private final Map<ID, E> entities;

    public InMemoryRepository(Validator<E> validator) {
        this.validator = validator;
        entities = new HashMap<ID,E>();
    }

    /**
     *
     * @param id -the id of the entity to be returned
     *           id must not be null
     * @return the entity
     */
    @Override
    public E findOne(ID id) {
        if (id == null)
            throw new IllegalArgumentException("id must be not null");
        return entities.get(id);
    }

    /**
     *
     * @return list of entities
     */
    @Override
    public Iterable<E> findAll() {
        return entities.values();
    }

    /**
     *
     * @param entity entity must be not null
     * @return the entity if it already exists or null if it doesnt
     *
     * @throws IllegalArgumentException if entity is null
     */
    @Override
    public E save(E entity) {
        if (entity == null)
            throw new IllegalArgumentException("entity must be not null");
        validator.validate(entity);
        if (entities.get(entity.getId()) != null) {
            return entity;
        }
        entities.put(entity.getId(), entity);
        return null;
    }

    /**
     *
     * @param id id must be not null
     * @return
     */
    @Override
    public E delete(ID id) {
        if (id == null)
            throw new IllegalArgumentException("id must be not null");
        return entities.remove(id);
    }

    /**
     *
     * @param entity entity must not be null
     * @return the entity if it exists and null if it dosent
     */
    @Override
    public E update(E entity) {
        if (entity == null){
            throw new IllegalArgumentException("enitity must not be null");
        }
        validator.validate(entity);

        if(!entities.containsKey(entity.getId())){
            return entity;
        }
        entities.put(entity.getId(),entity);
        return null;
    }
}
