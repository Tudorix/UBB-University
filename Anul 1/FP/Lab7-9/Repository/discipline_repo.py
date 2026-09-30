from Domain.disciplina import Disciplina
class DisciplineRepo:
    def __init__(self , fileName):
        """
            Constructorul clasei DisciplineRepo
        """
        self.__lista_discipline = []
        self.__fileName = fileName
        self.load_from_file()
        
    def getList(self):
        """ 
            Functie care returneaza lista de discipline
        """
        #self.load_from_file()
        return self.__lista_discipline
        
    def rst(self):
        """
            Functie care reseteaza lista de discipline
        """
        self.__lista_discipline = []
        self.load_in_file()
        
    def get_by_id(self, ID):
        """
            Functie care returneaza disciplina daca ID exista in lista
            @param ID - int
            Raise - IndexError 
        """
        for e in self.__lista_discipline:
            if ID == e.getID():
                return e
        raise IndexError

    def exista_ID(self, ID):
        """
            Functie care verifica unicitatea ID-ului specificat
            @param ID - int
        """
        for e in self.__lista_discipline:
            if ID == e.getID():
                return True
        return False

    def adauga_disciplina(self, disciplina):
        """
            Functie care adauga disciplina in lista de discipline
            @param disciplina - Disciplina
            Raise - IndexError 
        """
        if self.exista_ID(disciplina.getID()):
            raise IndexError
        else:
            self.__lista_discipline.append(disciplina)
            self.load_in_file()
            
        
    def sterge_disciplina(self, ID):
        """
            Functie care sterge disciplina din lista de discipline
            @param ID - string
            Raise - MemoryError
        """
        for i in range(len(self.__lista_discipline)):
            if self.__lista_discipline[i].getID() == int(ID):
                del self.__lista_discipline[i]
                self.load_in_file()
                return
        raise MemoryError
        
    def update_disciplina(self , ID , disciplina):
        """
            Functie care modifica o disciplina din lista de discipline
            @param ID - string
            @param newID - int
            @param Nume - string
            @param Profesor - string
            Raise - MemoryError
        """
        if self.exista_ID(disciplina.getID()) and int(ID) != disciplina.getID():
            print("There is another Discipline with this ID")
        else:
            for i in range(len(self.__lista_discipline)):
                if self.__lista_discipline[i].getID() == int(ID):
                    self.__lista_discipline[i] = disciplina
                    self.load_in_file()
                    return
                
            raise MemoryError
        
    def load_from_file(self):
        """  
            Functie care incarca informatii din fisier
        """
        with open(self.__fileName , "r") as f:
            #reset list
            self.__lista_discipline.clear()
            #take info
            lines = f.readlines()
            for l in lines:
                parts = l.split(",")
                #Take info
                ID = int(parts[0])
                Nume = parts[1]
                Profesor = parts[2]
                disciplina = Disciplina(ID , Nume , Profesor)
                self.__lista_discipline.append(disciplina)
    
    def load_in_file(self):
        """  
            Functie care incarca informatii in fisier
        """
        with open(self.__fileName , "w") as f:
            for i in self.__lista_discipline:
                f.write(f"{i.getID()},{i.getNume()},{i.getProfesor()}\n")

