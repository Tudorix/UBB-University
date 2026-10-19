package repository;

import java.util.HashMap;
import java.util.Map;

public class InMemoryRepository<ID, E extends model.Entity<ID>> implements Repository<ID, E> {
    private Map<ID, E> entities = new HashMap<>();

    @Override
    public E findOne(ID id) {
        if (id == null) {
            throw new IllegalArgumentException("ID must not be null");
        }
        return entities.get(id);
    }

    @Override
    public Iterable<E> findAll() {
        return entities.values();
    }

    @Override
    public E save(E entity) {
        if (entity == null) {
            throw new IllegalArgumentException("Entity must not be null");
        }
        if (entities.containsKey(entity.getId())) {
            return entity; // Entity with this ID already exists
        }
        entities.put(entity.getId(), entity);
        return null; // Successfully saved
    }

    @Override
    public E delete(ID id) {
        if (id == null) {
            throw new IllegalArgumentException("ID must not be null");
        }
        return entities.remove(id);
    }

    @Override
    public E update(E entity) {
        if (entity == null) {
            throw new IllegalArgumentException("Entity must not be null");
        }
        if (!entities.containsKey(entity.getId())) {
            return entity; // Entity with this ID does not exist
        }
        entities.put(entity.getId(), entity);
        return null; // Successfully updated
    }
}
