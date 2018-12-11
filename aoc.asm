.data
	agenda: .asciiz "agenda.txt"
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
	lista3: .asciiz "\nQuantidade: "
	fim: .asciiz "Muito obrigado! Guarde seu .txt com cuidado... =) Volte sempre! -KDOXG"
	Buffer: .space 4
	
.text

la $a0, welcome
li $v0, 4
syscall

la $t9, Buffer			#Registrador do endereco para guardar nomes
li $v0, 9
li $a0, 36
syscall
sw $v0, ($t9)
move $t9, $v0
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

incluirPessoa: 
	li $v0, 4
	la $a0, digitarnome
	syscall
	li $v0, 8
	move $a0, $t9
	li $a1, 32
	syscall
	addi $t3, $t3, 1
	addi $t9, $t9, 32

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
	li $a1, 32
	syscall
	lw $t8, Buffer
	lw $t6, Buffer					#Aqui, $t6 agira como um ponteiro para o nodo anterior
	lw $t1, ($t8)					##Ele servira para guardar o ponteiro da posicao a seguir do que sera apagado
	lw $t2, ($t9)
	
For_apaga:
	seq $t5, $t1, $t2
	beq $t5, 1, Apagar
	nop

	addi $t8, $t8, 32
	move $t6, $t8
	lw $t8, ($t8)
	beq $t8, $t9, Erro		#Funcao global, verificar la em baixo
	nop
	lw $t1, ($t8)
	j For_apaga
	nop

Apagar: 
	addi $t8, $t8, 32
	lw $t8, ($t8)
	sw $t8, ($t6)
	addi $t3, $t3, -1
	li $v0, 4
	la $a0, finalizado2
	syscall
	j menu
	nop

#----------------------------------
buscarPessoa:
	li $v0, 4
	la $a0, digitarnome
	syscall
	li $v0, 8
	move $a0, $t9
	li $a1, 32
	syscall
	lw $t8, Buffer
	lw $t1, ($t8)
	lw $t2, ($t9)

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
	lw $t1, ($t8)
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

#----------------------------------
listarPessoas:
	lw $t8, Buffer

For_lista:
	jal Imprimir
	nop

	addi $t8, $t8, 32
	lw $t8, ($t8)
	beq $t8, $t9, Fim_lista
	nop
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
	lw $a0, ($t8)
	syscall
	jr $ra
	nop

#----------------------------------
Sair:		#Salvar no arquivo simplesmente nao funciona
	li $v0, 13
	la $a0, agenda
	li $a1, 1
	li $a2, 0
	syscall
	move $t7, $v0
	li $v0, 15
	move $a0, $t7
	lw $a1, Buffer
	li $a2, 32
	lw $t8, Buffer
	
Salva:
	syscall
	addi $t8, $t8, 32
	lw $t8, ($t8)
	beq $t8, $t9, Encerra
	nop
	la $a1, ($t8)
	j Salva
	nop
	
Encerra:
	li $v0, 16
	move $a0, $t7
	syscall
	la $a0, fim
	li $v0, 4
	syscall
	li $v0, 10
	syscall