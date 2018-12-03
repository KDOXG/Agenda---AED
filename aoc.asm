.data		#Disclaimer: sera mais facil se eu fizer usando uma estrutura guiada por ponteiros (lista encadeada)
	#UPDATE: Chamar as frases extras via operações com arquivos
	welcome: .asciiz "Seja bem-vindo a agenda de KDOXG! Carregando..."
	escolha1: .asciiz "\n1: Adicionar pessoa,\n"
	escolha2: .asciiz "2: Remover pessoa,\n"
	escolha3: .asciiz "3: Buscar pessoa,\n"
	escolha4: .asciiz "4: Listar pessoas,\n"
	escolha5: .asciiz "5: Sair. Digite: "
	digitarnome: .asciiz "Digite o nome: "
	finalizado1: .asciiz "Pessoa adicionada!\n"
	finalizado2: .asciiz "Pessoa removida!\n"
	lista1: .asciiz "Nome: "
	lista2: .asciiz "\nCodigo de identificacao: "
	fim: .asciiz "Muito obrigado! Guarde seu .txt com cuidado :-) Volte sempre! -KDOXG"
	Buffer: .space 39
	
.text
#InsertionSort:
#apagarPessoa:
#buscarPessoa:
#listarPessoas:
#Sair:

la $a0, welcome
li $v0, 4
syscall

#--------------------------------------
#colocar as funcoes graficas aqui
#referenciar para 0xffff0000
#UPDATE: Chamar a imagem via operações com arquivos
#--------------------------------------

la $t9, Buffer
addi $t9, $t9, 3
li $t1, 0
li $t2, 0
li $t3, 0
li $t4, 0
li $t5, 0

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

menu: li $v0, 5
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

#lw $s0 0($sp)
#addi $sp $sp 4
#lw $ra 0($sp)
#addi $sp $sp 4
#jr $ra
#nop

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

li $v0, 9
li $a0, 36
syscall
addi $t9, $t9, 1
sw $v0, ($t9)
la $t9, ($v0)
li $v0, 4
la $a0, finalizado1
syscall
j menu
nop

apagarPessoa:
li $v0, 4
la $a0, digitarnome
syscall
li $v0, 8
move $a0, $t9
li $a1, 31
syscall
#Necessita de um algoritmo de busca em assembly
#Necessita de um algoritmo de ordenacao

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

listarPessoas:
#Necessita de um algoritmo de busca e de exibicao em loop

Sair: #Dar um jeito de dar um free() no Buffer
