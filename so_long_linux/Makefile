# Lista de archivos fuente
SOURCES = verify.c exit.c ber_to_split.c so_long.c gnl/get_next_line.c \
			colect_profundidad.c rendering.c start_mlx.c ft_handle_input.c
# Nombre del programa resultante
TARGET = so_long

# Compilador
CC = gcc

# Opciones de compilación
CFLAGS = -Wall -Wextra -Werror -g3 -O0

# Directorios de búsqueda de bibliotecas
LIBMLX = mlx/libmlx_Linux.a

LIBFT  = libft/libft.a
LIBFTDIR = libft/

MLXDIR = mlx

# Bibliotecas a enlazar
LIBS = -lXext -lX11 -lm

# Objetos generados
OBJECTS = $(SOURCES:.c=.o)

# Regla de compilación
all: $(TARGET)

$(LIBFT):
	make -C libft

$(LIBMLX): 
	make -C mlx

$(TARGET): $(OBJECTS) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LIBFT) $(LIBMLX) $(LIBS)

# Limpieza de archivos generados
clean:
	$(MAKE) clean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MLXDIR)
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MLXDIR)
	rm -f $(TARGET)
re:	fclean
	$(MAKE) all -C $(LIBFTDIR)
	$(MAKE) all -C $(MLXDIR)
	$(MAKE) all

