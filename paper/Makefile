TARGET=paper.pdf

all: $(TARGET)

%.pdf: %.dvi
	dvipdf $<

%.dvi: %.tex
	latex $<
	latex $<

clean:
	rm -f $(TARGET)
	rm -f *.dvi
	rm -f *.aux
	rm -f *.log
	rm -f *.out
