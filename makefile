EE_BIN = gsKitColorExample.elf
EE_OBJS	= main.o 
EE_LIBS = -lkernel -ldebug -L$(GSKITSRC)/lib -lgskit -ldmakit
EE_INCS = -I$(GSKITSRC)/ee/gs/include -I$(GSKITSRC)/ee/dma/include 

all: $(EE_BIN)
		$(EE_STRIP) --strip-all $(EE_BIN)

clean:
		rm -f $(EE_BIN) $(EE_OBJS)

include $(PS2SDK)/samples/Makefile.pref
include $(PS2SDK)/samples/Makefile.eeglobal