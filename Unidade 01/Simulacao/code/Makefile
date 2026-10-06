#
#	Makefile da Avaliação de Computação Gráfica
#

#
# A variável CC indica que compilador será utilizado
#
CC= gcc

#
# A variável CFLAGS indica que opções de compilação queremos
#
CFLAGS=	-Wall -g

#
# A variável SRCs indica os códigos fontes
#
SRCs= main.c model.c image.c

#
# A variavel EXEC indica o nome do executável final
#
EXEC= executavel

#
# A variável LIBS indica o caminho das bibliotecas e as bibliotecas usadas na ligação
#
LIBS= -lm

#
# A variável OBJS indica os arquivos objetos
#
OBJS= $(SRCs:.c=.o)


#
# Regra padrao do Makefile
#
all: $(EXEC) execute

#
# Regra de compilação e ligação do executável
# 
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	rm -f $(OBJS)

#
# Regra de compilação dos arquivos objetos
# 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#
# Regra que elimina arquivos intermediários
# 
clean:
	rm -f $(OBJS) $(EXEC) *~ *.ppm

#
# Regra que direciona o resultado para um arquivo PPM.
#
execute:
	./executavel > output.ppm


#
# Regra para teste da tarefa de rotacao do modelo
#
scale: CFLAGS += -DSCALE
scale: clean $(EXEC)
	./$(EXEC) > output.ppm
