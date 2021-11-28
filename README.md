# IRtools

More information on IR protocols, limitations of the IRremote, and solutions for those limitations (MSB vs. LSB, long IR signals, unsuported protocols etc.), vsit [documentation](https://arduino-irremote.github.io/Arduino-IRremote/) or [webarchive entry](https://web.archive.org/web/20211126224923/https://arduino-irremote.github.io/Arduino-IRremote/).

For MSB/LSB debug use the `reverseBitsSignificance` function available in code, or online tools such as [HEX to BIN](https://onlinebinarytools.com/convert-hexadecimal-to-binary), [bits reversal](https://onlinebinarytools.com/reverse-binary-numbers), and [BIN to HEX](https://onlinebinarytools.com/convert-binary-to-hexadecimal).

As for the NEC protocol, if you encounter a `0` signal (LSB, `FFFFFFFF` in MSB), thats a 'repeat' action, whitch means 'the same key as before, continuously pressed'.
