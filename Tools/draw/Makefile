all:
	xelatex draw.tex
	pdfcrop draw.pdf
	convert -density 200 draw-crop.pdf draw.png
	@rm -f *.log
	@rm -f *.aux
	@rm -f *.dvi

clean:
	@rm -f *.log
	@rm -f *.aux
	@rm -f *.dvi
	@rm -f *.pdf
	@rm -f *.png
