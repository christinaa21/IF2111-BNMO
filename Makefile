# ########################################################################
# ####################### Makefile Template ##############################
# ########################################################################

# # Compiler settings - Can be customized.
# CC = gcc
# CXXFLAGS = -std=c11 -Wall
# LDFLAGS = 

# # Makefile settings - Can be customized.
# APPNAME = BNMO
# EXT = .c
# SRCDIR = ./src
# OBJDIR = obj

# ############## Do not change anything from here downwards! #############
# SRC = $(wildcard $(SRCDIR)/*$(EXT))
# OBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)/%.o)
# DEP = $(OBJ:$(OBJDIR)/%.o=%.d)
# # UNIX-based OS variables & settings
# RM = rm
# DELOBJ = $(OBJ)
# # Windows OS variables & settings
# DEL = del
# EXE = .exe
# WDELOBJ = $(SRC:$(SRCDIR)/%$(EXT)=$(OBJDIR)\\%.o)

# ########################################################################
# ####################### Targets beginning here #########################
# ########################################################################

# all: $(APPNAME)

# # Builds the app
# $(APPNAME): $(OBJ)
# 	$(CC) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# # Creates the dependecy rules
# %.d: $(SRCDIR)/%$(EXT)
# 	@$(CPP) $(CFLAGS) $< -MM -MT $(@:%.d=$(OBJDIR)/%.o) >$@

# # Includes all .h files
# -include $(DEP)

# # Building rule for .o files and its .c/.cpp in combination with all .h
# $(OBJDIR)/%.o: $(SRCDIR)/%$(EXT)
# 	$(CC) $(CXXFLAGS) -o $@ -c $<

# ################### Cleaning rules for Unix-based OS ###################
# # Cleans complete project
# .PHONY: clean
# clean:
# 	$(RM) $(DELOBJ) $(DEP) $(APPNAME)

# # Cleans only all files with the extension .d
# .PHONY: cleandep
# cleandep:
# 	$(RM) $(DEP)

# #################### Cleaning rules for Windows OS #####################
# # Cleans complete project
# .PHONY: cleanw
# cleanw:
# 	$(DEL) $(WDELOBJ) $(DEP) $(APPNAME)$(EXE)

# # Cleans only all files with the extension .d
# .PHONY: cleandepw
# cleandepw:
# 	$(DEL) $(DEP)

compile:
	@gcc -o main ./main.c ./src/ADT/arrayOfGame/arrayOfGame.c ./src/ADT/mesinkata/mesinkata.c ./src/ADT/mesinkata/mesinkarakter.c ./src/ADT/prioQueue/prioQueue.c ./src/ADT/queue/queue.c ./src/game_util/game_util.c ./src/games/diner_dash/diner_dash.c ./src/games/game_tambahan/game_tambahan.c ./src/games/random_number_generator/random_number_generator.c ./src/main_util/main_util.c ./src/ADT/list/list.c

compile2:
	@gcc -o main .\main.c .\src\ADT\arrayOfGame\arrayOfGame.c .\src\ADT\mesinkata\mesinkata.c .\src\ADT\mesinkata\mesinkarakter.c .\src\ADT\prioQueue\prioQueue.c .\src\ADT\queue\queue.c .\src\game_util\game_util.c .\src\games\diner_dash\diner_dash.c .\src\games\game_tambahan\game_tambahan.c .\src\random_number_generator\random_number_generator.c .\src\main_util\main_util.c