chars_to_remove = 'ButonPrizeABXY+=:,'

input = open("./input.txt", "r")
proc_input = open("./proc_input.txt", "w+")

                        # que linha de OURO ------------------------------------------
proc_input.writelines([line.translate({ord(i): None for i in chars_to_remove}).strip(" ")  
                       for line in input.readlines() if line != '\n'])

input.close()


qtd_casos = 0
cnt = input("Quantidade de linhas por caso: ") 

proc_input.seek(0)
for line in proc_input.readlines():
    cnt += 1

    if cnt == 3:
        qtd_casos += 1
        cnt = 0

proc_input_completo = str(qtd_casos) + "\n"

proc_input.seek(0)
for line in proc_input.readlines():
    proc_input_completo += line

proc_input.close()
proc_input = open("./proc_input.txt", "w")

proc_input.write(proc_input_completo)

proc_input.close()
