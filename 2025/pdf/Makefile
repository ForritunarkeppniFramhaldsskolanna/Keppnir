
all: fk_2025_beta_eftir.pdf fk_2025_beta_fyrir.pdf fk_2025_delta_eftir.pdf fk_2025_delta_fyrir.pdf fk_2025_alfa_eftir.pdf fk_2025_alfa_fyrir.pdf

%.pdf: %.tex
	pdflatex $<
	pdflatex $<
	pdflatex $<

clean:
	rm -f *.aux *.log *.fdb_latexmk *.toc *.fls *.pstmp

.PHONY: all

