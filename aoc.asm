.data
	welcome: .asciiz "Seja bem-vindo a agenda de KDOXG! Carregando..."
	escolha1: .asciiz "1: Adicionar pessoa,"
	escolha2: .asciiz "2: Remover pessoa,"
	escolha4: .asciiz "3: Buscar pessoa,"
	escolha3: .asciiz "4: Listar pessoas,"
	escolha5: .asciiz "5: Sair. Digite: "
	digitarnome: .asciiz "Digite o nome: "
	finalizado1: .asciiz "Pessoa adicionada!"
	finalizado2: .asciiz "Pessoa removida!"
	lista1: .asciiz "Nome: "
	lista2: .asciiz "Codigo de identificacao: "
	fim: .asciiz "Muito obrigado! Guarde seu .txt com cuidado :-) Volte sempre! -KDOXG"
	contrabarraene: .asciiz "\n"
	Buffer: .word 0,0,0,0,0,0,0,0,0,0,0,0,0
	
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
#--------------------------------------

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

Organizar: lw $t1, Buffer+0
lw $t2, Buffer+4
lw $t3, Buffer+8
lw $t4, Buffer+12
lw $t5, Buffer+16
jr $ra
nop

incluirPessoa: jal Organizar
nop
la $t9, Buffer+20($t3)
li $v0, 4
la $a0, digitarnome
syscall
li $v0, 8
move $a0, $t9
li $a1, 32
syscall

addi $t3, $t3, 1
addi $t8, $t3, 1
mul $t8, $t8, 32
addi $t8, $t8, 20
move $t2, $t8

li $v0, 9
move $a0, $t8
syscall
#Dar um jeito da label Buffer receber a nova area alocada
li $v0, 4
la $a0, finalizado1
syscall
j menu
nop

apagarPessoa: jal Organizar
nop

buscarPessoa: jal Organizar
nop

listarPessoas: jal Organizar
nop

Sair: #Dar um jeito de dar um free() no Buffer