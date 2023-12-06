BIN_DIRECTORY:=bin
BUILD_DIRECTORY:= build
WORKING_FILE :=pair.cpp
EXECUTING_FILE :=pair.cpp
BIN_DIRECTORY:=bin
pid:=pidof bash


process:
	$(pid)

default:vim
vim:
	vi Makefile



open:
	vi $(WORKING_FILE)

createfile:
	vi $(filename)


filecheck:
	@if [ -f $(filename) ]; then \
		echo "$(filename) is found"; \
	else \
		echo "$(filename) is not found"; \
	fi



run:executable
	./$(BIN_DIRECTORY)/$(WORKING_FILE)
executable:
	g++ -c $(WORKING_FILE) -o $(BUILD_DIRECTORY)/$(WORKING_FILE)
	g++ $(EXECUTING_FILE) -o $(BIN_DIRECTORY)/$(WORKING_FILE)


.PHONY:clean
clean:
	rm $(BIN_DIRECTORY)/executable
	rm -rf $(BIN_DIRECTORY)
	rm -rd $(BUILD_DIRECTORY)



create:bin build

bin:
	mkdir bin
build:
	mkdir build

