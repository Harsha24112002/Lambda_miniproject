SFMLDIR=/$(HOME)/packages/SFML-2.5.1
INCLUDEDIR=$(SFMLDIR)/include
LIBDIR=$(SFMLDIR)/lib
CC =g++
LIBFLAGS=-lsfml-window -lsfml-system -lsfml-graphics -pthread
SRCS = State.cpp Mainmenustate.cpp Option.cpp  Game.cpp  Player.cpp Playerattributes.cpp\
 Bullet.cpp Enemy.cpp Collider.cpp Shield.cpp Powerup.cpp Invisible.cpp Gameover.cpp\
  Pause.cpp Animation.cpp Level.h Levelup.cpp Singleplayer.cpp Dualplayer.cpp \
  Restorehealth.cpp
OBJS =$(addsuffix .o,$(basename $(SRCS)))
EXE = Game
.PHONY = clean all
all = $(EXE)
$(EXE) : $(OBJS)
	$(CC) -o $@ -L $(LIBDIR) $(OBJS) $(LIBFLAGS)

$(OBJS) :%.o :%.cpp
	$(CC) -c -I $(INCLUDEDIR) $<
	
clean:
	rm $(OBJS) $(EXE)