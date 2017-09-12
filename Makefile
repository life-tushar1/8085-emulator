OBJS = start.o all.o cmdHeaders.o cmdUtility.o memoryInitial.o utility.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

p1 : $(OBJS)
    $(CC) $(LFLAGS) $(OBJS) -o p1

start.o : start.cpp all.h cmdHeaders.cpp cmdHeaders.h cmdUtility.cpp cmdUtility.h memoryInitial.cpp memoryInitial.h utility.cpp utility.h
    $(CC) $(CFLAGS) start.cpp

cmdHeaders.o : start.cpp all.h cmdHeaders.cpp cmdHeaders.h cmdUtility.cpp cmdUtility.h memoryInitial.cpp memoryInitial.h utility.cpp utility.h
    $(CC) $(CFLAGS) cmdHeaders.cpp

cmdUtility.o :start.cpp all.h cmdHeaders.cpp cmdHeaders.h cmdUtility.cpp cmdUtility.h memoryInitial.cpp memoryInitial.h utility.cpp utility.h
    $(CC) $(CFLAGS) cmdUtility.cpp

memoryInitial.o : start.cpp all.h cmdHeaders.cpp cmdHeaders.h cmdUtility.cpp cmdUtility.h memoryInitial.cpp memoryInitial.h utility.cpp utility.h
    $(CC) $(CFLAGS) memoryInitial.cpp

utility.o :start.cpp all.h cmdHeaders.cpp cmdHeaders.h cmdUtility.cpp cmdUtility.h memoryInitial.cpp memoryInitial.h utility.cpp utility.h
		    $(CC) $(CFLAGS) utility.cpp

clean:
    \rm *.o *~ p1
