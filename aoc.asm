.data		#Disclaimer: sera mais facil se eu fizer usando uma estrutura guiada por ponteiros (lista encadeada)
	extra0: .asciiz "Isto e uma mensagem de enfase(enfase?)"
	extra1: .asciiz "Assembly <3"
	extra2: .asciiz "Saudades professor Guilherme ;-;"
	extra3: .asciiz "Joguem Touhou. E uma ordem."
	extra4: .asciiz "Existe tres tipos de programacao: programacao para embarcados, programacao para sistemas e programacao para as provas do Marilton."
	extra5: .asciiz "Entenderam, todo mundo entendeu? Entenderam, sim ou nao?"
	extra6: .asciiz "Imagina se o primeiro cliente do RU do Anglo é a agenda do pBuffer, so que pronta."
	extra7: .asciiz "Imagina um marmanjo falando 'Fredericoo~' ou 'Vivii~'. Imaginou?"
	extra8: .asciiz "Ir a pe para o Anglo nem e tao ruim!"
	extra9: .asciiz "Todos os dias depois da aula agora eu irei pra Cotada/CEng, e muito gostoso estudar la s2"
	extra10: .asciiz "o jojojojojojojojojojojojojojojojojojojojojojo"
	extra11: .asciiz "Professor Lulu ou professora Lulu?"
	extra12: .asciiz "Tem que ser muito doente ou um engenheiro pra gostar de Calculo..."
	extra13: .asciiz "'Lindo da tia, beijos.'"
	extra14: .asciiz "Sabe por que C++ nao deu certo? Porque o criador nao chamou de C++;, ai quando tentaram usar, nao compilou."
	extra15: .asciiz "Na porta de um dos boxes do banheiro do corredor do primeiro andar tem uma mensagem honesta."
	extra16: .asciiz "Tem uma bruxa moe na turma da Engenharia deste ano, e ela e fofa. Protejam-a!"
	extra17: .asciiz "Tambem comemorei o Halloween este ano, sai de casa 6 da manha naquela quarta-feira so pra ir ver uma bruxa"
	extra18: .asciiz "Aquele momento em que descobrem as lolis na casa do aluno de Computacao~"
	extra19: .asciiz "Foda ser orelha..."
	extra20: .asciiz "Sera que o prof. Mauricio entende bem de pilha?"
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
#referenciar para 0x10040000
#--------------------------------------

jal Organizar
nop

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

Organizar:
#addi $sp $sp -4
#sw $ra 0($sp)
#addi $sp $sp -4
#sw $s0 0($sp)

#lw $t1, Buffer+0
#lw $t2, Buffer+4
#lw $t3, Buffer+8
#lw $t4, Buffer+12
#lw $t5, Buffer+16

#lw $s0 0($sp)
#addi $sp $sp 4
#lw $ra 0($sp)
#addi $sp $sp 4
#jr $ra
#nop

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
#Tambem dar um jeito da nova area alocada receber os dados da label Buffer
li $v0, 4
la $a0, finalizado1
syscall
j menu
nop

apagarPessoa: jal Organizar
nop
la $t9, Buffer+20($t3)
li $v0, 4
la $a0, digitarnome
syscall
li $v0, 8
move $a0, $t9
li $a1, 32
syscall
#Necessita de um algoritmo de busca em assembly
#Necessita de um algoritmo de ordenacao

buscarPessoa: jal Organizar
nop
la $t9, Buffer+20($t3)
li $v0, 4
la $a0, digitarnome
syscall
li $v0, 8
move $a0, $t9
li $a1, 32
syscall
#Necessita de um algoritmo de busca em assembly
#Necessita de um algoritmo de exibicao

listarPessoas: jal Organizar
nop
#Necessita de um algoritmo de exibicao em loop

Sair: #Dar um jeito de dar um free() no Buffer
