.data		#Disclaimer: sera mais facil se eu fizer usando uma estrutura guiada por ponteiros (lista encadeada)
	#UPDATE: Chamar as frases extras via opera??es com arquivos
	welcome: .asciiz "Seja bem-vindo a agenda de KDOXG! Carregando..."
	escolha1: .asciiz "\n1: Adicionar pessoa,\n"
	escolha2: .asciiz "2: Remover pessoa,\n"
	escolha3: .asciiz "3: Buscar pessoa,\n"
	escolha4: .asciiz "4: Listar pessoas,\n"
	escolha5: .asciiz "5: Sair. Digite: "
	digitarnome: .asciiz "Digite o nome: "
	finalizado1: .asciiz "Pessoa adicionada!\n"
	finalizado2: .asciiz "Pessoa removida!\n"
	finalizado3: .asciiz "Pessoa nao encontrada.\n"
	lista1: .asciiz "\nNome: "
	lista2: .asciiz "Codigo de identificacao: "
	lista3: .asciiz "\n\nQuantidade: "
	fim: .asciiz "Muito obrigado! Guarde seu .txt com cuidado :-) Volte sempre! -KDOXG"
	Buffer: .space 36
	
.text
#Sair:

la $a0, welcome
li $v0, 4
syscall

#--------------------------------------
#colocar as funcoes graficas aqui
#referenciar para 0xffff0000
#UPDATE: Chamar a imagem via operacoes com arquivos
#UPDATE@: Nao tera imagens nem algoritmo de ordenacao
#Nao havera tempo de implementar.
#--------------------------------------

la $t9, Buffer			#Registrador do endereco para guardar nomes
li $t8, 0				#Registrador de auxilio para enderecos
li $t1, 0				#Registrador de auxilio (aux1,temp1)
li $t2, 0				#Segundo registrador de auxilio (aux2,temp2)
li $t3, 0				#Quantidade de nomes cadastrados na agenda
li $t4, 0				#Registrador de indice para la?os de repeticao
li $t5, 0				#Registrador geral 1
li $t6, 0				#Registrador geral 2

menu:
li $v0, 4
la $a0, escolha1
syscall
la $a0, escolha2
syscall
la $a0, escolha3
syscall
la $a0, escolha4
syscall
la $a0, escolha5
syscall

li $v0, 5
syscall
move $t0, $v0
beq $t0, 1, incluirPessoa
nop
beq $t0, 2, apagarPessoa
nop
beq $t0, 3, buscarPessoa
nop
beq $t0, 4, listarPessoas
nop
beq $t0, 5, Sair
nop
j menu
nop

#-----------------Stack Pointer - Como usar
#Organizar:
#addi $sp $sp -4
#sw $ra 0($sp)
#addi $sp $sp -4
#sw $s0 0($sp)

#~digitar funcoes aqui~

#lw $s0 0($sp)
#addi $sp $sp 4
#lw $ra 0($sp)
#addi $sp $sp 4
#jr $ra
#nop

#----------------------------------
incluirPessoa: 
li $v0, 4
la $a0, digitarnome
syscall
li $v0, 8
move $a0, $t9
li $a1, 31
syscall
lbu $t1, ($t9)
addi $t9, $t9, 31
sb $t1, ($t9)
addi $t3, $t3, 1
addi $t9, $t9, 1

li $v0, 9
li $a0, 36
syscall
sw $v0, ($t9)			#Guarda o endereco da nova area para a proxima posicao
la $t9, ($v0)			#Ideia que veio da lista encadeada
li $v0, 4
la $a0, finalizado1
syscall
j menu
nop

#----------------------------------
apagarPessoa:
li $v0, 4
la $a0, digitarnome
syscall
li $v0, 8
move $a0, $t9
li $a1, 31
syscall
#Necessita de um algoritmo de busca em assembly
la $t8, Buffer
lbu $t1, ($t8)
lbu $t2, ($t9)
addi $t6, $t8, 32

For_apaga:
seq $t5, $t1, $t2
beq $t5, 1, Apagar
nop

addi $t8, $t8, 32
move $t6, $t8
lw $t8, ($t8)
beq $t8, $t9, Erro
nop
lbu $t1, ($t8)
j For_apaga
nop

Apagar: 
addi $t8, $t8, 32
lw $t8, ($t8)
sw $t8, ($t6)
li $v0, 4
la $a0, finalizado2
syscall
j menu
nop

buscarPessoa:
li $v0, 4
la $a0, digitarnome
syscall
li $v0, 8
move $a0, $t9
li $a1, 31
syscall
#Necessita de um algoritmo de busca em assembly
#Necessita de um algoritmo de exibicao
la $t8, Buffer
lbu $t1, ($t8)
lbu $t2, ($t9)

For_busca:
seq $t5, $t1, $t2
addi $t5, $t5, -1
bgezal $t5, Imprimir
nop
bgez $t5, Fim_busca
nop

addi $t8, $t8, 32
lw $t8, ($t8)
beq $t8, $t9, Erro
nop
lbu $t1, ($t8)
j For_busca
nop
Fim_busca:
j menu
nop

Erro:
li $v0, 4
la $a0, finalizado3
syscall
j menu
nop

listarPessoas:
#Necessita de um algoritmo de busca e de exibicao em loop
la $t8, Buffer

For_lista:
jal Imprimir
nop

addi $t8, $t8, 32
lw $t8, ($t8)
beq $t8, $t9, Fim_lista
nop
#lbu $t1, ($t8)
j For_lista
nop

Fim_lista:
li $v0, 4
la $a0, lista3
syscall
li $v0, 1
move $a0, $t3
syscall
j menu
nop

Imprimir:
li $v0, 4
la $a0, lista1
syscall
move $a0, $t8
syscall
la $a0, lista2
syscall
li $v0, 1
lbu $a0, 31($t8)
syscall
jr $ra
nop

Sair: #Dar um jeito de dar um free() no Buffer
la $a0, fim
li $v0, 4
syscall
li $v0, 10
syscall
