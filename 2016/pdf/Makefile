
all: fk_2016_beta_eftir.pdf fk_2016_beta_fyrir.pdf fk_2016_delta_eftir.pdf fk_2016_delta_fyrir.pdf

%.pdf: %.tex
	pdflatex $<
	pdflatex $<
	pdflatex $<

clean:
	rm -f *.aux *.log *.fdb_latexmk *.toc *.fls

.PHONY: all

