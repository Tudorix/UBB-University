from Domain.nota_dto import NotaDTO

class NoteRepo:
    def __init__(self , fileName):
        """
            Constructorul clasei NoteRepo
        """
        self.__lista_note = []
        self.__fileName = fileName
        self.load_from_file()
        
    def get_note(self):
        """ 
            Functie care returneaza lista de note
        """
        self.load_from_file()
        return self.__lista_note
        
    def exista_ID(self, ID):
        """
            Functie care verifica unicitatea ID-ului specificat
            @param ID - int
        """
        for e in self.__lista_note:
            if e.getID() == ID:
                return True
        return False
    
    def rst(self):
        """
            Functie care reseteaza lista de note
        """
        self.__lista_note = []
        #self.load_in_file()
        
    def lenght(self):
        """ 
            Functie ce returneaza lungimea listei de note
        """
        return len(self.__lista_note)
        
    def adauga_nota(self, Nota):
        if self.exista_ID(Nota.getID()):
            print("There is another Nota with that ID")
        else:
            self.__lista_note.append(Nota)
            self.load_in_file()
            
    def sterge_nota(self , ID):
        """
            Functie care sterge nota din lista de note
            @param ID - string
        """
        for i in range(len(self.__lista_note)):
            if self.__lista_note[i].getID() == int(ID):
                del self.__lista_note[i]
                self.load_in_file()
                return
                
        raise MemoryError
    
    def __processLine(self , line):
        """ 
            Functie care proceseaza o lineie din fisier
        """
        parts = line.split(",")
        ID = int(parts[0])
        Valoare = int(parts[1])
        IdStudent = int(parts[2])
        IdDisciplina = int(parts[3])
        nota_dto = NotaDTO(ID , Valoare , IdStudent , IdDisciplina)
        self.__lista_note.append(nota_dto)
    
    def load_from_file(self):
        with open(self.__fileName, "r") as f:
            self.rst()
            lines = f.readlines()
            for l in lines:
                self.__processLine(l)
                
    def load_in_file(self):
        with open(self.__fileName , "w") as f:
            for i in self.__lista_note:
                f.write(f"{i.getID()},{i.getValoare()},{i.getIdStudent()},{i.getIdDisciplina()}\n")