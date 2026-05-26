setup:
    qmk setup --home "$PWD/.qmk"

clean:
    qmk clean

compile:
    qmk userspace-compile -e HLC_TFT_DISPLAY=1 -e TARGET=splitkb_halcyon_ferris_rev1_aveltras_left
    qmk userspace-compile -e HLC_CIRQUE_TRACKPAD=1 -e TARGET=splitkb_halcyon_ferris_rev1_aveltras_right
