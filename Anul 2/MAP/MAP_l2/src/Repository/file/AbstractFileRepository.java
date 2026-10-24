package Repository.file;

import Domain.Entity;
import Exceptions.RepositoryException;
import Exceptions.ValidationException;
import Repository.InMemoryRepository;
import Validator.Validator;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.time.format.DateTimeParseException;
import java.util.Map;

public abstract class AbstractFileRepository<ID, E extends Entity<ID>> extends InMemoryRepository<ID,E> {

    private final String filename;

    public AbstractFileRepository(Validator<E> validator, String filename) {
        super(validator);
        this.filename = filename;
    }

    protected abstract E extractEntity(String line);

    protected abstract String createEntityAsString(E entity);

    protected void loadData(){
        try(BufferedReader reader = new BufferedReader(new FileReader(filename, StandardCharsets.UTF_8))){
            String line;
            int lineNumber = 0;

            while ((line = reader.readLine()) != null) {
                lineNumber++;

                try {
                    E entity = extractEntity(line);
                    super.save(entity);

                } catch (ValidationException | IllegalArgumentException | DateTimeParseException e) {
                    System.err.println(
                            "Invalid line " + lineNumber + ": " + e.getMessage()
                    );
                }
            }
        }catch (FileNotFoundException e){
            System.out.println("File not found: " + filename + ". Starting with empty repository.");

        }catch (IOException e){
            throw new RepositoryException("Error while reading from the file " + filename, e);
        }catch (ValidationException e){
            throw new RepositoryException("User not found" ,e);
        }
    }

    private void writeToFile() {
        try(BufferedWriter writer = new BufferedWriter(new FileWriter(filename, StandardCharsets.UTF_8))){
            for(E entity: findAll()){
                writer.write(createEntityAsString(entity));
                writer.newLine();
            }
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
