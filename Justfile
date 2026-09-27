setup:
    qmk setup --home "$PWD/.qmk"

clean:
    qmk clean

compile:
    qmk userspace-compile -p -j 0

left:
    cp splitkb_halcyon_ferris_rev1_aveltras_left.uf2 /run/media/aveltras/RPI-RP2/

right:
    cp splitkb_halcyon_ferris_rev1_aveltras_right.uf2 /run/media/aveltras/RPI-RP2/
