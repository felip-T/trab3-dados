"""
 * UFRJ   - Universidade Federal do Rio de Janeiro
 * DMA/IM - Departamento de Matemática Aplicada do Instituto de Matemática
 *
 *            (MAE 016) Top. Eng. Dados B: Estruturas de Dados e seus Algoritmos
 *
 *          Tarefa de Programação 003 - Hierarquia de Classes de Estruturas de Dados Lineares
 *
 *          Prof. Milton R Ramirez (milton@matematica.ufrj.br)
 *          Data da criação  : 05 de novembro de 2023
 *
"""

class Array:
    def __init__(self,name):
        self.lista=[]
        self.name=name
    
    def CriaArray(self):
        while 1 == True:
            item = input("Input item to array. ")
            self.lista.append(item)
            cont = input("Input new item? Y/N ")
            if cont == "y" and "Y":
                continue
            elif cont == "n" and "N":
                break
            else:
                print("Please, input an acceptable answer.")
                cont = input("Input new item? Y/N ")
                if cont == "y" or "Y":
                    continue
                elif cont == "n" or "N":
                    break
        print("")
        print(self.name+" array is: "+str(self.lista))
        
    def ManageItems(self):
        while 1 == True:
            op1=input("""
What would you like to do?
1 - Insert an item
2 - Substitute an item
3 - Remove an item
                    
Press any other key to return
""")
            if op1=="1":
                while 1 == True:
                    op2=input("""
Where should it be inserted?
1 - At the beginning
2 - At the end
3 - In a determined position
4 - Before a specific item*
5 - After a specific item*
         
Press any other key to return
*Note that if there are many of the specified item, only the first will be referenced
""")
                    if op2=="1":
                        op3=input("Input item to be inserted ")
                        self.lista.insert(0,op3)
                        continue
                    if op2=="2":
                        op3=input("Input item to be inserted ")
                        self.lista.append(op3)
                        continue
                    if op2=="3":
                        op4=input("Where should it be inserted? ")
                        while int(op4)>len(self.lista):
                            self.lista.append("")
                        op3=input("Input item to be inserted ")
                        self.lista.insert(int(op4),op3)
                        continue
                    if op2=="4":
                        op4=input("Insert before which item? ")
                        while 1 == True:
                            if op4 in self.lista:
                                op3=input("Input item to be inserted ")
                                self.lista.insert((self.lista.index(op4)-1),op3)
                                break
                            else:
                                print("Referenced item not present in "+self.name)
                                op4=input("Insert before which item? ")
                                continue
                        continue
                    if op2=="5":
                        op4=input("Insert after which item? ")
                        while 1 == True:
                            if op4 in self.lista:
                                op3=input("Input item to be inserted ")
                                self.lista.insert((self.lista.index(op4)+1),op3)
                                break
                            else:
                                print("Referenced item not present in "+self.name)
                                op4=input("Insert after which item? ")
                                continue
                        continue
                    else:
                        break
            if op1=="2":
                while 1 == True:
                    op2=input("""
Select the substitution method:
1 - By the item's name*
2 - By the item's index

Press any other key to return
*Note that if there are many of the specified item, only the first will be referenced
""")
                    if op2=="1":
                        op3=input("Input targeted item's name. ")
                        while 1 == True:
                            if op3 in self.lista:
                                op4=input("Input new item. ")
                                self.lista[self.lista.index(op3)]=op4
                                break
                            else:
                                print("Referenced item not present in "+self.name)
                                op3=input("Input targeted item's name. ")
                                continue
                        continue
                    if op2=="2":
                        op3=input("Input targeted item's index. ")
                        while 1 == True:
                            if op3 < len(self.lista):
                                op4=input("Input new item. ")
                                self.lista[int(op3)]=op4
                                break
                            else:
                                print("IndexError: list index out of range")
                                op3=input("Input targeted item's index. ")
                                continue
                        continue
                    else:
                        break
            if op1=="3":
                while 1 == True:
                    op2=input("""
Select removal method:
1 - Remove first item
2 - Remove last item
3 - Remove item by its index
4 - Remove item by its name*
         
Press any other key to return
*Note that if there are many of the specified item, only the first will be removed
""")    
                    if op2=="1":
                        self.lista.pop(0)
                        continue
                    if op2=="2":
                        self.lista.pop(len(self.lista)-1)
                        continue
                    if op2=="3":
                        while 1==True:
                            op3=input("Input targeted item's index. ")
                            if op3 < len(self.lista):
                                self.lista.pop(int(op3))
                                break
                            else:
                                print("IndexError: list index out of range")
                                continue
                        continue
                    if op2=="4":
                        op3=input("Input targeted item's name. ")
                        while op3 not in self.lista:
                            print("Referenced item not present in "+self.name)
                            op3=input("Input targeted item's name. ")
                            continue
                        self.lista.remove(op3)
                        continue
                    else:
                        break
            else:
                print("")
                break
        
    
    def LenArray(self):
        print("")
        print(self.name+" array's lenght is: "+str(len(self.lista)))
        
    def CheckArray(self):
        while 1 == True:
            op1=input("""
Would you like to:
1 - Visualize the complete array
2 - Inspect an specific item

Press any other key to return
""")
            if op1=="1":
                print(self.lista)
            if op1=="2":
                while 1 == True:
                    op2=input("""
1 - Present the array's first item
2 - Present the array's last item
3 - Present item by its index
4 - Present specific item's index*

Press any other key to return
*Note that if there are many of the specified item, only the first will be referenced
""")
                    if op2=="1":
                        print("")
                        print(self.lista[0])
                        continue
                    if op2=="2":
                        print("")
                        print(self.lista[len(self.lista)-1])
                        continue
                    if op2=="3":
                        print("")
                        indice=input("Input index. ")
                        while int(indice)>(len(self.lista)-1):
                            print("IndexError: list index out of range")
                            indice=input("Input index. ")
                        print(self.lista[int(indice)])
                        continue
                    if op2=="4":
                        print("")
                        op3=input("Input desired item. ")
                        print("The item's index is: "+str(self.lista.index(op3)))
                        continue
                    else:
                        print("")
                        break
            else:
                print("")
                break
            
                


while 1 == True:
    ans1 = input("Would you like to create a new array? Y/N ")
    if ans1=="y" and "Y":
        ans2=input("How should it be named? ")
        ans2=Array(ans2)
        ans2.CriaArray()
        while 1 == True:
            ans3=input("""
Would you like to perform any further operations?
1 - Manage the array's items
2 - Check the array's lenght
3 - Inspect the array
                
Press any other key to Exit
""")
            if ans3=="1":
                ans2.ManageItems()
                continue
            elif ans3=="2":
                ans2.LenArray()
                continue
            elif ans3=="3":
                ans2.CheckArray()
                continue
            else:
                break
    elif ans1 == "n" and "N":
        print("Ok, see you!")
        break
    else:
        print("Please, input an acceptable answer.")
        continue
