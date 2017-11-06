all: KuttyTTS.exe

KuttyTTS.exe: my_flite_hts_imp.c us_int_accent_cart.c us_int_tone_cart.c us_nums_cart.c us_phrasing_cart.c us_pos_cart.c transliterator.c
	i586-mingw32msvc-cc -o $@ $^ -lm

clean:
	rm -fr *.o KuttyTTS.exe

.PHONY: clean
