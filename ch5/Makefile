
SRC_DIR := src/
PROGRAM_DIR := bin/

ifndef $(V)
V := @
endif

all: $(PROGRAMS)
	make -C $(SRC_DIR) all
	make -C $(PROGRAM_DIR) all

clean:
	make -C $(SRC_DIR) clean
	make -C $(PROGRAM_DIR) clean

