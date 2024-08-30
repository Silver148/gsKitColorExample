#include <stdio.h>
#include <kernel.h>
#include <debug.h>
#include <gsKit.h>
#include <dmakit.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    GSGLOBAL *gsGlobal;

    gsGlobal = gsKit_init_global();

    gsKit_init_screen(gsGlobal);

    gsKit_mode_switch(gsGlobal , GS_PERSISTENT);

    u64 Azul = GS_SETREG_RGBAQ(0x00, 0x00, 0xFF, 0x80, 0x00);

    u64 Rojo = GS_SETREG_RGBAQ(0xFF, 0x00, 0x00, 0x80, 0x00);

    u64 Verde = GS_SETREG_RGBAQ(0x00, 0xFF, 0x00, 0x80, 0x00);

    dmaKit_init(D_CTRL_RELE_OFF, D_CTRL_MFD_OFF, D_CTRL_STS_UNSPEC, D_CTRL_STD_OFF, D_CTRL_RCYC_8, 1 << DMA_CHANNEL_GIF);

	dmaKit_chan_init(DMA_CHANNEL_GIF);

    while(1){

        gsKit_clear(gsGlobal, Azul);

        gsKit_sync_flip(gsGlobal);

        gsKit_queue_exec(gsGlobal);

        sleep(1);

        gsKit_clear(gsGlobal, Rojo);

        gsKit_sync_flip(gsGlobal);

        gsKit_queue_exec(gsGlobal);

        sleep(1);

        gsKit_clear(gsGlobal, Verde);

        gsKit_sync_flip(gsGlobal);

        gsKit_queue_exec(gsGlobal);

        sleep(1);

    }

    return 0;
}
