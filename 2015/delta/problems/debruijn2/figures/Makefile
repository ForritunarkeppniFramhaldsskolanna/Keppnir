
IMGS=circle.png circle_2.png circle_3.png

%.png: %.tex
	pdflatex $<
	convert -density 150 $*.pdf -quality 90 -background white -flatten $@

all: $(IMGS)

clean:
	rm -f *.aux *.fdb_latexmk *.fls *.log *.pdf *.png

publish: $(IMGS)
	cp $(IMGS) ../assets

