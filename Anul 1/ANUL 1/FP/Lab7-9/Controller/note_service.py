from Domain.nota import Nota
from Domain.nota_dto import NotaDTO
from Domain.sefPromotieDTO import SefPromotieDTO
import math
import operator
from sortari import Sort
class ServiceNote:
    
    def __init__(self, ValidatorNota , RepoNota , RepoStudent , RepoDiciplina):
        """
            Constructorul clasei ServiceDiscipline
            @param ValidatorNota - ValidatorNota
            @param RepoNota - NotaRepo
        """
        self.__validatorNota = ValidatorNota
        self.__repoNota = RepoNota
        self.__repoStud = RepoStudent
        self.__repoDisc = RepoDiciplina
        
    def reset_list(self):
        """
            Functie care reseteaza lista de note
        """
        self.__repoNota.rst()
        
    def __construiesteNota(self, nota_dto):
        """
        Functie care construieste o Nota din NotaDTO
        
        :param nota_dto: NotaDTO
        :rtype: Nota
        """
        idNota = nota_dto.getID()
        Valoare = nota_dto.getValoare()
        Student = self.__repoStud.get_by_id(nota_dto.getIdStudent())
        Disciplina = self.__repoDisc.get_by_id(nota_dto.getIdDisciplina())
        nota = Nota(Student,Disciplina,Valoare,idNota)
        return nota
        
    def get_note(self):
        """ 
            Functie care returneza lista curenta de note
        """
        note_dtos = self.__repoNota.get_note()
        note = []
        for nota_dto in note_dtos:
            nota = self.__construiesteNota(nota_dto)
            note.append(nota)
        return note
    
    #Complexitatea este Theta(n^2) , n - lungimea listei de studenti
    def filtrare_nume_nota(self, disciplina):
        """
            Functie care sorteaza studentii dupa Nume si Nota
            raise - ValueError
        """
        lista = self.get_note()
        lista_filt = []
        
        #verificare disciplina
        #Complexitate Theta(n)
        for i in range(0 ,self.__repoNota.lenght()):
            if lista[i].getDisciplina().getNume() == disciplina:
                lista_filt.append(lista[i])
        
        lenght = len(lista_filt)
        if lenght == 0:
            raise ValueError
        
        #filtarre dupa nume -> nota
        #Complexitate Theta(n^2)
        """
        for i in range(0 ,lenght - 1):
            for j in range(i , lenght):
                if lista_filt[i].getStudent().getNume() > lista_filt[j].getStudent().getNume():
                    lista_filt[i] , lista_filt[j] = lista_filt[j] , lista_filt[i]
                elif lista_filt[i].getStudent().getNume() == lista_filt[j].getStudent().getNume():
                    if lista_filt[i].getValoare() < lista_filt[j].getValoare():
                        lista_filt[i] , lista_filt[j] = lista_filt[j] , lista_filt[i]
        """
        
        lista_filt = Sort.BubbleSort(lista_filt, key = lambda nota: nota.getStudent().getNume(), cmp=operator.gt,key_aux= lambda nota : nota.getValoare())
        
        return lista_filt
    
    def filtrare_nota_nume(self, disciplina):
        """
            Functie care sorteaza studentii dupa Nota si Nume
            raise - ValueError
        """
        lista = self.get_note()
        lista_filt = []
        
        #verificare disciplina
        for i in range(0 ,self.__repoNota.lenght()):
            if lista[i].getDisciplina().getNume() == disciplina:
                lista_filt.append(lista[i])
        
        lenght = len(lista_filt)
        if lenght == 0:
            raise ValueError
        
        #filtarre dupa nota -> nume
        """
        for i in range(0 ,lenght - 1):
            for j in range(i , lenght):
                if lista_filt[i].getValoare() < lista_filt[j].getValoare():
                    lista_filt[i] , lista_filt[j] = lista_filt[j] , lista_filt[i]
                elif lista_filt[i].getValoare() == lista_filt[j].getValoare():
                    if lista_filt[i].getStudent().getNume() > lista_filt[j].getStudent().getNume():
                        lista_filt[i] , lista_filt[j] = lista_filt[j] , lista_filt[i]
        """
        lista_filt = Sort.BubbleSort(lista_filt , lambda nota: nota.getValoare(), operator.lt , lambda nota : nota.getStudent().getNume())
        
        return lista_filt
    
    def __listaMedii(self , lista_studenti , lista_note):
        """
        Functie care returneaza lista de SefPromotieDTO
        
        :param self: Description
        :param lista_studenti: Description
        :param lista_note: Description
        :return: Description
        :rtype: NoReturn
        """
        lista_medii = []
        for e in lista_studenti:
            suma = 0.0
            nr = 0
            for i in lista_note:
                if e.getID() == i.getStudent().getID():
                    suma += i.getValoare()
                    nr += 1
            
            if suma != 0:
                suma /= nr
                sef_promotie = SefPromotieDTO(suma , e.getNume() )
                lista_medii.append(sef_promotie)
                
        return lista_medii
    
    def filtrare_20(self):
        """
            Functie care sorteaza studentii dupa media notelor
            
            :return lista cu 20% studenti cu cele mai mari medii
        """
        lista_note = self.get_note()
        lista_studenti = self.__repoStud.getList()
        
        lista_medii = self.__listaMedii(lista_studenti , lista_note)
        
        lenght = len(lista_medii)
        percent = math.floor(20/100 * lenght)
        
        """
        #filtarre dupa medie
        for i in range(lenght - 1):
            for j in range(lenght):
                if lista_medii[i].getMedie() > lista_medii[j].getMedie():
                    aux = lista_medii[i]
                    lista_medii[i] = lista_medii[j]
                    lista_medii[j] = aux
        """
        
        lista_medii = Sort.ShellSort(lista_medii, key = lambda notaDTO : notaDTO.getMedie())

        return lista_medii[:percent]
        
        
    def adauga_nota(self , ID , Valoare, idStudent , idDisciplina):
        """
            Functie care adauga nota in lista de note
            @param ID - int
            @param Valoare - int
            @param Student - Student
            @param Disciplina - Disciplina
        """
        
        Student = self.__repoStud.get_by_id(idStudent)
        Disciplina = self.__repoDisc.get_by_id(idDisciplina)
        
        nota = Nota(Student , Disciplina , Valoare , ID)
        try:
            self.__validatorNota.validareNota(nota)
        except:
            raise Exception
        
        nota = NotaDTO(ID , Valoare , Student.getID() , Disciplina.getID())
        
        self.__repoNota.adauga_nota(nota)
        
    def sterge_toate_notele(self , list_id):
        """
            Functie care sterge toate notele cu IDurile din list_id

        Args:
            list_id (list): lista cu idurile 
        """
        for i in list_id:
            self.sterge_nota(i)
        
    def sterge_nota(self, ID):
        """
            Functie care sterge nota din lista de note
            @param ID - int
        """
        try:
            self.__validatorNota.validareID(ID)
        except:
            raise ValueError
        
        self.__repoNota.sterge_nota(ID)