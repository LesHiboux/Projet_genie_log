CC = g++
CFLAG = -Wall -pedantic
STD = -std=c++11
SRC = src/
INC = include/
OBJ = object/
BIN = bin/
PROJ = projet
MAIN = main
GAM = Game
INT = Interface
MAP = Map
CHAR = Character
SKI = Skill
GAU = Gauge

$(BIN)$(PROJ).exe: $(OBJ)$(MAIN).o $(OBJ)$(GAM).o $(OBJ)$(INT).o $(OBJ)$(MAP).o $(OBJ)$(CHAR).o $(OBJ)$(SKI).o $(OBJ)$(GAU).o
	$(CC) $(STD) -o $@ $^ $(CFLAG)

$(BIN)$(PROJ): $(OBJ)$(MAIN).o $(OBJ)$(GAM).o $(OBJ)$(INT).o $(OBJ)$(MAP).o $(OBJ)$(CHAR).o $(OBJ)$(SKI).o $(OBJ)$(GAU).o
	$(CC) $(STD) -o $@ $^ $(CFLAG)

$(OBJ)$(MAIN).o: $(MAIN).cpp $(INC)$(GAM).h $(INC)$(INT).h $(INC)$(MAP).h $(INC)$(CHAR).h $(INC)$(SKI).h $(INC)$(GAU).h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)
	
$(OBJ)$(GAM).o: $(SRC)$(GAM).cpp $(INC)$(GAM).h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)
	
$(OBJ)$(INT).o: $(SRC)$(INT).cpp $(INC)$(INT).h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)
	
$(OBJ)$(MAP).o: $(SRC)$(MAP).cpp $(INC)$(MAP).h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

$(OBJ)$(CHAR).o: $(SRC)$(CHAR).cpp $(INC)$(CHAR).h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

$(OBJ)$(SKI).o: $(SRC)$(SKI).cpp $(INC)$(SKI).h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

$(OBJ)$(GAU).o: $(SRC)$(GAU).cpp $(INC)$(GAU).h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

make: $(BIN)$(PROJ).exe $(BIN)$(PROJ)

clean:
	rm -f $(OBJ)*.o
	rm -f *~

mrproper: clean
	rm -f $(BIN)$(PROJ)*
