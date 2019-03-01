all:
	xelatex draw.tex
	pdfcrop draw.pdf
	convert draw-crop.pdf draw.png
	@rm -f *.log
	@rm -f *.aux
	@rm -f *.dvi
	@rm -f *.pdf

clean:
	@rm -f *.log
	@rm -f *.aux
	@rm -f *.dvi
	@rm -f *.pdf
	@rm -f *.png
