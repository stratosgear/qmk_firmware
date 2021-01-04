#!/bin/sh

# In order to compile a 8.hex use:
# https://config.qmk.fm
# to load the latest layers.json file from the repo.
#
# Then put the keyboard in programming mode:
# * Remove power
# * Press: space+b while connecting cable
# * Keyboard will be inactive. Use laptop keyboard to type:
sudo dfu-programmer atmega32u4 erase
sudo dfu-programmer atmega32u4 flash --force dz60_stratosgear2.hex
sudo dfu-programmer atmega32u4 reset
