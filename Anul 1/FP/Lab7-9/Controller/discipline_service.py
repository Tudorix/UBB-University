from Domain.disciplina import Disciplina

class ServiceDiscipline:
    def __init__(self, ValidatorDisciplina, RepoDisciplina):
        """
            Constructorul clasei ServiceDiscipline
            @param ValidatorDisciplina - ValidatorDisciplina
            @param RepoDisciplina - DisciplinaRepo
        """
        self.__validatorDisciplina = ValidatorDisciplina
        self.__repoDisciplina = RepoDisciplina
        
    def reset_list(self):
        """
            Functie care reseteaza lista de discipline
        """
        self.__repoDisciplina.rst()
        
    def get_discipline(self):
        """ 
            Functie care returneza lista curenta de discipline
        """
        return self.__repoDisciplina.getList()
    
    def cautare_disciplina(self, args):
        """ 
            Functie care cauta o disciplina
            @param args - lista
            Raise - Exeption
        """
        if len(args) != 2:
            raise Exception
        
        case = 0
        if args[0] == "ID" : 
            case = 1
            try:
                self.__validatorDisciplina.validareID(args[1])
            except:
                raise Exception
        elif args[0] == "Nume" :
            case = 2
            try:
                self.__validatorDisciplina.validareCuvant(args[1])
            except:
                raise Exception
        elif args[0] == "Profesor" : 
            case = 3
            try:
                self.__validatorDisciplina.validareCuvant(args[1])
            except:
                raise Exception
        else : raise Exception
        
        lista_filtrata = []
        
        for e in self.get_discipline():
            if (case == 1 and e.getID() == int(args[1])) or (case == 2 and e.getNume() == args[1]) or (case == 3 and e.getProfesor() == args[1]):
                lista_filtrata.append(e)
        
        return lista_filtrata

    def adauga_disciplina(self , ID, Nume, Profesor):
        """
            Functie care adauga disciplina in lista de discipline
            @param ID - int
            @param Nume - string
            @param Profesor - string
            Raise - ValueError
        """
        disciplina = Disciplina(ID , Nume.strip(), Profesor.strip())
        try:
            self.__validatorDisciplina.validareDiscilina(disciplina)
        except:
            raise ValueError
        
        self.__repoDisciplina.adauga_disciplina(disciplina)
        
    def sterge_disciplina(self, ID):
        """
            Functie care sterge disciplina din lista de discipline
            @param ID - int
            Raise - ValueError
        """
        try:
            self.__validatorDisciplina.validareID(ID)
        except:
            raise ValueError

        self.__repoDisciplina.sterge_disciplina(ID)
        
    def update_disciplina(self,idDisciplina , newId , Nume, Profesor):
        """
            Functie care modifica disciplina din lista de discipline
            @param idDisciplina - string
            @param newId - int
            @param Nume - string
            @param Profesor - string
            Raise - ValueError - Invalid Disciplina
            Raise - IndexError - Invalid ID
        """
        disciplina = Disciplina(newId , Nume, Profesor)
        try:
            self.__validatorDisciplina.validareDiscilina(disciplina)
        except:
            raise ValueError
        
        try:
            self.__validatorDisciplina.validareID(idDisciplina)
        except:
            raise IndexError
        
        self.__repoDisciplina.update_disciplina(idDisciplina, disciplina)