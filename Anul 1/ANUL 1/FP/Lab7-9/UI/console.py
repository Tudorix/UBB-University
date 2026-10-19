class Console:
    
    def __init__(self, serviceStudenti, serviceDiscipline, serviceNote):
        """
            Constructorul clasei Console
            @param serviceStudenti - ServiceStudent
            @param serviceDiscipline - ServiceDiscipline
            @param serviceNote - ServiceNote
        """
        self.serviceStudenti = serviceStudenti
        self.serviceDiscipline = serviceDiscipline
        self.serviceNote = serviceNote
    
    def citeste_student(self):
        """
            Functie care citeste datele pentru obiectul student
        """
        id = None
        nume = ""
        varsta = None
        
        while True:
            try:
                id = int(input("Enter the ID\n>>>")) 
                break
            except ValueError:
                print("ID invalid")
                
        while True:
            try:
                varsta = int(input("Enter the Age\n>>>")) 
                break
            except ValueError:
                print("Age invalid")
        
        while nume == "":
            nume = input("Enter the Name\n>>>")
        
        return (id , nume, varsta)
    
    def add_for_test(self):
        self.serviceStudenti.reset_list()
        self.serviceStudenti.adauga_student(1 , "Tudor", 20)
        self.serviceStudenti.adauga_student(2 , "Dragos", 23)
        self.serviceStudenti.adauga_student(3 , "Adi", 18)
        self.serviceStudenti.adauga_student(4 , "Guta", 17)
        self.serviceStudenti.adauga_student(5 , "Gaboru", 21)
        self.serviceStudenti.adauga_student(6 , "Sonia", 22)
        self.serviceStudenti.adauga_student(7 , "Stef", 21)
        self.serviceStudenti.adauga_student(8 , "Misu", 19)
        self.serviceStudenti.adauga_student(9 , "Pecichi", 24)
        self.serviceStudenti.adauga_student(10 , "Ali", 18)
        
        self.serviceDiscipline.reset_list()
        self.serviceDiscipline.adauga_disciplina(1 , "Mate", "Stefan")
        self.serviceDiscipline.adauga_disciplina(2 , "Info", "Daniela")
        
        self.serviceNote.reset_list()
        self.serviceNote.adauga_nota(1 , 10, 1 , 1)
        self.serviceNote.adauga_nota(2 , 9 , 1 , 2)
        self.serviceNote.adauga_nota(3 , 10 , 1 , 2)
        
        self.serviceNote.adauga_nota(4 , 9, 2 , 1)
        self.serviceNote.adauga_nota(5 , 9, 2 , 2)
        self.serviceNote.adauga_nota(6 , 7, 2 , 2)
        
        self.serviceNote.adauga_nota(7 , 8, 3 , 1)
        self.serviceNote.adauga_nota(8 , 9, 3 , 2)
        self.serviceNote.adauga_nota(9 , 6, 3 , 2)
        
        self.serviceNote.adauga_nota(10 , 8, 4 , 2)
        self.serviceNote.adauga_nota(11, 10, 4 , 2)
        self.serviceNote.adauga_nota(12 , 10, 4 , 2)
        
        self.serviceNote.adauga_nota(13 , 6, 5 , 2)
        self.serviceNote.adauga_nota(14, 8, 5 , 2)
        self.serviceNote.adauga_nota(15, 7, 5 , 2)
        
        self.serviceNote.adauga_nota(16, 5, 6 , 1)
        self.serviceNote.adauga_nota(17, 7, 6 , 2)
        
        self.serviceNote.adauga_nota(18, 10, 7 , 1)
        self.serviceNote.adauga_nota(19, 7, 7 , 2)
        
        self.serviceNote.adauga_nota(20, 9, 8 , 1)
        self.serviceNote.adauga_nota(21, 8, 8 , 2)
        
        self.serviceNote.adauga_nota(22, 7, 9 , 1)
        self.serviceNote.adauga_nota(23, 7, 9 , 2)
        
        self.serviceNote.adauga_nota(24, 5, 10 , 1)
        self.serviceNote.adauga_nota(25, 6, 10 , 2)
        
    
    def citeste_nota(self):
        """
            Functie care citeste datele pentru obiectul student
        """
        idNota = None
        valoare = -1
        idStudent = None
        idDisciplina = None
        
        while True:
            try:
                idNota = int(input("Enter the ID of the Nota\n>>>")) 
                break
            except ValueError:
                print("Nota ID invalid")
                
        while True:
            try:
                valoare = int(input("Enter the value of Nota\n>>>")) 
                if valoare > 0 and valoare <= 10:
                    break
            except ValueError:
                print("Nota value invalid")
                
        while True:
            try:
                idStudent = int(input("Enter the ID of the Student\n>>>")) 
                break
            except ValueError:
                print("Student ID invalid")
                
        while True:
            try:
                idDisciplina = int(input("Enter the ID of the Disciplina\n>>>")) 
                break
            except ValueError:
                print("Disciplina ID invalid")
                
        return (idNota , valoare, idStudent , idDisciplina)
    
    def citeste_disciplina(self):
        """
            Functie care citeste datele pentru obiectul disciplina
        """
        id = None
        nume = ""
        profesor = ""
        
        while True:
            try:
                id = int(input("Enter the ID\n>>>")) 
                break
            except ValueError:
                print("ID invalid")
        
        while nume == "":
            nume = input("Enter the Name\n>>>")
            
        while profesor == "":
            profesor = input("Enter the Profssor\n>>>")
        
        return (id , nume , profesor)
    
    def citeste_numar(self):
        nr = -1
        while True:
            try:
                nr = int(input("Enter the number of students to be generated\n>>>")) 
                break
            except ValueError:
                print("Invalid NUmebr")
                
        return nr
    
    def run(self):
        print("Type 'help' to see the commands")
        running = True
        
        while running:
            #try:
                com = input("Enter a command:\n>>>")
                args = com.strip().split()
                
                if args[0] == "exit":
                    running = False
                elif args[0] == "testval":
                    self.add_for_test()
                elif args[0] == "help":
                    print("Commands list:\n" + 
                        "exit\n" + 
                        "gen student\n" +
                        "add student/disciplina/nota\n" + 
                        "update student/disciplina\n" + 
                        "del student/disciplina/nota\n" + 
                        "print student/disciplina/nota")
                elif args[0] == "print":
                    if len(args) <= 1:
                        print("You forgot to specify the type(student/disciplina)")
                    elif args[1] == "student":
                        print("Studenti:")
                        lista = self.serviceStudenti.get_studenti()
                        for e in lista:
                            print(e)
                    elif args[1] == "disciplina":
                        print("Discipline:")
                        lista = self.serviceDiscipline.get_discipline()
                        for e in lista:
                            print(e)
                    elif args[1] == "nota":
                        print("Note:")
                        lista = self.serviceNote.get_note()
                        for e in lista:
                            print(e)
                            
                elif com == "gen student":
                    x = self.citeste_numar()
                    self.serviceStudenti.gen_studenti(x)
                elif args[0] == "add":
                    if len(args) <= 1:
                        print("You forgot to specify the type(student/disciplina)")
                    elif args[1] == "student":
                        (ID , nume, varsta) = self.citeste_student()
                        try:
                            self.serviceStudenti.adauga_student(ID , nume, varsta)
                            print("Student added successfully")
                        except ValueError:
                            print("Invalid Student")
                        except IndexError:
                            print("There is another Student with that ID")
                    elif args[1] == "disciplina":
                        (ID , nume, profesor) = self.citeste_disciplina()
                        try:
                            self.serviceDiscipline.adauga_disciplina(ID , nume, profesor)
                            print("Disciplina added successfully")
                        except ValueError:
                            print("Invalid Disciplina")
                        except IndexError:
                            print("There is another Discipline with this ID")
                    elif args[1] == "nota":
                        (idNota , valoare, idStudent , idDisciplina) = self.citeste_nota()
                        try:
                            self.serviceNote.adauga_nota(idNota , valoare, idStudent , idDisciplina)
                            print("Nota added successfully")
                        except IndexError:
                            print("There is a missing object with this ID")
                        except:
                            print("Invalid Nota")
                        
                elif args[0] == "del":
                    if len(args) <= 1:
                        print("You forgot to specify the type(student/disciplina)")
                    elif args[1] == "student":
                        
                        if len(args) <= 2:
                            print("You forgot to specify the student ID")
                        else:
                            try:
                                lista_note = self.serviceNote.get_note()
                                try:
                                    id = int(args[2])
                                except:
                                    raise MemoryError
                                
                                lista_id = []
                                
                                for e in lista_note:
                                    if e.getStudent().getID() == id:
                                        lista_id.append(e.getID())
                                        
                                self.serviceNote.sterge_toate_notele(lista_id)
                                
                                self.serviceStudenti.sterge_student(args[2])
                                print("Student deleted successfully")
                            except MemoryError:
                                print("There is no Student with that ID")
                            except ValueError:
                                print("ID is invalid")
                                
                    elif args[1] == "disciplina":
                        
                        if len(args) <= 2:
                            print("You forgot to specify the disciplina ID")
                        else:
                            try:
                                lista_note = self.serviceNote.get_note()
                                try:
                                    id = int(args[2])
                                except:
                                    raise MemoryError
                                
                                lista_id = []
                                
                                for e in lista_note:
                                    if e.getDisciplina().getID() == id:
                                        lista_id.append(e.getID())
                                        
                                self.serviceNote.sterge_toate_notele(lista_id)
                                
                                self.serviceDiscipline.sterge_disciplina(args[2])
                                print("Disciplina deleted successfully")
                            except MemoryError:
                                print("There is no Disciplina with that ID")
                            except ValueError:
                                print("ID is invalid")
                    elif args[1] == "nota":
                        
                        if len(args) <= 2:
                            print("You forgot to specify the nota ID")
                        else:
                            try:
                                self.serviceNote.sterge_nota(args[2])
                                print("Nota deleted successfully")
                            except MemoryError:
                                print("There is no Nota with that ID")
                            except ValueError:
                                print("ID is invalid")
                            
                elif args[0] == "update":
                    if len(args) <= 1:
                        print("You forgot to specify the type(student/disciplina)")
                    elif args[1] == "student":
                        
                        if len(args) <= 2:
                            print("You forgot to specify the student ID")
                        else:
                            (ID , nume, varsta) = self.citeste_student()
                            try:
                                self.serviceStudenti.update_student(args[2],ID, nume, varsta)
                                print("Student updated successfully")
                            except MemoryError:
                                print("There is no Student with that ID")
                            except ValueError:
                                print("Invalid Student")
                            except IndexError:
                                print("Existing ID is invalid")
                            
                    elif args[1] == "disciplina":
                        
                        if len(args) <= 2:
                            print("You forgot to specify the disciplina ID")
                        else:
                            (ID , nume, profesor) = self.citeste_disciplina()
                            try:
                                self.serviceDiscipline.update_disciplina(args[2],ID, nume, profesor)
                                print("Disciplina updated successfully")
                            except MemoryError:
                                print("There is no Disciplina with that ID")
                            except ValueError:
                                print("Invalid Disciplina")
                            except IndexError:
                                print("Existing ID is invalid")
                            
                elif args[0] == "cauta":
                    if len(args) <= 1:
                        print("You forgot to specify the type(student/disciplina)")
                    elif args[1] == "student":
                        
                        if len(args) <= 2:
                            print("You forgot to specify the criteria")
                        else:
                            try:
                                argumente = args[2:]
                                lista = self.serviceStudenti.cautare_student(argumente)
                                for e in lista:
                                    print(e)
                            except:
                                print("Invalid arguments")
                    elif args[1] == "disciplina":
                        
                        if len(args) <= 2:
                            print("You forgot to specify the criteria")
                        else:
                            try:
                                argumente = args[2:]
                                lista = self.serviceDiscipline.cautare_disciplina(argumente)
                                for e in lista:
                                    print(e)
                            except:
                                print("Invalid arguments")
            
                elif args[0] == "filt":
                    if len(args) <= 1:
                        print("You forgot to specify the type(alfabetic / 20%)")
                    elif args[1] == "alfabetic":
                        if len(args) <= 2:
                            print("You forgot to specify the criteria")
                        else:
                            try:
                                argumente = args[2]
                                lista = self.serviceNote.filtrare_nume_nota(argumente)
                                for e in lista:
                                    print(f"{e.getStudent().getNume()} : {e.getValoare()}")
                            except:
                                print("Invalid disciplina")
                    elif args[1] == "nota":
                        if len(args) <= 2:
                            print("You forgot to specify the criteria")
                        else:
                            try:
                                argumente = args[2]
                                lista = self.serviceNote.filtrare_nota_nume(argumente)
                                for e in lista:
                                    print(f"{e.getStudent().getNume()} : {e.getValoare()}")
                            except:
                                print("Invalid disciplina")
                    elif args[1] == "varsta":
                        if len(args) <= 2:
                            print("You forgot to specify the varsta")
                        else:
                            try:
                                argumente = args[2]
                                lista = self.serviceStudenti.filt_varsta(argumente)
                                for e in lista:
                                    print(e)
                            except ValueError:
                                print("Invalid varsta")
                    elif args[1] == "20":
                        try:
                            lista = self.serviceNote.filtrare_20()
                            for e in lista:
                                print(e)
                        except:
                            print("Invalid disciplina")
                    
                else:
                    print("Invalid command typed")
            #except Exception:
            #    print ("Invalid command")