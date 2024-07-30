# Variáveis
CC = gcc
CFLAGS = -Wall -g
TARGET = bigshot
DESTDIR = /usr/bin

# Regras
all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

install: $(TARGET)
	sudo cp $(TARGET) $(DESTDIR)

clean:
	rm -f $(TARGET)

.PHONY: all clean install
