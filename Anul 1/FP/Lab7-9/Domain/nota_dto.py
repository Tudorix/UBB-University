class NotaDTO:
    
    def __init__(self , ID , Valoare , IdStudent , IdDisciplina):
        """
            Functie constructor pentru clasa NotaDTO
            
        :param ID: int
        :param Valoare: int
        :param IdStudent: int
        :param IdDisciplina: int
        """
        self.__ID = ID
        self.__Valoare = Valoare
        self.__IdStudent = IdStudent
        self.__IdDisciplina = IdDisciplina
        
    def getID(self):
        """
            Getter pentru Nota ID
        """
        return self.__ID
    
    def getValoare(self):
        """
            Getter pentru Valoare
        """
        return self.__Valoare
    
    def getIdStudent(self):
        """
            Getter pentru ID Student
        """
        return self.__IdStudent
    
    def getIdDisciplina(self):
        """
            Getter pentru ID Disciplina
        """
        return self.__IdDisciplina