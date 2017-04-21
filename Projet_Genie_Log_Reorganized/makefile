CC = g++
CFLAG = -Wall -pedantic
STD = -std=c++11
SRC = src/
INC = include/
OBJ = object/
BIN = bin/

$(BIN)projet: $(OBJ)main.o $(OBJ)Game.o $(OBJ)Map.o $(OBJ)Character.o $(OBJ)Skill.o $(OBJ)Gauge.o
	$(CC) $(STD) -o $@ $^ $(CFLAG)

$(OBJ)main.o: main.cpp $(INC)Character.h $(INC)Skill.h $(INC)Gauge.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)
	
$(OBJ)Game.o: $(SRC)Game.cpp $(INC)Game.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)
	
$(OBJ)Map.o: $(SRC)Map.cpp $(INC)Map.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

$(OBJ)Character.o: $(SRC)Character.cpp $(INC)Character.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

$(OBJ)Skill.o: $(SRC)Skill.cpp $(INC)Skill.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

$(OBJ)Gauge.o: $(SRC)Gauge.cpp $(INC)Gauge.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

clean:
	rm -f $(OBJ)*.o

mrproper: clean
	rm -f $(BIN)projet
