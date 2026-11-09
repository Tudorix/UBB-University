package Repository.file;

import Domain.Entity;
import Exceptions.RepositoryException;
import Exceptions.ValidationException;
import Repository.InMemoryRepository;
import Validator.Validator;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.NoSuchFileException;
import java.nio.file.Paths;
import java.time.format.DateTimeParseException;
import java.util.List;
import java.util.stream.IntStream;
import java.util.stream.Stream;
import java.util.stream.StreamSupport;

public abstract class AbstractFileRepository<ID, E extends Entity<ID>> extends InMemoryRepository<ID,E> {

    private final String filename;

    public AbstractFileRepository(Validator<E> validator, String filename) {
        super(validator);
        this.filename = filename;
    }

    protected abstract E extractEntity(String line);

    protected abstract String createEntityAsString(E entity);

    protected void loadData(){
        try(Stream<String> stream = Files.lines(Paths.get(filename), StandardCharsets.UTF_8)){
            List<String> lines = stream.toList();

            IntStream.range(0, lines.size())
                    .forEach(i -> {
                        String line = lines.get(i);
                        int lineNumber = i + 1;
                        try {
                            E e = extractEntity(line);
                            super.save(e);
                        }catch (ValidationException | IllegalArgumentException e){
                            System.err.println("Invalid line " + lineNumber + ": " + e.getMessage());
                        }
                    });
        }catch (NoSuchFileException e){
            System.out.println("File not found: " + filename + ". Starting with empty repository.");
        }catch (IOException e){
            throw new RepositoryException("Error while reading from the file " + filename, e);
        }catch (ValidationException e){
            throw new RepositoryException("User not found" ,e);
        }
    }

    private void writeToFile() {
        try{
            List<String> lines = StreamSupport.stream(findAll().spliterator(),false).map(this::createEntityAsString).toList();
            Files.write(Paths.get(filename), lines, StandardCharsets.UTF_8);
        }catch (IOException e){
            throw new RepositoryException("Error in wrtitng in file " + filename, e);
        }
    }

    @Override
    public E save(E entity){
        E result = super.save(entity);
        if(result == null){
            writeToFile();
        }
        return result;
    }

    @Override
    public E delete(ID id) {
        E result = super.delete(id);
        if (result != null)
            writeToFile();
        return result;
    }

    @Override
    public E update(E entity) {
        E result = super.update(entity);
        if (result == null)
            writeToFile();
        return result;
    }
}
