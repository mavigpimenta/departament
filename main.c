class Pessoa:

    def __init__(self, nome, idade, gen):
        self.__nome = nome
        self.__idade = idade 
        self.__gen = gen

    def getNome(self):
        return self.__nome

    def getIdade(self):
        return self.__idade

    def getGen(self):
        return self.__gen


class Funcionario(Pessoa):

    def __init__(self, nome, idade, gen, cargo, salario):
        super().__init__(nome, idade, gen)
        self.__cargo = cargo
        self.__salario = salario

    def getCargo(self):
        return self.__cargo

    def getSalario(self):
        return self.__salario

    def calcularBonificacao(self):
        bonificacao = 0.1 * self.__salario
        return bonificacao


class Gerente(Funcionario):
    def __init__(self, setor, salario):
        self.__setor = setor
        self.__salario = salario

    def getSetor(self):
        return self.__setor

    def calcularBonificacao(self):
        bonificacao = (0.15 * self.__salariosalario)
        return bonificacao


class Departamento:

    listaFuncionario = []

    def __init__(self, nomeDepartamento, listaFun):
        self.nomeDepartamento = nomeDepartamento
        self.listaFun = listaFun

    def adicionarFun(funcionario):
        Departamento.listaFuncionario.append(funcionario)

    def removerFun(funcionario):
        Departamento.listaFuncionario.remove(funcionario)

    def listarFuncionarios():
        for f in Departamento.listaFuncionario:
            print(f"{f.getNome()}: {f.getCargo()}")


def menu():
    print("\n----------------------------------")
    print("|    1 - CONSULTAR FUNCIONARIO   |")
    print("|    2 - CALCULAR BONIFICAÇÃO    |")
    print("|    3 - ADICIONAR FUNCIONARIO   |")
    print("|    4 - REMOVER FUNCIONARIO     |")
    print("|    5 - LISTAR FUNCIONARIOS     |")
    print("----------------------------------")

    userChoice = int(input("\n> "))

    return userChoice


def printInfo(f):

    print(f"Nome: {f.getNome()}")
    print(f"Idade: {f.getIdade()}")
    print(f"Genero: {f.getGen()}")
    print(f"Salário: {f.getSalario()}")
    print(f"Cargo: {f.getCargo()}")


def adcFunGen():

    print("\n----------------------------------")
    print("|        1 - FUNCIONARIO         |")
    print("|        2 - GERENTE             |")
    print("----------------------------------")

    funOuGen = int(input("\n> "))

    if funOuGen == 1:
        nome = input("Nome: ")
        idade = input("Idade: ")
        gen = input("Genero: ")
        salario = int(input("Salário: "))
        cargo = input("Cargo: ")

        funcionario = Funcionario(nome, idade, gen, salario, cargo)
        Departamento.adicionarFun(funcionario)

        print(f"\nFuncionário cadastrado com sucesso!")
        printInfo(funcionario)

    elif funOuGen == 2:
        nome = input("Nome: ")
        idade = input("Idade: ")
        gen = input("Genero: ")
        salario = int(input("Salário: "))
        cargo = input("Cargo: ")
        setor = input("Setor: ")

        gerente = Gerente(nome, idade, gen, salario, cargo)
        Departamento.adicionarFun(gerente)

        print(f"\nGerente cadastrado com sucesso!")
        printInfo(gerente)
        print(f"Setor: {gerente.getSetor()}")

    else:
        print("\nOPÇÃO INVÁLIDA!")


def choice():

    while True: 

        match (menu()):
            case 1:
                fun = input("DIGITE O NOME DO FUNCIONARIO\n> ")

                for f in Departamento.listaFuncionario:
                    if f.getNome() == fun:
                        printInfo(f)
                    else:
                        print("Esse funcionário não consta na lista...")

            case 2:
                fun = input("DIGITE O NOME DO FUNCIONARIO\n> ")

                for f in Departamento.listaFuncionario:
                    if f.getNome() == fun:
                        print(f"Bonificação: {f.calcularBonificacao()}")
                    else:
                        print("Esse funcionário não consta na lista...")    

            case 3:
                adcFunGen()

            case 4:
                fun = input("DIGITE O NOME DO FUNCIONARIO\n> ")

                for f in Departamento.listaFuncionario:
                    if f.getNome() == fun:
                        Departamento.removerFun(f)
                    else:
                        print("Esse funcionário não consta na lista...")

            case 5:
                Departamento.listarFuncionarios()

            case _:
                print("\nOPÇÃO INVÁLIDA!")

choice()
